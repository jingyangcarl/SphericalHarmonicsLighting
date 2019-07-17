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
#include <QtWidgets/QPushButton>
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
    QLabel *label;
    QLineEdit *lineEdit_faceCount;
    QLineEdit *lineEdit_meshPath;
    QLabel *label_contrast;
    QSpacerItem *verticalSpacer;
    QLabel *label_normalCount;
    QLineEdit *lineEdit_contrast;
    QLabel *label_brightness;
    QSlider *horizontalSlider_contrast;
    QSlider *horizontalSlider_brightness;
    QLabel *label_ambientFactor;
    QPushButton *pushButton_loadMesh;
    QLabel *label_faceCount;
    QSlider *horizontalSlider_ambientFactor;
    QLineEdit *lineEdit_texCoordCount;
    QLineEdit *lineEdit_ambientFactor;
    QLineEdit *lineEdit_meshScale;
    QLineEdit *lineEdit_brightness;
    QLabel *label_meshScale;
    QLineEdit *lineEdit_normalCount;
    QLabel *label_texCoordCount;
    QLabel *label_verCoordCount;
    QLineEdit *lineEdit_verCoordCount;
    QLabel *label_2;
    QSlider *horizontalSlider_meshScale;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SphericalHarmonicsLightingClass)
    {
        if (SphericalHarmonicsLightingClass->objectName().isEmpty())
            SphericalHarmonicsLightingClass->setObjectName(QString::fromUtf8("SphericalHarmonicsLightingClass"));
        SphericalHarmonicsLightingClass->resize(1529, 1024);
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
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 9, 0, 1, 2);

        lineEdit_faceCount = new QLineEdit(centralWidget);
        lineEdit_faceCount->setObjectName(QString::fromUtf8("lineEdit_faceCount"));
        lineEdit_faceCount->setReadOnly(true);

        gridLayout->addWidget(lineEdit_faceCount, 6, 1, 1, 1);

        lineEdit_meshPath = new QLineEdit(centralWidget);
        lineEdit_meshPath->setObjectName(QString::fromUtf8("lineEdit_meshPath"));
        lineEdit_meshPath->setReadOnly(true);

        gridLayout->addWidget(lineEdit_meshPath, 2, 0, 1, 2);

        label_contrast = new QLabel(centralWidget);
        label_contrast->setObjectName(QString::fromUtf8("label_contrast"));

        gridLayout->addWidget(label_contrast, 14, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 18, 0, 1, 2);

        label_normalCount = new QLabel(centralWidget);
        label_normalCount->setObjectName(QString::fromUtf8("label_normalCount"));

        gridLayout->addWidget(label_normalCount, 5, 0, 1, 1);

        lineEdit_contrast = new QLineEdit(centralWidget);
        lineEdit_contrast->setObjectName(QString::fromUtf8("lineEdit_contrast"));
        lineEdit_contrast->setReadOnly(true);

        gridLayout->addWidget(lineEdit_contrast, 14, 1, 1, 1);

        label_brightness = new QLabel(centralWidget);
        label_brightness->setObjectName(QString::fromUtf8("label_brightness"));

        gridLayout->addWidget(label_brightness, 16, 0, 1, 1);

        horizontalSlider_contrast = new QSlider(centralWidget);
        horizontalSlider_contrast->setObjectName(QString::fromUtf8("horizontalSlider_contrast"));
        horizontalSlider_contrast->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_contrast, 15, 0, 1, 2);

        horizontalSlider_brightness = new QSlider(centralWidget);
        horizontalSlider_brightness->setObjectName(QString::fromUtf8("horizontalSlider_brightness"));
        horizontalSlider_brightness->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_brightness, 17, 0, 1, 2);

        label_ambientFactor = new QLabel(centralWidget);
        label_ambientFactor->setObjectName(QString::fromUtf8("label_ambientFactor"));

        gridLayout->addWidget(label_ambientFactor, 12, 0, 1, 1);

        pushButton_loadMesh = new QPushButton(centralWidget);
        pushButton_loadMesh->setObjectName(QString::fromUtf8("pushButton_loadMesh"));

        gridLayout->addWidget(pushButton_loadMesh, 1, 0, 1, 2);

        label_faceCount = new QLabel(centralWidget);
        label_faceCount->setObjectName(QString::fromUtf8("label_faceCount"));

        gridLayout->addWidget(label_faceCount, 6, 0, 1, 1);

        horizontalSlider_ambientFactor = new QSlider(centralWidget);
        horizontalSlider_ambientFactor->setObjectName(QString::fromUtf8("horizontalSlider_ambientFactor"));
        horizontalSlider_ambientFactor->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_ambientFactor, 13, 0, 1, 2);

        lineEdit_texCoordCount = new QLineEdit(centralWidget);
        lineEdit_texCoordCount->setObjectName(QString::fromUtf8("lineEdit_texCoordCount"));
        lineEdit_texCoordCount->setReadOnly(true);

        gridLayout->addWidget(lineEdit_texCoordCount, 4, 1, 1, 1);

        lineEdit_ambientFactor = new QLineEdit(centralWidget);
        lineEdit_ambientFactor->setObjectName(QString::fromUtf8("lineEdit_ambientFactor"));
        lineEdit_ambientFactor->setInputMask(QString::fromUtf8(""));
        lineEdit_ambientFactor->setText(QString::fromUtf8(""));
        lineEdit_ambientFactor->setReadOnly(true);

        gridLayout->addWidget(lineEdit_ambientFactor, 12, 1, 1, 1);

        lineEdit_meshScale = new QLineEdit(centralWidget);
        lineEdit_meshScale->setObjectName(QString::fromUtf8("lineEdit_meshScale"));
        lineEdit_meshScale->setReadOnly(true);

        gridLayout->addWidget(lineEdit_meshScale, 10, 1, 1, 1);

        lineEdit_brightness = new QLineEdit(centralWidget);
        lineEdit_brightness->setObjectName(QString::fromUtf8("lineEdit_brightness"));
        lineEdit_brightness->setReadOnly(true);

        gridLayout->addWidget(lineEdit_brightness, 16, 1, 1, 1);

        label_meshScale = new QLabel(centralWidget);
        label_meshScale->setObjectName(QString::fromUtf8("label_meshScale"));

        gridLayout->addWidget(label_meshScale, 10, 0, 1, 1);

        lineEdit_normalCount = new QLineEdit(centralWidget);
        lineEdit_normalCount->setObjectName(QString::fromUtf8("lineEdit_normalCount"));
        lineEdit_normalCount->setReadOnly(true);

        gridLayout->addWidget(lineEdit_normalCount, 5, 1, 1, 1);

        label_texCoordCount = new QLabel(centralWidget);
        label_texCoordCount->setObjectName(QString::fromUtf8("label_texCoordCount"));

        gridLayout->addWidget(label_texCoordCount, 4, 0, 1, 1);

        label_verCoordCount = new QLabel(centralWidget);
        label_verCoordCount->setObjectName(QString::fromUtf8("label_verCoordCount"));

        gridLayout->addWidget(label_verCoordCount, 3, 0, 1, 1);

        lineEdit_verCoordCount = new QLineEdit(centralWidget);
        lineEdit_verCoordCount->setObjectName(QString::fromUtf8("lineEdit_verCoordCount"));
        lineEdit_verCoordCount->setReadOnly(true);

        gridLayout->addWidget(lineEdit_verCoordCount, 3, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        horizontalSlider_meshScale = new QSlider(centralWidget);
        horizontalSlider_meshScale->setObjectName(QString::fromUtf8("horizontalSlider_meshScale"));
        horizontalSlider_meshScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_meshScale, 11, 0, 1, 2);

        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 3);

        gridlayout->addLayout(gridLayout, 0, 2, 1, 1);

        gridlayout->setColumnStretch(0, 4);
        SphericalHarmonicsLightingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SphericalHarmonicsLightingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1529, 21));
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
        label->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Control Panel", nullptr));
        label_contrast->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Contrast (2.0)", nullptr));
        label_normalCount->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Normal Count", nullptr));
        label_brightness->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Brightness (0.13)", nullptr));
        label_ambientFactor->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Ambient Factor (0.35)", nullptr));
        pushButton_loadMesh->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Load Mesh", nullptr));
        label_faceCount->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Face Count", nullptr));
        label_meshScale->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Mesh Scale", nullptr));
        label_texCoordCount->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Texture Coord Count", nullptr));
        label_verCoordCount->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Vertex Coord Count", nullptr));
        label_2->setText(QCoreApplication::translate("SphericalHarmonicsLightingClass", "Infor Panel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SphericalHarmonicsLightingClass: public Ui_SphericalHarmonicsLightingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPHERICALHARMONICSLIGHTING_H
