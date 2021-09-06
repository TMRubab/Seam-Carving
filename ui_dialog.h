/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "super_label.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *SliderWidth;
    super_label *label_width;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *SliderHeight;
    super_label *label_height;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(281, 187);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 140, 80, 25));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 256, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        SliderWidth = new QSlider(layoutWidget);
        SliderWidth->setObjectName(QString::fromUtf8("SliderWidth"));
        SliderWidth->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(SliderWidth);

        label_width = new super_label(layoutWidget);
        label_width->setObjectName(QString::fromUtf8("label_width"));
        label_width->setMinimumSize(QSize(70, 0));
        QFont font;
        font.setPointSize(14);
        label_width->setFont(font);

        horizontalLayout_2->addWidget(label_width);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        SliderHeight = new QSlider(layoutWidget);
        SliderHeight->setObjectName(QString::fromUtf8("SliderHeight"));
        SliderHeight->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(SliderHeight);

        label_height = new super_label(layoutWidget);
        label_height->setObjectName(QString::fromUtf8("label_height"));
        label_height->setMinimumSize(QSize(70, 0));
        label_height->setFont(font);

        horizontalLayout->addWidget(label_height);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Resize", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Width", nullptr));
        label_width->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Height", nullptr));
        label_height->setText(QCoreApplication::translate("Dialog", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
