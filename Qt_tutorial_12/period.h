#ifndef PERIOD_H
#define PERIOD_H
#define DB_NAME QString("eWallet.sqlite")

#include <QObject>
#include <QString>
#include <QtSql/QtSql>
#include <QSqlDatabase>

/**
 *@brief The Period class
 *
 * Period is a class designed to open the SQLite database,
 * run 03 predefined SQL queries and return the recordsets to the GUI.
 * It inherits from QObject in order to benefit Qt signals and slots mecanisms
 *
 * Interaction between C++ Period Class and GUI in main.qml is done using 03 assets :
 *    1 / properties defined using the Q_PROPERTY macro in C++
 *    2/ calls to methods declared using the Q_INVOKABLE prefix in C++
 *    3/ signals connected to slots in QML
 *
 * 04 additional properties will be added :
 *     1/ Connection_error : handler for database connection errors
 *     2/ periods_list : model bound to the period table in the database
 *     3/ wallet_records : model bound to the record table in the database
 *     4/ balance : current amount of cash in the wallet
 *     the last 03 properties will be read-only and bound to a READ accessor.
 */

class Period : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool dbError MEMBER db_error NOTIFY dbErrorChanged)
    Q_PROPERTY(QStringList periodsList READ getPeriods NOTIFY periodsListChanged)
    Q_PROPERTY(QVariant walletRecords READ getWalletRecords NOTIFY walletRecordsChanged)
    Q_PROPERTY(QString balance READ getBalance NOTIFY balanceChanged)

public:

    // model constructor and destructor
    explicit Period(QObject *parent = nullptr);
    virtual ~Period();

    // model public methods callable from QML
    Q_INVOKABLE bool selectPeriods(int skip=0, int max=0);
    Q_INVOKABLE bool selectWalletRecordsFor(QString period);
    Q_INVOKABLE bool selectBalanceFor(QString period);
    Q_INVOKABLE bool execSQL(QString query);

    // public members that might be attached to Q_Properties


    // public accessors that might be attached to Q_Properties
    QStringList getPeriods();
    QVariant getWalletRecords();
    QString getBalance();

    // model setters might be connected to some slots
    void setCurrentPeriod(int period_id);

private:

    QSqlDatabase db;
    bool db_error;
    int current_period_id;
    QStringList *periods;
    QList<QObject*> *wallet_records;
    QString *period_balance;

     // model methods to run SQL and DB administration
     bool execSQL(QString query, QStringList *data);
     bool execSQL(QString query, QVector<QStringList> *data);
     bool execSQL(QString query, QString *data);
     bool dbCopy(QFile &source_file, QFile &destination_file);
     bool dbReplace(QFile &source_file, QFile &destination_file);
     bool dbExists(QString BD);

signals:

     void dbErrorChanged();
     void periodsListChanged();
     void periodsListError();
     void walletRecordsChanged();
     void walletRecordsError();
     void balanceChanged();

public slots:
};

#endif // PERIOD_H
