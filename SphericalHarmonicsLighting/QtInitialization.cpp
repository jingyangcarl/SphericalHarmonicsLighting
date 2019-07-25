#include "SphericalHarmonicsLighting.h"

/*
Description:
	This function is used to initialize all the Qt widgets and build up connections;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::QWidgetInit() {
	InitHoriSliderAmbientFactor();
	InitHoriSliderContrast();
	InitHoriSliderBrightness();
	InitHoriSliderMeshScale();
	InitHoriSliderRefreactRatio();
	InitComboBoxMaterialType();
	InitPushButtonLoadMesh();
	InitConnection();
}

/*
Description:	
	This function is used to initialize the Horizontal Slider for Ambient Factor;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitHoriSliderAmbientFactor() {
	ui.horizontalSlider_ambientFactor->setMaximum(100);
	ui.horizontalSlider_ambientFactor->setMinimum(0);
	ui.horizontalSlider_ambientFactor->setValue(35);
	ui.lineEdit_ambientFactor->setText(QString::number(0.35));
}

/*
Description:
	This function is used to initialize the Horizontal Slider for Contrast;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitHoriSliderContrast() {
	ui.horizontalSlider_contrast->setMaximum(400);
	ui.horizontalSlider_contrast->setMinimum(1);
	ui.horizontalSlider_contrast->setValue(200);
	ui.lineEdit_contrast->setText(QString::number(2.0));
}

/*
Description:
	This function is used to initialize the Horizontal Slider for Brightness;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitHoriSliderBrightness() {
	ui.horizontalSlider_brightness->setMaximum(100);
	ui.horizontalSlider_brightness->setMinimum(0);
	ui.horizontalSlider_brightness->setValue(13);
	ui.lineEdit_brightness->setText(QString::number(0.13));
}

/*
Description:
	This function is used to initialize the Horizontal Slider for Mesh Scale;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitHoriSliderMeshScale() {
	ui.horizontalSlider_meshScale->setMaximum(100);
	ui.horizontalSlider_meshScale->setMinimum(1);
	ui.horizontalSlider_meshScale->setValue(10);
	ui.lineEdit_meshScale->setText(QString::number(1.0));
}

/*
Description:
	This function is used to initialize the Horizontal Slider for Refreaction Ratio;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitHoriSliderRefreactRatio() {
	ui.horizontalSlider_refractRatio->setMaximum(100);
	ui.horizontalSlider_refractRatio->setMinimum(1);
	ui.horizontalSlider_refractRatio->setValue(66);
	ui.lineEdit_refractRatio->setText(QString::number(0.66));
}

/*
Description:
	This function is used to initialize the Combo Box for Material Type;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitComboBoxMaterialType() {
	ui.comboBox_materialType->setCurrentIndex(0);
	ui.lineEdit_materialType->setText(ui.comboBox_materialType->currentText());
}

/*
Description:
	This function is used to initialize the Push Button for mesh loading;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitPushButtonLoadMesh() {

}

/*
Description:
	This function is used to initialize connections between Qt slots and Qt signals;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsLighting::InitConnection() {
	// Load Mesh Button
	connect(ui.pushButton_loadMesh, SIGNAL(clicked()),
			this, SLOT(PushButtonLoadMesh()));

	// Material Type
	connect(ui.comboBox_materialType, SIGNAL(currentTextChanged(QString)),
			this, SLOT(ComboBoxMaterialType(QString)));

	// Ambient Factor
	connect(ui.horizontalSlider_ambientFactor, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderAmbientFactor(int)));

	// Contrast
	connect(ui.horizontalSlider_contrast, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderContrast(int)));

	// Brightness
	connect(ui.horizontalSlider_brightness, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderBrightness(int)));

	// Mesh Scale
	connect(ui.horizontalSlider_meshScale, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderMeshScale(int)));

	// Refract ratio
	connect(ui.horizontalSlider_refractRatio, SIGNAL(valueChanged(int)),
			this, SLOT(HorizontalSliderRefractRatio(int)));
}
