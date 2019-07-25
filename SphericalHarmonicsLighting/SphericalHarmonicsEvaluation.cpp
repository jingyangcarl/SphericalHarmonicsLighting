#include "SphericalHarmonicsSampler.h"

/*
Description:
	This function is used to generate spherical harmonic lighting basis, a 16x1 vector, for a given point;
Input:
	@ QVector3D & verCoord: a given sample's location;
Output:
	@ QVector<float> returnValue: corresponding spherical harmonic lighting coefficients;
*/
QVector<float> SphericalHarmonicsSampler::BasisCoefficient(QVector3D & verCoord) {

	int n = pow(level + 1, 2);
	QVector<float> Y(n);
	QVector3D normal = verCoord;
	normal.normalize();
	float x = normal.x();
	float y = normal.y();
	float z = normal.z();
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	if (level >= 0) {
		Y[0] = 1.0f / 2.0f * sqrt(1.0f / M_PI); // check
	}
	if (level >= 1) {
		Y[1] = sqrt(3.0f / (4.0f * M_PI)) * y; // check
		Y[2] = sqrt(3.0f / (4.0f * M_PI)) * z; // check
		Y[3] = sqrt(3.0f / (4.0f * M_PI)) * x; // check
	}
	if (level >= 2) {
		Y[4] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * y; // check
		Y[5] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * z * y; // check
		Y[6] = 1.0f / 4.0f * sqrt(5.0f / M_PI) * (-x2 - y2 + 2.0f*z2); // check
		Y[7] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * z; // check
		Y[8] = 1.0f / 4.0f * sqrt(15.0f / M_PI) * (x2 - y2); // check
	}
	if (level >= 3) {
		Y[9] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (3.0f*x2 - y2) * y; // check
		Y[10] = 1.0f / 2.0f * sqrt(105.0f / M_PI) * x * z * y; // check
		Y[11] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * y * (5.0f*z2 - x2 - y2); // check
		Y[12] = 1.0f / 4.0f * sqrt(7.0f / M_PI) * z * (1.5f*z2 - 3.0f*x2 - 3.0f*y2); // check
		Y[13] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * x * (5.0f*z2 - x2 - y2); // check
		Y[14] = 1.0f / 4.0f * sqrt(105.0f / M_PI) * (x2 - y2) * z; // check
		Y[15] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (x2 - 3.0f*y2) * x; // check
	}

	return Y;
}

/*
Description:
	This function is used to evaluate all the samples and generate spherical harmonics lighting coefficients;
Input:
	@ void parameter: void;
Output:
	@ QVector<QVector3D> & returnValue: spherical harmonic lighting coefficients;
*/
QVector<QVector3D> SphericalHarmonicsSampler::Evaluate() {
	int n = pow(level + 1, 2);
	QVector<QVector3D> coefs = QVector<QVector3D>(n, QVector3D());

	for (int i = 0; i < samples.size(); i++) {
		auto Y = BasisCoefficient((samples[i])->verCoord);
		float r = (samples[i])->verColor.red();
		float g = (samples[i])->verColor.green();
		float b = (samples[i])->verColor.blue();
		QVector3D color(r, g, b);
		color /= 256;
		for (int j = 0; j < n; j++) {
			coefs[j] += Y[j] * color;
		}
	}

	double factor = 0.5;
	for (auto coef = coefs.begin(); coef != coefs.end(); coef++) {
		(*coef) = factor * 4 * M_PI * (*coef) / samples.size();
	}

	return coefs;
}
