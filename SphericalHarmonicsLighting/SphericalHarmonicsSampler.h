#pragma once
#include <qvector.h>
#include <qimage.h>
#include <qfile.h>
#include <qdebug.h>
#include <qpainter.h>
#include <qvector2d.h>
#include <qvector3d.h>
#include <random>
#include <qopengltexture.h>
#include <qmath.h>

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
	SphericalHarmonicsSampler(QMap<QString, QImage*> &images);
	~SphericalHarmonicsSampler();

	// setter and getter
	void setSphericalHarmonicLevel(const int level = 3);
	const QVector<Sample*> & getSamples() const;

private:
	// uv mapping
	QPair<QString, QVector2D> CubeXYZ2UV(QVector3D &verCoord);

	// sampling
	float NormalRandom(const float mu = 0.0f, const float sigma = 1.0f);
public:
	void RandomSampling(int number);

	/*---------------------SphericalHarmonicsEvaluation.cpp-------------------------*/
	// evaluation
private:
	QVector<float> BasisCoefficient(QVector3D& verCoord);
public:
	QVector<QVector3D> Evaluate();

private:
	// input
	QMap<QString, QImage*> &images;
	int level = 0;

	// samples
	QVector<Sample*> samples;
};

