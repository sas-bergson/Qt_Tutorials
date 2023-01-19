/**
 * @file calculator.hpp
 * @author Daniel Moune (daniel.moune@ictuniversity.edu.cm)
 * @brief  Definition of the Calculator component
 * @version 0.1
 * @date 2023-01-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QFrame>

namespace Ui {
    class Frame; // frame class to be used to create the User Interface Object 
}


class Calculator : public QFrame
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();
    void digitClicked();
    void equalClicked();
    void changeSignClicked();
    void clear();
    void clearAll();
    void backspaceClicked();
    void decimalClicked();
    void unaryOperatorClicked();
    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();

private:
    double sumInMemory;                     // contains the value stored in the calculator's memory (using MS, M+, or MC).
    
    double sumSoFar;                        // stores a temporary value when doing additions or substractions.
                                            // When the user clicks =, sumSoFar is recomputed and shown on the display.
                                            // Clear All resets sumSoFar to zero.
    
    double factorSoFar;                     // stores a temporary value when doing multiplications or divisions.
                                            // When the user clicks =, sumSoFar is recomputed and shown on the display.
                                            // Clear All resets factorSoFar to zero.

    QString pendingAdditiveOperator;        // stores the last additive operator clicked by the user.
    QString pendingMultiplicativeOperator;  // stores the last multiplicative operator clicked by the user.
    bool waitingForOperand;                 // when the calculator is expecting the user to start typing an operand.
    bool firstdigitSet;                     // true when the calculator hold the first significant digit
    bool decimalmodeSet;                    // true when the calculator expect next input to be added to decimal part
    Ui::Frame *ui;                          // pointer to the User Interface of the Calculator
    void setupSignalsandSlots();            // link buttons signals to the calculator's slots
    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);
};


#endif // CALCULATOR_H
