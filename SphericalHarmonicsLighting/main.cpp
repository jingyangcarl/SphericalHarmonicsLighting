#include "SphericalHarmonicsLighting.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SphericalHarmonicsLighting w;
	w.show();
	return a.exec();
}
