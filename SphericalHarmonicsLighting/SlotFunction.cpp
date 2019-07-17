#include "SphericalHarmonicsLighting.h"

void SphericalHarmonicsLighting::HorizontalSliderAmbientFactor() {
	int value = ui.horizontalSlider_ambientFactor->value();
	float ambientFactor = value / 100.0;
	ui.lineEdit_ambientFactor->setText(QString::number(ambientFactor));
	ui.openGLWidget->setAmbientFactor(ambientFactor);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::HorizontalSliderContrast() {
	int value = ui.horizontalSlider_contrast->value();
	float contrast = value / 100.0;
	ui.lineEdit_contrast->setText(QString::number(contrast));
	ui.openGLWidget->setContrast(contrast);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::HorizontalSliderBrightness() {
	int value = ui.horizontalSlider_brightness->value();
	float brightness = value / 100.0;
	ui.lineEdit_brightness->setText(QString::number(brightness));
	ui.openGLWidget->setBrightness(brightness);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::HorizontalSliderMeshScale() {
	int value = ui.horizontalSlider_meshScale->value();
	float meshScale = value / 10.0f;
	ui.lineEdit_meshScale->setText(QString::number(meshScale));
	ui.openGLWidget->setMeshScale(meshScale);
	ui.openGLWidget->update();
}

void SphericalHarmonicsLighting::PushButtonLoadMesh() {
	QString file = QFileDialog::getOpenFileName(this, tr("Select Mesh File"), "./Resources/Model", tr("Mesh File(*.obj)"));
	ui.openGLWidget->reloadMesh(file);
}
