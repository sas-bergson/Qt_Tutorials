#include <QApplication>
#include <QLayout>
#include "calculator.hpp"

int main(int argc, char* argv[]){

    QApplication my_qt_application(argc, argv); // initialize the main thread
    
    QWidget main_app_widget; // initialize the main app widget

    Calculator calculator_widget; // initialize the calculator's widget

    QLayout* calculator_layout = calculator_widget.layout(); // get the calculator's layout

    main_app_widget.setLayout(calculator_layout); // set the app layout to be the calculator's layout

    main_app_widget.setWindowTitle("Daniel Moune - Calculator App Demo - built with Qt5");

    main_app_widget.show(); // show the app

    return my_qt_application.exec(); // run the main thread
}
