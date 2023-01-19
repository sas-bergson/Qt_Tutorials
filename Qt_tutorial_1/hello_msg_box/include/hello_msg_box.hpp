#ifndef HELLOMSGBOX_H
#define HELLOMSGBOX_H
#include <QMessageBox>

class HelloMsgBox : public QMessageBox{
    Q_OBJECT
public:
    HelloMsgBox();
public slots:
    void changeText(const QString&); // change your own text
};

#endif // HELLOMSGBOX_H
