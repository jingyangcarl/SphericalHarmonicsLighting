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

	void loadImage(QString & filePath);
	void loadImages(QVector<QString> & filePaths);
	void ImageComposition();

private:
	// 
	QVector<QImage*> images;
	QImage texture;
};

