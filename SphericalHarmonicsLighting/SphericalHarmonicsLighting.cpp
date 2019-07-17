#include "SphericalHarmonicsLighting.h"

SphericalHarmonicsLighting::SphericalHarmonicsLighting(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	ui.lineEdit_ambientFactor->setText(QString("0.0"));
	ui.lineEdit_contrast->setText(QString("0.0"));
	ui.lineEdit_brightness->setText(QString("0.0"));

	ui.horizontalSlider_ambientFactor->setMaximum(1.0);
	ui.horizontalSlider_ambientFactor->setMinimum(0.0);
	ui.horizontalSlider_contrast->setMaximum(10.0);
	ui.horizontalSlider_contrast->setMinimum(1.0);
	ui.horizontalSlider_brightness->setMaximum(1.0);
	ui.horizontalSlider_brightness->setMinimum(0.0);
}
