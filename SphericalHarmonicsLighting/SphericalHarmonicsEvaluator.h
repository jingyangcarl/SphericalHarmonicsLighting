#pragma once
#include <qvector.h>
#include <qvector3d.h>
#include <qmath.h>
#include "SphericalHarmonicsSampler.h"

struct Sample;

class SphericalHarmonicsEvaluator {
public:
	SphericalHarmonicsEvaluator(const QVector<Sample*> &samples, int level);
	~SphericalHarmonicsEvaluator();

	QVector<float> BasisCoefficient(QVector3D& verCoord);
	void Evaluate();

	// get
	const QVector<QVector3D> & getCoefficients() const;

private:
	// paramters
	int level = 0;
	QVector<Sample*> samples;

	// coefficients
	QVector<QVector3D> coefs;
};

