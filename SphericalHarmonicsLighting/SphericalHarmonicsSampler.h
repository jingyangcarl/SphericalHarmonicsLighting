#pragma once
#include <qvector.h>
#include <qimage.h>
#include <qfile.h>
#include <qdebug.h>
#include <qpainter.h>

class SphericalHarmonicsSampler {
public:
	SphericalHarmonicsSampler();
	~SphericalHarmonicsSampler();

	void loadImage(QString &name, QString & filePath);
	void ImageComposition();

private:
	// 
	QMap<QString, QImage*> images;
	QImage* texture;
};

