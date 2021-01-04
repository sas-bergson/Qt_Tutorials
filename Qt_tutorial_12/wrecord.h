#ifndef WRECORD_H
#define WRECORD_H

#include <QObject>
#include <QDateTime>

class Wrecord : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString date READ getDate NOTIFY record_notification)
    Q_PROPERTY(QString balance READ getBalance NOTIFY record_notification)

public:
    explicit Wrecord(QString date, QString balance, QObject *parent = nullptr);
    virtual ~Wrecord();

    QString getDate() const;
    QString getBalance() const;

private:
    QString date;
    QString balance;

signals:
    void record_notification();

public slots:
};

#endif // WRECORD_H
