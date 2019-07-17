#include "SphericalHarmonicsLighting.h"

SphericalHarmonicsLighting::SphericalHarmonicsLighting(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	// Load Mesh Button
	ui.lineEdit_verCoordCount->setText(QString::number(0));
	ui.lineEdit_texCoordCount->setText(QString::number(0));
	ui.lineEdit_normalCount->setText(QString::number(0));
	ui.lineEdit_faceCount->setText(QString::number(0));
	connect(ui.pushButton_loadMesh, SIGNAL(clicked()), 
			this, SLOT(PushButtonLoadMesh()));

	// Ambient Factor
	ui.horizontalSlider_ambientFactor->setMaximum(100);
	ui.horizontalSlider_ambientFactor->setMinimum(0);
	ui.horizontalSlider_ambientFactor->setValue(35);
	ui.lineEdit_ambientFactor->setText(QString::number(0.35));
	connect(ui.horizontalSlider_ambientFactor, SIGNAL(valueChanged(int)), 
			this, SLOT(HorizontalSliderAmbientFactor()));

	// Contrast
	ui.horizontalSlider_contrast->setMaximum(400);
	ui.horizontalSlider_contrast->setMinimum(1);
	ui.horizontalSlider_contrast->setValue(200);
	ui.lineEdit_contrast->setText(QString::number(2.0));
	connect(ui.horizontalSlider_contrast, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderContrast()));

	// Brightness
	ui.horizontalSlider_brightness->setMaximum(100);
	ui.horizontalSlider_brightness->setMinimum(0);
	ui.horizontalSlider_brightness->setValue(13);
	ui.lineEdit_brightness->setText(QString::number(0.13));
	connect(ui.horizontalSlider_brightness, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderBrightness()));

	// Mesh Scale
	ui.horizontalSlider_meshScale->setMaximum(100);
	ui.horizontalSlider_meshScale->setMinimum(1);
	ui.horizontalSlider_meshScale->setValue(10);
	ui.lineEdit_meshScale->setText(QString::number(1.0));
	connect(ui.horizontalSlider_meshScale, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderMeshScale()));
}