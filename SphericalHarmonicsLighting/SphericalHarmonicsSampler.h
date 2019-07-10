#pragma once
#include <qvector.h>
#include <qimage.h>
#include <qfile.h>
#include <qdebug.h>
#include <qpainter.h>
#include <qvector2d.h>
#include <qvector3d.h>

class SphericalHarmonicsSampler {
public:
	SphericalHarmonicsSampler();
	~SphericalHarmonicsSampler();

	// skybox initialization
	void loadImage(QString &name, QString & filePath);
	void ImageComposition();

	// uv mapping
	QVector3D CubeUV2XYZ(QVector2D uv);
	QVector2D CubeXYZ2UV(QVector3D xyz);

private:
	// input
	QMap<QString, QImage*> images;
	QImage* texture;

	// samples
	QVector<QPair<QVector3D, QVector2D>> samples;
};

