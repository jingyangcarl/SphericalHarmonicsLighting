#include "SphericalHarmonicsLighting.h"

void SphericalHarmonicsLighting::HorizontalSliderAmbientFactor() {
	int value = ui.horizontalSlider_ambientFactor->value();
	float ambientFactor = value / 100.0f;
	ui.lineEdit_ambientFactor->setText(QString::number(ambientFactor));
	ui.openGLWidget->setAmbientFactor(ambientFactor);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::HorizontalSliderContrast() {
	int value = ui.horizontalSlider_contrast->value();
	float contrast = value / 10.0f;
	ui.lineEdit_contrast->setText(QString::number(contrast));
	ui.openGLWidget->setContrast(contrast);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::HorizontalSliderBrightness() {
	int value = ui.horizontalSlider_brightness->value();
	float brightness = value / 100.0f;
	ui.lineEdit_brightness->setText(QString::number(brightness));
	ui.openGLWidget->setBrightness(brightness);
	ui.openGLWidget->update();
}
