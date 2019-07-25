#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include "ui_SphericalHarmonicsLighting.h"

class SphericalHarmonicsLighting : public QMainWindow
{
	Q_OBJECT

public:
	SphericalHarmonicsLighting(QWidget *parent = Q_NULLPTR);

	/*----------------QtInitialization.cpp-------------------*/
	void QWidgetInit();
	void InitHoriSliderAmbientFactor();
	void InitHoriSliderContrast();
	void InitHoriSliderBrightness();
	void InitHoriSliderMeshScale();
	void InitHoriSliderRefreactRatio();
	void InitComboBoxMaterialType();
	void InitPushButtonLoadMesh();
	void InitConnection();

public slots:
	/*---------------QtSlotFunction.cpp---------------------*/
	void HorizontalSliderAmbientFactor(int value);
	void HorizontalSliderContrast(int value);
	void HorizontalSliderBrightness(int value);
	void HorizontalSliderMeshScale(int value);
	void HorizontalSliderRefractRatio(int value);
	void ComboBoxMaterialType(QString value);
	void PushButtonLoadMesh();

private:
	Ui::SphericalHarmonicsLightingClass ui;
};
