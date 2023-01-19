#include "hello_msg_box.hpp"

HelloMsgBox::HelloMsgBox():QMessageBox("Hello", "Hello World !!!!",
                                                     QMessageBox::Information,
                                                     QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton)
{

}

void HelloMsgBox::changeText(const QString& str){
    QString msg = str;
    this->setText(msg.prepend("Hello "));
}
