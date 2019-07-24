#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include "ui_SphericalHarmonicsLighting.h"

class SphericalHarmonicsLighting : public QMainWindow
{
	Q_OBJECT

public:
	SphericalHarmonicsLighting(QWidget *parent = Q_NULLPTR);

public slots:
	/*-------------------SlotFunction.cpp-------------------------*/
	void HorizontalSliderAmbientFactor();
	void HorizontalSliderContrast();
	void HorizontalSliderBrightness();
	void HorizontalSliderMeshScale();
	void HorizontalSliderRefractRatio();
	void ComboBoxMaterialType();
	void PushButtonLoadMesh();

private:
	Ui::SphericalHarmonicsLightingClass ui;
};
