/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "drawingview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionProject;
    QAction *actionAuthors;
    QAction *actionImport_image;
    QAction *actionClear_image;
    QAction *actionResize;
    QAction *actionObject_removal;
    QAction *actionExport_image;
    QAction *actionRemove;
    QAction *actionCancel;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    drawingview *graphicsView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(410, 366);
        actionProject = new QAction(MainWindow);
        actionProject->setObjectName(QString::fromUtf8("actionProject"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rsc/img/about_project.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProject->setIcon(icon);
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QString::fromUtf8("actionAuthors"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rsc/img/about_creators.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAuthors->setIcon(icon1);
        actionImport_image = new QAction(MainWindow);
        actionImport_image->setObjectName(QString::fromUtf8("actionImport_image"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rsc/img/import_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_image->setIcon(icon2);
        actionClear_image = new QAction(MainWindow);
        actionClear_image->setObjectName(QString::fromUtf8("actionClear_image"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rsc/img/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_image->setIcon(icon3);
        actionResize = new QAction(MainWindow);
        actionResize->setObjectName(QString::fromUtf8("actionResize"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rsc/img/resize.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResize->setIcon(icon4);
        actionObject_removal = new QAction(MainWindow);
        actionObject_removal->setObjectName(QString::fromUtf8("actionObject_removal"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rsc/img/highlighter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionObject_removal->setIcon(icon5);
        actionExport_image = new QAction(MainWindow);
        actionExport_image->setObjectName(QString::fromUtf8("actionExport_image"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rsc/img/export_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_image->setIcon(icon6);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rsc/img/object_removal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon7);
        actionCancel = new QAction(MainWindow);
        actionCancel->setObjectName(QString::fromUtf8("actionCancel"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rsc/img/cancel_drawing.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCancel->setIcon(icon8);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new drawingview(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 410, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionImport_image);
        menuFile->addAction(actionClear_image);
        menuFile->addAction(actionExport_image);
        menuTools->addAction(actionResize);
        menuTools->addAction(actionObject_removal);
        menuTools->addAction(actionRemove);
        menuTools->addAction(actionCancel);
        menuAbout->addAction(actionProject);
        menuAbout->addAction(actionAuthors);
        toolBar->addAction(actionImport_image);
        toolBar->addAction(actionClear_image);
        toolBar->addAction(actionExport_image);
        toolBar->addSeparator();
        toolBar->addAction(actionResize);
        toolBar->addAction(actionObject_removal);
        toolBar->addAction(actionRemove);
        toolBar->addAction(actionCancel);
        toolBar->addSeparator();
        toolBar->addAction(actionProject);
        toolBar->addAction(actionAuthors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionProject->setText(QCoreApplication::translate("MainWindow", "Project", nullptr));
        actionAuthors->setText(QCoreApplication::translate("MainWindow", "Authors", nullptr));
        actionImport_image->setText(QCoreApplication::translate("MainWindow", "Import image", nullptr));
        actionClear_image->setText(QCoreApplication::translate("MainWindow", "Clear image", nullptr));
        actionResize->setText(QCoreApplication::translate("MainWindow", "Resize", nullptr));
        actionObject_removal->setText(QCoreApplication::translate("MainWindow", "Marker", nullptr));
        actionExport_image->setText(QCoreApplication::translate("MainWindow", "Export image", nullptr));
        actionRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actionCancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
