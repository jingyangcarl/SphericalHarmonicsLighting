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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <Widget.h>

QT_BEGIN_NAMESPACE

class Ui_SphericalHarmonicsLightingClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridlayout;
    Widget *openGLWidget;
    QGridLayout *gridLayout;
    QLabel *label_ambientFactor;
    QLineEdit *lineEdit_ambientFactor;
    QLabel *label;
    QLineEdit *lineEdit_brightness;
    QSpacerItem *verticalSpacer;
    QLabel *label_contrast;
    QLabel *label_brightness;
    QLineEdit *lineEdit_contrast;
    QSlider *horizontalSlider_contrast;
    QSlider *horizontalSlider_ambientFactor;
    QSlider *horizontalSlider_brightness;
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

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_ambientFactor = new QLabel(centralWidget);
        label_ambientFactor->setObjectName(QString::fromUtf8("label_ambientFactor"));

        gridLayout->addWidget(label_ambientFactor, 1, 0, 1, 1);

        lineEdit_ambientFactor = new QLineEdit(centralWidget);
        lineEdit_ambientFactor->setObjectName(QString::fromUtf8("lineEdit_ambientFactor"));
        lineEdit_ambientFactor->setInputMask(QString::fromUtf8(""));
        lineEdit_ambientFactor->setText(QString::fromUtf8(""));
        lineEdit_ambientFactor->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ambientFactor, 1, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        lineEdit_brightness = new QLineEdit(centralWidget);
        lineEdit_brightness->setObjectName(QString::fromUtf8("lineEdit_brightness"));
        lineEdit_brightness->setReadOnly(true);

        gridLayout->addWidget(lineEdit_brightness, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 2);

        label_contrast = new QLabel(centralWidget);
        label_contrast->setObjectName(QString::fromUtf8("label_contrast"));

        gridLayout->addWidget(label_contrast, 3, 0, 1, 1);

        label_brightness = new QLabel(centralWidget);
        label_brightness->setObjectName(QString::fromUtf8("label_brightness"));

        gridLayout->addWidget(label_brightness, 5, 0, 1, 1);

        lineEdit_contrast = new QLineEdit(centralWidget);
        lineEdit_contrast->setObjectName(QString::fromUtf8("lineEdit_contrast"));
        lineEdit_contrast->setReadOnly(true);

        gridLayout->addWidget(lineEdit_contrast, 3, 1, 1, 1);

        horizontalSlider_contrast = new QSlider(centralWidget);
        horizontalSlider_contrast->setObjectName(QString::fromUtf8("horizontalSlider_contrast"));
        horizontalSlider_contrast->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_contrast, 4, 0, 1, 2);

        horizontalSlider_ambientFactor = new QSlider(centralWidget);
        horizontalSlider_ambientFactor->setObjectName(QString::fromUtf8("horizontalSlider_ambientFactor"));
        horizontalSlider_ambientFactor->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_ambientFactor, 2, 0, 1, 2);

        horizontalSlider_brightness = new QSlider(centralWidget);
        horizontalSlider_brightness->setObjectName(QString::fromUtf8("horizontalSlider_brightness"));
        horizontalSlider_brightness->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_brightness, 6, 0, 1, 2);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);

        gridlayout->addLayout(gridLayout, 0, 2, 1, 1);

        gridlayout->setColumnStretch(0, 4);
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
        label_ambientFactor->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Ambient Factor (0.35)", nullptr));
        label->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Control Panel", nullptr));
        label_contrast->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Contrast (2.0)", nullptr));
        label_brightness->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Brightness (0.13)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SphericalHarmonicsLightingClass: public Ui_SphericalHarmonicsLightingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERICALHARMONICSLIGHTING_H
