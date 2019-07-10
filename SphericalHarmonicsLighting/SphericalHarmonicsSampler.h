#pragma once
#include <qvector.h>
#include <qimage.h>
#include <qfile.h>
#include <qdebug.h>
#include <qpainter.h>
#include <qvector2d.h>
#include <qvector3d.h>
#include <random>

struct Sample {
public:
	Sample() {};
	Sample(QVector3D verCoord, QColor verColor) {
		this->verCoord = verCoord;
		this->verColor = verColor;
	}
	QVector3D verCoord;
	QColor verColor;
};

class SphericalHarmonicsSampler {
public:
	SphericalHarmonicsSampler();
	~SphericalHarmonicsSampler();

	// skybox initialization
	void loadImage(QString &name, QString & filePath);
	void ImageComposition();

	// uv mapping
	QVector3D &CubeUV2XYZ(QVector2D &uv);
	QPair<QString, QVector2D> CubeXYZ2UV(QVector3D &verCoord);

	// sampling
	float NormalRandom(const float mu = 0.0f, const float sigma = 1.0f);
	void RandomSampling(int number);

	// spherical harmonics
	QVector<float> BasisCoefficients(const QVector3D& verCoord);
	void Evaluate(int degree);

private:
	// input
	QMap<QString, QImage*> images;
	QImage* texture;

	// samples
	QVector<Sample*> samples;

	// coefficients
	QVector<QVector3D> coefs;
};

