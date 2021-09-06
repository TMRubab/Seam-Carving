/********************************************************************************
** Form generated from reading UI file 'size_input.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZE_INPUT_H
#define UI_SIZE_INPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_size_input
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *size_input)
    {
        if (size_input->objectName().isEmpty())
            size_input->setObjectName(QString::fromUtf8("size_input"));
        size_input->resize(339, 209);
        widget = new QWidget(size_input);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 50, 197, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(size_input);

        QMetaObject::connectSlotsByName(size_input);
    } // setupUi

    void retranslateUi(QDialog *size_input)
    {
        size_input->setWindowTitle(QCoreApplication::translate("size_input", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("size_input", "Push me", nullptr));
    } // retranslateUi

};

namespace Ui {
    class size_input: public Ui_size_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZE_INPUT_H
