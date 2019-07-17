#include "SphericalHarmonicsLighting.h"

SphericalHarmonicsLighting::SphericalHarmonicsLighting(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);


	ui.horizontalSlider_ambientFactor->setMaximum(100);
	ui.horizontalSlider_ambientFactor->setMinimum(0);
	ui.horizontalSlider_ambientFactor->setValue(35);
	ui.lineEdit_ambientFactor->setText(QString::number(35.0/100.0));

	ui.horizontalSlider_contrast->setMaximum(100);
	ui.horizontalSlider_contrast->setMinimum(1);
	ui.horizontalSlider_contrast->setValue(20);
	ui.lineEdit_contrast->setText(QString::number(20.0/10.0));

	ui.horizontalSlider_brightness->setMaximum(100);
	ui.horizontalSlider_brightness->setMinimum(0);
	ui.horizontalSlider_brightness->setValue(13);
	ui.lineEdit_brightness->setText(QString::number(13.0/100.0));

	connect(ui.horizontalSlider_ambientFactor, SIGNAL(valueChanged(int)), 
			this, SLOT(HorizontalSliderAmbientFactor()));
	connect(ui.horizontalSlider_contrast, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderContrast()));
	connect(ui.horizontalSlider_brightness, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderBrightness()));
}