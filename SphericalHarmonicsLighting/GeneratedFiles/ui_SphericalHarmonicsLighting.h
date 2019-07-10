/********************************************************************************
** Form generated from reading UI file 'SphericalHarmonicsLighting.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPHERICALHARMONICSLIGHTING_H
#define UI_SPHERICALHARMONICSLIGHTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "Widget.h"

QT_BEGIN_NAMESPACE

class Ui_SphericalHarmonicsLightingClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridlayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SphericalHarmonicsLightingClass)
    {
        if (SphericalHarmonicsLightingClass->objectName().isEmpty())
            SphericalHarmonicsLightingClass->setObjectName(QString::fromUtf8("SphericalHarmonicsLightingClass"));
        SphericalHarmonicsLightingClass->resize(1171, 739);
        centralWidget = new QWidget(SphericalHarmonicsLightingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridlayout = new QGridLayout(centralWidget);
        gridlayout->setSpacing(6);
        gridlayout->setContentsMargins(11, 11, 11, 11);
        gridlayout->setObjectName(QString::fromUtf8("gridlayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridlayout->addWidget(openGLWidget, 0, 0, 1, 1);

        SphericalHarmonicsLightingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SphericalHarmonicsLightingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1171, 21));
        SphericalHarmonicsLightingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SphericalHarmonicsLightingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SphericalHarmonicsLightingClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SphericalHarmonicsLightingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SphericalHarmonicsLightingClass->setStatusBar(statusBar);

        retranslateUi(SphericalHarmonicsLightingClass);

        QMetaObject::connectSlotsByName(SphericalHarmonicsLightingClass);
    } // setupUi

    void retranslateUi(QMainWindow *SphericalHarmonicsLightingClass)
    {
        SphericalHarmonicsLightingClass->setWindowTitle(QCoreApplication::translate("SphericalHarmonicsLightingClass", "SphericalHarmonicsLighting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SphericalHarmonicsLightingClass: public Ui_SphericalHarmonicsLightingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERICALHARMONICSLIGHTING_H
