/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *row1;
    QLCDNumber *lcdNumber;
    QHBoxLayout *row2;
    QPushButton *btn_bcksp;
    QPushButton *btn_cl;
    QPushButton *btn_cl_all;
    QHBoxLayout *row3;
    QGridLayout *btn_grid;
    QPushButton *btn_M_CLEAR;
    QPushButton *btn_9;
    QPushButton *btn_7;
    QPushButton *btn_DIVIDE;
    QPushButton *btn_8;
    QPushButton *btn_SQRT;
    QPushButton *btn_M_READ;
    QPushButton *btn_6;
    QPushButton *btn_4;
    QPushButton *btn_MULTIPLY;
    QPushButton *btn_5;
    QPushButton *btn_SQUARE;
    QPushButton *btn_M_SET;
    QPushButton *btn_3;
    QPushButton *btn_1;
    QPushButton *btn_SUB;
    QPushButton *btn_2;
    QPushButton *btn_INVERT;
    QPushButton *btn_M_ADD;
    QPushButton *btn_SIGN;
    QPushButton *btn_0;
    QPushButton *btn_ADD;
    QPushButton *btn_DECIMAL;
    QPushButton *btn_EQUAL;

    void setupUi(QFrame *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName(QString::fromUtf8("Frame"));
        Frame->resize(532, 300);
        Frame->setMinimumSize(QSize(532, 300));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("calc");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        Frame->setWindowIcon(icon);
        Frame->setFrameShape(QFrame::NoFrame);
        verticalLayout = new QVBoxLayout(Frame);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(8, 8, 8, 8);
        row1 = new QHBoxLayout();
        row1->setSpacing(5);
        row1->setObjectName(QString::fromUtf8("row1"));
        row1->setSizeConstraint(QLayout::SetDefaultConstraint);
        lcdNumber = new QLCDNumber(Frame);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);
        lcdNumber->setMinimumSize(QSize(514, 79));
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(11);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);

        row1->addWidget(lcdNumber);


        verticalLayout->addLayout(row1);

        row2 = new QHBoxLayout();
        row2->setSpacing(5);
        row2->setObjectName(QString::fromUtf8("row2"));
        btn_bcksp = new QPushButton(Frame);
        btn_bcksp->setObjectName(QString::fromUtf8("btn_bcksp"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_bcksp->sizePolicy().hasHeightForWidth());
        btn_bcksp->setSizePolicy(sizePolicy1);

        row2->addWidget(btn_bcksp);

        btn_cl = new QPushButton(Frame);
        btn_cl->setObjectName(QString::fromUtf8("btn_cl"));
        sizePolicy1.setHeightForWidth(btn_cl->sizePolicy().hasHeightForWidth());
        btn_cl->setSizePolicy(sizePolicy1);

        row2->addWidget(btn_cl);

        btn_cl_all = new QPushButton(Frame);
        btn_cl_all->setObjectName(QString::fromUtf8("btn_cl_all"));
        sizePolicy1.setHeightForWidth(btn_cl_all->sizePolicy().hasHeightForWidth());
        btn_cl_all->setSizePolicy(sizePolicy1);

        row2->addWidget(btn_cl_all);


        verticalLayout->addLayout(row2);

        row3 = new QHBoxLayout();
        row3->setSpacing(5);
        row3->setObjectName(QString::fromUtf8("row3"));
        btn_grid = new QGridLayout();
        btn_grid->setSpacing(5);
        btn_grid->setObjectName(QString::fromUtf8("btn_grid"));
        btn_M_CLEAR = new QPushButton(Frame);
        btn_M_CLEAR->setObjectName(QString::fromUtf8("btn_M_CLEAR"));
        sizePolicy1.setHeightForWidth(btn_M_CLEAR->sizePolicy().hasHeightForWidth());
        btn_M_CLEAR->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_M_CLEAR, 0, 0, 1, 1);

        btn_9 = new QPushButton(Frame);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        sizePolicy1.setHeightForWidth(btn_9->sizePolicy().hasHeightForWidth());
        btn_9->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_9, 0, 3, 1, 1);

        btn_7 = new QPushButton(Frame);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        sizePolicy1.setHeightForWidth(btn_7->sizePolicy().hasHeightForWidth());
        btn_7->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_7, 0, 1, 1, 1);

        btn_DIVIDE = new QPushButton(Frame);
        btn_DIVIDE->setObjectName(QString::fromUtf8("btn_DIVIDE"));
        sizePolicy1.setHeightForWidth(btn_DIVIDE->sizePolicy().hasHeightForWidth());
        btn_DIVIDE->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_DIVIDE, 0, 4, 1, 1);

        btn_8 = new QPushButton(Frame);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        sizePolicy1.setHeightForWidth(btn_8->sizePolicy().hasHeightForWidth());
        btn_8->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_8, 0, 2, 1, 1);

        btn_SQRT = new QPushButton(Frame);
        btn_SQRT->setObjectName(QString::fromUtf8("btn_SQRT"));
        sizePolicy1.setHeightForWidth(btn_SQRT->sizePolicy().hasHeightForWidth());
        btn_SQRT->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_SQRT, 0, 5, 1, 1);

        btn_M_READ = new QPushButton(Frame);
        btn_M_READ->setObjectName(QString::fromUtf8("btn_M_READ"));
        sizePolicy1.setHeightForWidth(btn_M_READ->sizePolicy().hasHeightForWidth());
        btn_M_READ->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_M_READ, 1, 0, 1, 1);

        btn_6 = new QPushButton(Frame);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        sizePolicy1.setHeightForWidth(btn_6->sizePolicy().hasHeightForWidth());
        btn_6->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_6, 1, 3, 1, 1);

        btn_4 = new QPushButton(Frame);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        sizePolicy1.setHeightForWidth(btn_4->sizePolicy().hasHeightForWidth());
        btn_4->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_4, 1, 1, 1, 1);

        btn_MULTIPLY = new QPushButton(Frame);
        btn_MULTIPLY->setObjectName(QString::fromUtf8("btn_MULTIPLY"));
        sizePolicy1.setHeightForWidth(btn_MULTIPLY->sizePolicy().hasHeightForWidth());
        btn_MULTIPLY->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_MULTIPLY, 1, 4, 1, 1);

        btn_5 = new QPushButton(Frame);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        sizePolicy1.setHeightForWidth(btn_5->sizePolicy().hasHeightForWidth());
        btn_5->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_5, 1, 2, 1, 1);

        btn_SQUARE = new QPushButton(Frame);
        btn_SQUARE->setObjectName(QString::fromUtf8("btn_SQUARE"));
        sizePolicy1.setHeightForWidth(btn_SQUARE->sizePolicy().hasHeightForWidth());
        btn_SQUARE->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_SQUARE, 1, 5, 1, 1);

        btn_M_SET = new QPushButton(Frame);
        btn_M_SET->setObjectName(QString::fromUtf8("btn_M_SET"));
        sizePolicy1.setHeightForWidth(btn_M_SET->sizePolicy().hasHeightForWidth());
        btn_M_SET->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_M_SET, 2, 0, 1, 1);

        btn_3 = new QPushButton(Frame);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        sizePolicy1.setHeightForWidth(btn_3->sizePolicy().hasHeightForWidth());
        btn_3->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_3, 2, 3, 1, 1);

        btn_1 = new QPushButton(Frame);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        sizePolicy1.setHeightForWidth(btn_1->sizePolicy().hasHeightForWidth());
        btn_1->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_1, 2, 1, 1, 1);

        btn_SUB = new QPushButton(Frame);
        btn_SUB->setObjectName(QString::fromUtf8("btn_SUB"));
        sizePolicy1.setHeightForWidth(btn_SUB->sizePolicy().hasHeightForWidth());
        btn_SUB->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_SUB, 2, 4, 1, 1);

        btn_2 = new QPushButton(Frame);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        sizePolicy1.setHeightForWidth(btn_2->sizePolicy().hasHeightForWidth());
        btn_2->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_2, 2, 2, 1, 1);

        btn_INVERT = new QPushButton(Frame);
        btn_INVERT->setObjectName(QString::fromUtf8("btn_INVERT"));
        sizePolicy1.setHeightForWidth(btn_INVERT->sizePolicy().hasHeightForWidth());
        btn_INVERT->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_INVERT, 2, 5, 1, 1);

        btn_M_ADD = new QPushButton(Frame);
        btn_M_ADD->setObjectName(QString::fromUtf8("btn_M_ADD"));
        sizePolicy1.setHeightForWidth(btn_M_ADD->sizePolicy().hasHeightForWidth());
        btn_M_ADD->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_M_ADD, 3, 0, 1, 1);

        btn_SIGN = new QPushButton(Frame);
        btn_SIGN->setObjectName(QString::fromUtf8("btn_SIGN"));
        sizePolicy1.setHeightForWidth(btn_SIGN->sizePolicy().hasHeightForWidth());
        btn_SIGN->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_SIGN, 3, 3, 1, 1);

        btn_0 = new QPushButton(Frame);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        sizePolicy1.setHeightForWidth(btn_0->sizePolicy().hasHeightForWidth());
        btn_0->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_0, 3, 1, 1, 1);

        btn_ADD = new QPushButton(Frame);
        btn_ADD->setObjectName(QString::fromUtf8("btn_ADD"));
        sizePolicy1.setHeightForWidth(btn_ADD->sizePolicy().hasHeightForWidth());
        btn_ADD->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_ADD, 3, 4, 1, 1);

        btn_DECIMAL = new QPushButton(Frame);
        btn_DECIMAL->setObjectName(QString::fromUtf8("btn_DECIMAL"));
        sizePolicy1.setHeightForWidth(btn_DECIMAL->sizePolicy().hasHeightForWidth());
        btn_DECIMAL->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_DECIMAL, 3, 2, 1, 1);

        btn_EQUAL = new QPushButton(Frame);
        btn_EQUAL->setObjectName(QString::fromUtf8("btn_EQUAL"));
        sizePolicy1.setHeightForWidth(btn_EQUAL->sizePolicy().hasHeightForWidth());
        btn_EQUAL->setSizePolicy(sizePolicy1);

        btn_grid->addWidget(btn_EQUAL, 3, 5, 1, 1);


        row3->addLayout(btn_grid);


        verticalLayout->addLayout(row3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 2);

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QFrame *Frame)
    {
        Frame->setWindowTitle(QApplication::translate("Frame", "Calculator(Qt5)", nullptr));
        btn_bcksp->setText(QApplication::translate("Frame", "Backspace", nullptr));
        btn_cl->setText(QApplication::translate("Frame", "Clear", nullptr));
        btn_cl_all->setText(QApplication::translate("Frame", "Clear All", nullptr));
        btn_M_CLEAR->setText(QApplication::translate("Frame", "MC", nullptr));
        btn_9->setText(QApplication::translate("Frame", "9", nullptr));
        btn_7->setText(QApplication::translate("Frame", "7", nullptr));
        btn_DIVIDE->setText(QApplication::translate("Frame", "\303\267", nullptr));
        btn_8->setText(QApplication::translate("Frame", "8", nullptr));
        btn_SQRT->setText(QApplication::translate("Frame", "Sqrt", nullptr));
        btn_M_READ->setText(QApplication::translate("Frame", "MR", nullptr));
        btn_6->setText(QApplication::translate("Frame", "6", nullptr));
        btn_4->setText(QApplication::translate("Frame", "4", nullptr));
        btn_MULTIPLY->setText(QApplication::translate("Frame", "x", nullptr));
        btn_5->setText(QApplication::translate("Frame", "5", nullptr));
        btn_SQUARE->setText(QApplication::translate("Frame", "x\302\262", nullptr));
        btn_M_SET->setText(QApplication::translate("Frame", "MS", nullptr));
        btn_3->setText(QApplication::translate("Frame", "3", nullptr));
        btn_1->setText(QApplication::translate("Frame", "1", nullptr));
        btn_SUB->setText(QApplication::translate("Frame", "-", nullptr));
        btn_2->setText(QApplication::translate("Frame", "2", nullptr));
        btn_INVERT->setText(QApplication::translate("Frame", "1/x", nullptr));
        btn_M_ADD->setText(QApplication::translate("Frame", "M+", nullptr));
        btn_SIGN->setText(QApplication::translate("Frame", "\302\261", nullptr));
        btn_0->setText(QApplication::translate("Frame", "0", nullptr));
        btn_ADD->setText(QApplication::translate("Frame", "+", nullptr));
        btn_DECIMAL->setText(QApplication::translate("Frame", ".", nullptr));
        btn_EQUAL->setText(QApplication::translate("Frame", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
