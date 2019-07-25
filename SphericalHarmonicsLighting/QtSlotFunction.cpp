#include "SphericalHarmonicsLighting.h"

/*
Description:
	This function is used to set ambient factor for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ int value: ambient factor;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::HorizontalSliderAmbientFactor(int value) {
	float ambientFactor = value / 100.0;
	ui.lineEdit_ambientFactor->setText(QString::number(ambientFactor));
	ui.openGLWidget->setAmbientFactor(ambientFactor);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to set contrast for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ int value: contrast;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::HorizontalSliderContrast(int value) {
	float contrast = value / 100.0;
	ui.lineEdit_contrast->setText(QString::number(contrast));
	ui.openGLWidget->setContrast(contrast);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to set brightness for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ int value: brightness;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::HorizontalSliderBrightness(int value) {
	float brightness = value / 100.0;
	ui.lineEdit_brightness->setText(QString::number(brightness));
	ui.openGLWidget->setBrightness(brightness);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to set mesh scale for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ int value: mesh scale;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::HorizontalSliderMeshScale(int value) {
	float meshScale = value / 10.0f;
	ui.lineEdit_meshScale->setText(QString::number(meshScale));
	ui.openGLWidget->setMeshScale(meshScale);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to set refraction ratio for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ int value: refraction ratio;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::HorizontalSliderRefractRatio(int value) {
	float refractRatio = value / 100.0;
	ui.lineEdit_refractRatio->setText(QString::number(refractRatio));
	ui.openGLWidget->setRefractRatio(refractRatio);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to set material type for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ QString value: material type;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::ComboBoxMaterialType(QString value) {
	ui.lineEdit_materialType->setText(value);
	ui.openGLWidget->setMaterialType(value);
	ui.openGLWidget->update();
}

/*
Description:
	This function is used to load mesh for QOpenGLWidget, namely Spherical Harmonics Lighting Widget class;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::PushButtonLoadMesh() {
	QString file = QFileDialog::getOpenFileName(this, tr("Select Mesh File"), "./Resources/Model", tr("Mesh File(*.obj)"));
	ui.openGLWidget->reloadMesh(file);
}
