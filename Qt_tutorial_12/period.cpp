#include "period.h"
#include "wrecord.h"

// Constructor and Destructor
Period::Period(QObject *parent) : QObject(parent), db_error(false),current_period_id(0),periods(NULL),wallet_records(NULL),period_balance(NULL)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QFile source_file(QString("assets:/db/%1").arg(DB_NAME));
    QFile destination_file(QString("./%1").arg(DB_NAME));

    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... checking database access ...");
    if(!dbExists(QString("./") + DB_NAME)){
        qInfo() << Q_FUNC_INFO <<QString::fromUtf8(" ... could not find database at './%1 '").arg(DB_NAME);
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... creating database if necessary ...");
        if (!dbCopy(source_file, destination_file)){
            db_error = true;
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : impossible to create Database at %1 !")
                        .arg(QCoreApplication::applicationDirPath() + DB_NAME);
        }
    }

    if(dbExists(QString("./") + DB_NAME)){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... database access successful ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... attempting to open the database ...");
        db.setDatabaseName(QString("./") + DB_NAME);
        if(!db.open()){
            db_error = true;
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : impossible to open Database at %1 !").arg(QCoreApplication::applicationDirPath() + DB_NAME);
        }else qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... database opening successful ...");
        QSqlQuery query;
        if(!query.exec("pragma foreign_keys = on;")){
            db_error = true;
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Erreur : %1").arg(query.lastError().text());
        }
    }
    emit dbErrorChanged();
}
Period::~Period(){
    // flush all lists
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... flushing all lists ...");
    periods->clear();
    qDeleteAll(*wallet_records);
    wallet_records->clear();
    // delete all pointers
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... deleting all pointers ...");
    delete periods;
    delete wallet_records;
    delete period_balance;
}

// for data access from QML
void Period::setCurrentPeriod(int period_id){
    qInfo() << Q_FUNC_INFO << QString::fromUtf8("Setting current period to : %1").arg(period_id);
    this->current_period_id = period_id;
}
bool Period::selectPeriods(int skip, int max){
    if(db_error) return false;
    if(periods==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... periods list not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing a new list for periods ...");
        periods = new QStringList();
    }else{
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... found an old list of periods ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... flushing the old list ...");
        periods->clear();
     }
    // select all periods skip some records and keep up to max
    QString query;
    query = QString::fromUtf8("SELECT CAST(period.year as TEXT) || '-' ||"
            "CAST(period.month as TEXT) || '-' ||"
            "CAST(period.day as TEXT) as date, "
            "FROM period "
            "ORDER BY period.year, period.month, period.day DESC"
            "LIMIT %1,%2").arg(skip).arg(max);
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... getting data from the database ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... running sql =  %1").arg(query);
    if(!execSQL(query, periods)){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... No records found due to sql processing error... ");
        emit periodsListError();
        return false;
    }
    if(periods->count() == 0){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... no period records found ... ");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... notifying period records not found error ... ");
        emit periodsListError();
        return false;
    }
    periods->prepend(QString::fromUtf8("All records"));
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... sql execution successful ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... %1 records extracted ... ").arg(periods->count());
    emit periodsListChanged();
    return true;
}
bool Period::selectWalletRecordsFor(QString period){
    if(db_error) return false;
    if(wallet_records==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... wallet records list not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing a new list for wallet records...");
        wallet_records = new QList<QObject*>();
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... done");
    }else{
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... wallet records from previous selection detected");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... flushing list of records from previous selection");
        qDeleteAll(*wallet_records);
        wallet_records->clear();
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... done");
    }

    QVector<QStringList> p_wallet_records;

    // select all wallet records for the current period
    QString query;
    if (QString::compare(period,QString::fromUtf8("All records"),Qt::CaseInsensitive)==0){
        query = QString::fromUtf8("SELECT CAST(period.year as TEXT) || '-' ||"
                "CAST(period.month as TEXT) || '-' ||"
                "CAST(period.day as TEXT) as logdate, "
                "(record.type * record.amount) as amount "
                "FROM record "
                "INNER JOIN period "
                "ON period.id = record.period_id "
                "ORDER BY period.year, period.month, period.day DESC");
    }else{
        query = QString::fromUtf8("SELECT CAST(period.year as TEXT) || '-' ||"
                "CAST(period.month as TEXT) || '-' ||"
                "CAST(period.day as TEXT) as logdate, "
                "(record.type * record.amount) as amount "
                "FROM record "
                "INNER JOIN period "
                "ON period.id = record.period_id "
                "WHERE logdate LIKE '%1'").arg(period);
    }
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... getting data from the database ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... running sql =  %1").arg(query);
    if(!execSQL(query, &p_wallet_records)){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... No records found due to sql processing error... ");
        emit walletRecordsError();
        return false;
    }
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... sql execution successful ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... checking records ... ");
    if(p_wallet_records.count() == 0){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... no wallet records found ... ");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... notifying wallet records not found error ... ");
        emit walletRecordsError();
        return false;
    }
    for(int i=0;i<p_wallet_records.count();i++){
        Wrecord *w_record = new Wrecord(p_wallet_records.at(i).at(0), p_wallet_records.at(i).at(1), this);
        wallet_records->append(w_record);
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... record[%1] = date -> %2  ;   amount ->  %3 ")
                                                    .arg(i).arg(w_record->getDate()).arg(w_record->getBalance());
    }
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" %1 records extracted ... ").arg(p_wallet_records.count());
    emit walletRecordsChanged();
    return true;
}
bool Period::selectBalanceFor(QString period){
    if(db_error) return false;
    if(period_balance==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... period_balance was not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing period_balance to 0");
        period_balance = new QString("0");
    }
    // select all wallet records for the period and sum their balance
    QString query;
    if (QString::compare(period,QString::fromUtf8("All records"),Qt::CaseInsensitive)==0){
        query = QString::fromUtf8("SELECT amount FROM("
                "SELECT CAST(period.year as TEXT) || '-' ||"
                "CAST(period.month as TEXT) || '-' ||"
                "CAST(period.day as TEXT) as logdate, "
                "SUM(record.type * record.amount) as amount "
                "FROM record "
                "INNER JOIN period "
                "ON period.id = record.period_id)");
    }else{
        query = QString::fromUtf8("SELECT amount FROM("
                "SELECT CAST(period.year as TEXT) ||  '-' ||"
                "CAST(period.month as TEXT) || '-' ||"
                "CAST(period.day as TEXT) as logdate, "
                "SUM(record.type * record.amount) as amount "
                "FROM record "
                "INNER JOIN period "
                "ON period.id = record.period_id "
                "WHERE logdate LIKE '%1')").arg(period);
    }
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... getting data from the database ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... running sql = %1").arg(query);
    if (!execSQL(query, period_balance)){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... No records found due to sql processing error... ");
        return false;
    }
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... sql execution successful ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... checking records ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... found period balance =  %1").arg(*period_balance);
    emit balanceChanged();
    return true;
}
bool Period::execSQL(QString query){
    QSqlQuery r;
    if(db.isOpen()) return r.exec(query);
    else {
        qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : %1 for query %2").arg(r.lastError().text()).arg(query);
    }
    return false;
}

// for access to the class Q_Properties
QStringList Period::getPeriods(){
    if(db_error) return QStringList();
    if(periods==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... periods list not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing a new list for periods ...");
        periods = new QStringList();
    }else{
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... found an old list of periods ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... flushing the old list ...");
        periods->clear();
    }
    // select all periods skip some records and keep up to max
    QString query;
    query = QString::fromUtf8("SELECT CAST(period.year as TEXT) || '-' ||"
            "CAST(period.month as TEXT) || '-' ||"
            "CAST(period.day as TEXT) as date "
            "FROM period "
            "ORDER BY period.year, period.month, period.day DESC");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... getting data from the database ... ");
    qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... running sql =  %1").arg(query);
    if(execSQL(query, periods)){
        if(periods->count() == 0) qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... No records found due to sql processing error... ");
        else{
            periods->prepend(QString::fromUtf8("All records"));
            qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... sql execution successful ... ");
            qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... %1 records extracted ... ").arg(periods->count());
        }
    }
    return *periods;
}
QVariant Period::getWalletRecords(){
    if(db_error) return QVariant();
    if(wallet_records==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... wallets records list not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing a new list for wallet records ...");
        wallet_records = new QList<QObject*>();
    }else{
        if(wallet_records->count() == 0)qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... no records found ... ");
        else{
            qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... %1 records found ... ").arg(wallet_records->count());
        }
    }
    return QVariant::fromValue(*wallet_records);
}
QString Period::getBalance(){
    if(db_error) return QString();
    if(period_balance==NULL){
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... balance value not initialized ...");
        qInfo() << Q_FUNC_INFO << QString::fromUtf8(" ... initializing balance to 0 ...");
        period_balance = new QString("0");
    }
    return *period_balance;
}

// for database CRUD
bool Period::execSQL(QString query, QStringList *data){
    QSqlQuery r;
    bool r_value;
    if(db.isOpen()){
        r_value = r.exec(query);
        if(r_value){
            while ( r.next() ){
                *data << r.value(0).toString();
            }
            return true;
        }else{
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : %1 for query %2").arg(r.lastError().text()).arg(query);
        }
    }
    return false;
}
bool Period::execSQL(QString query, QVector<QStringList> *data){
    QSqlQuery r;
    bool r_value;
    QStringList records;
    if(db.isOpen()){
       r_value = r.exec(query);
       if(r_value){
            while ( r.next() ){
                // get each QString and append them in the QStringList
                for(int i=0;i<r.record().count();i++)
                    records << r.value(i).toString();
                // push the QStringList in the QVector
                data->push_back(records);
                // dump QStringList contents and restart
                records.clear();
            }
            return true;
       }else{
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : %1 for query %2").arg(r.lastError().text()).arg(query);
       }
    }
    return false;
}
bool Period::execSQL(QString query, QString *data){
    QSqlQuery r;
    bool r_value;

    if(db.isOpen()){
        r_value = r.exec(query);
        if(r_value){
            r.first();
            if(!r.isValid() || r.isNull(0)) return false;
            *data = r.value(0).toString();
            return true;
        }else{
            qDebug() << Q_FUNC_INFO << QString::fromUtf8("Error : %1 for query %2").arg(r.lastError().text()).arg(query);
        }
    }
    return false;
}

// for database Administration
bool Period::dbCopy(QFile &source_file, QFile &destination_file){
    if (source_file.exists()){
        return source_file.copy(destination_file.fileName());
    }
    return false;
}
bool Period::dbReplace(QFile &source_file, QFile &destination_file){
    if (source_file.exists()){
        if (destination_file.exists()){
            if(!destination_file.remove()) return false;
        }
    }
    return dbCopy(source_file, destination_file);
}
bool Period::dbExists(QString Db){
    QFile file(Db);
    if (file.exists()) return true;
    return false;
}
