/**
 * @file calculator.cpp
 * @author Daniel Moune (daniel.moune@ictuniversity.edu.cm)
 * @brief  implementation of the Calculator component
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "calculator.hpp"

/*
    the ui_frame.h will be generated at compile time by the Qt Engine 
    from the frame.ui XML file generated in Qt Designer
*/
#include "ui_frame.h"

#include <cmath>
#include <iostream>

Calculator::Calculator(QWidget *parent) :
    QFrame(parent), ui(new Ui::Frame),
    sumInMemory(0.0), sumSoFar(0.0), factorSoFar(0.0),
    waitingForOperand(true), firstdigitSet(false), decimalmodeSet(false)
{
    ui->setupUi(this);
    setupSignalsandSlots();
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::clear()
{
    // if (waitingForOperand)
    //     return;

    ui->lcdNumber->display("0");
    waitingForOperand = true;
    if (firstdigitSet) firstdigitSet = false;
    if (decimalmodeSet) decimalmodeSet = false;
}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->lcdNumber->display("0");
    waitingForOperand = true;
    if (firstdigitSet) firstdigitSet = false;
    if (decimalmodeSet) decimalmodeSet = false;
}

void Calculator::backspaceClicked()
{
    // if (waitingForOperand)
    //     return;

    QString text = QString::number(ui->lcdNumber->value());
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
        if (firstdigitSet) firstdigitSet = false;
        if (!text.contains(".")) decimalmodeSet = false;
    }
    ui->lcdNumber->display(text);
}

void Calculator::unaryOperatorClicked()
{
    QPushButton* clicked_btn = qobject_cast<QPushButton *>(sender());
    QString clicked_operator = clicked_btn->text();
    double operand = ui->lcdNumber->value();
    double result = 0.0;

    if (clicked_operator == tr("Sqrt")) {
        if (operand < 0.0) {
            abortOperation();
            return;
        }
        result = std::sqrt(operand);
    } else if (clicked_operator == tr("x\302\262")) {
        result = std::pow(operand, 2.0);
    } else if (clicked_operator == tr("1/x")) {
        if (operand == 0.0) {
            abortOperation();
            return;
        }
        result = 1.0 / operand;
    }
    ui->lcdNumber->display(QString::number(result));
    waitingForOperand = true;
    if (firstdigitSet) firstdigitSet = false;
    if (decimalmodeSet) decimalmodeSet = false;
}

void Calculator::multiplicativeOperatorClicked()
{
    QPushButton* clicked_btn = qobject_cast<QPushButton *>(sender());
    
    if (!clicked_btn)
      return;

    QString clicked_operator = clicked_btn->text();
    double operand = ui->lcdNumber->value();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->lcdNumber->display(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }
    pendingMultiplicativeOperator = clicked_operator;
    waitingForOperand = true;
    if (firstdigitSet) firstdigitSet = false;
    if (decimalmodeSet) decimalmodeSet = false;
}

void Calculator::additiveOperatorClicked()
{
    QPushButton* clicked_btn = qobject_cast<QPushButton *>(sender()); // get reference to the button that emitted the signal
    
    if (!clicked_btn)
      return;

    QString clicked_operator = clicked_btn->text();
    double operand = ui->lcdNumber->value();
    
    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->lcdNumber->display(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }

    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        ui->lcdNumber->display(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }
    pendingAdditiveOperator = clicked_operator;
    waitingForOperand = true;
    if (firstdigitSet) firstdigitSet = false;
    if (decimalmodeSet) decimalmodeSet = false;
}

void Calculator::digitClicked()
{
    QPushButton* clicked_btn = qobject_cast<QPushButton *>(sender()); // get reference to the button that emitted the signal
    double btn_value = clicked_btn->text().toDouble();
    double displayed_value = ui->lcdNumber->value();
    if (displayed_value == 0)
    {
        if (btn_value == 0) return;
        else{
            QString text  = QString::number(displayed_value);
            if (decimalmodeSet && !text.contains(".")){
                text.append(".");
                text.append(QString::number(btn_value));
                ui->lcdNumber->display(text);
            }else ui->lcdNumber->display(QString::number(btn_value));
            if (!firstdigitSet) firstdigitSet = true;
        }
    }else{
        if (!firstdigitSet){
            ui->lcdNumber->display(QString::number(btn_value));
            firstdigitSet = true;
        }else{
            QString text  = QString::number(displayed_value);
            if (decimalmodeSet && !text.contains(".")) text.append(".");
            text.append(QString::number(btn_value));
            ui->lcdNumber->display(text);
            if (!firstdigitSet) firstdigitSet = true;
        }
    }
}

void Calculator::changeSignClicked()
{
    double value = (ui->lcdNumber->value());
    QString text = QString::number(value);

    if (value > 0.0) {
        text.prepend(tr("-"));
    } else if (value < 0.0) {
        text.remove(0, 1);
    }
    ui->lcdNumber->display(text);
}

void Calculator::decimalClicked()
{
    if (waitingForOperand && !firstdigitSet) ui->lcdNumber->display("0");
    QString text = QString::number(ui->lcdNumber->value());
    if (!text.contains('.')){
        decimalmodeSet = true;
    }
    waitingForOperand = false;
    if (!firstdigitSet) firstdigitSet = true;
}

void Calculator::equalClicked()
{
    double operand = ui->lcdNumber->value();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    ui->lcdNumber->display(QString::number(sumSoFar));
    double value = ui->lcdNumber->value();
    QString text = QString::number(value);
    if (text.contains(".") && !decimalmodeSet) decimalmodeSet = true;
    sumSoFar = 0.0;
    waitingForOperand = true;
}

void Calculator::clearMemory()
{
    sumInMemory = 0.0;
    if (firstdigitSet) firstdigitSet = false;
}

void Calculator::readMemory()
{
    ui->lcdNumber->display(QString::number(sumInMemory));
    waitingForOperand = true;
}

void Calculator::setMemory()
{
    equalClicked();
    sumInMemory = ui->lcdNumber->value();
}

void Calculator::addToMemory()
{
    equalClicked();
    sumInMemory += ui->lcdNumber->value();
}

void Calculator::abortOperation()
{
    clearAll();
    ui->lcdNumber->display(tr("####"));
    if (firstdigitSet) firstdigitSet = false;
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{
    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("x")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }
    return true;
}

void Calculator::setupSignalsandSlots()
{
    QObject::connect(ui->btn_0, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_1, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_2, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_3, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_4, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_5, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_6, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_7, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_8, &QPushButton::clicked, this, &Calculator::digitClicked);
    QObject::connect(ui->btn_9, &QPushButton::clicked, this, &Calculator::digitClicked);

    QObject::connect(ui->btn_bcksp, &QPushButton::clicked, this, &Calculator::backspaceClicked);
    QObject::connect(ui->btn_cl, &QPushButton::clicked, this, &Calculator::clear);
    QObject::connect(ui->btn_cl_all, &QPushButton::clicked, this, &Calculator::clearAll);

    QObject::connect(ui->btn_SQRT, &QPushButton::clicked, this, &Calculator::unaryOperatorClicked);
    QObject::connect(ui->btn_INVERT, &QPushButton::clicked, this, &Calculator::unaryOperatorClicked);
    QObject::connect(ui->btn_SQUARE, &QPushButton::clicked, this, &Calculator::unaryOperatorClicked);
    QObject::connect(ui->btn_SIGN, &QPushButton::clicked, this, &Calculator::changeSignClicked);

    QObject::connect(ui->btn_ADD, &QPushButton::clicked, this, &Calculator::additiveOperatorClicked);
    QObject::connect(ui->btn_SUB, &QPushButton::clicked, this, &Calculator::additiveOperatorClicked);

    QObject::connect(ui->btn_MULTIPLY, &QPushButton::clicked, this, &Calculator::multiplicativeOperatorClicked);
    QObject::connect(ui->btn_DIVIDE, &QPushButton::clicked, this, &Calculator::multiplicativeOperatorClicked);

    QObject::connect(ui->btn_EQUAL, &QPushButton::clicked, this, &Calculator::equalClicked);
    QObject::connect(ui->btn_DECIMAL, &QPushButton::clicked, this, &Calculator::decimalClicked);

    QObject::connect(ui->btn_M_CLEAR, &QPushButton::clicked, this, &Calculator::clearMemory);
    QObject::connect(ui->btn_M_ADD, &QPushButton::clicked, this, &Calculator::addToMemory);
    QObject::connect(ui->btn_M_SET, &QPushButton::clicked, this, &Calculator::setMemory);
    QObject::connect(ui->btn_M_READ, &QPushButton::clicked, this, &Calculator::setMemory);
}