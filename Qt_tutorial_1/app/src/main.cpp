#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "hello_msg_box.hpp"

int main(int argc, char* argv[]){
    QApplication my_qt_application(argc, argv);
    QWidget main_app_window;

    QLabel name_lbl("Name");
    QLineEdit name_ledit("");
    QPushButton say_hello_btn("Say Hello");

    HelloMsgBox hello_msg_box;

    QVBoxLayout app_main_layout;

    main_app_window.setLayout(&app_main_layout);

    QHBoxLayout row1_hlayout;
    row1_hlayout.addWidget(&name_lbl);
    row1_hlayout.addWidget(&name_ledit);
    QHBoxLayout row2_hlayout;
    row2_hlayout.addWidget(&say_hello_btn);

    app_main_layout.addLayout(&row1_hlayout);
    app_main_layout.addLayout(&row2_hlayout);

    QObject::connect(&say_hello_btn, &QPushButton::clicked, &hello_msg_box, &QMessageBox::exec);
    QObject::connect(&name_ledit, &QLineEdit::textChanged, &hello_msg_box, &HelloMsgBox::changeText);

    main_app_window.show();
    return my_qt_application.exec();
}
