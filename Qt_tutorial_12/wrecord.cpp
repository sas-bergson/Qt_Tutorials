#include "wrecord.h"

// Constructor and Destructor
Wrecord::Wrecord(QString date, QString balance, QObject *parent) : QObject(parent), date(date), balance(balance)
{
}
Wrecord::~Wrecord(){
    // default destructor will prevail here !!!!
}

// for data access
QString Wrecord::getDate() const{
    return this->date;
}
QString Wrecord::getBalance() const{
    return this->balance;
}
