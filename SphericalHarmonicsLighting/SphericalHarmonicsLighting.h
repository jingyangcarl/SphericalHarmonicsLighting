#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SphericalHarmonicsLighting.h"

class SphericalHarmonicsLighting : public QMainWindow
{
	Q_OBJECT

public:
	SphericalHarmonicsLighting(QWidget *parent = Q_NULLPTR);

private:
	Ui::SphericalHarmonicsLightingClass ui;
};
