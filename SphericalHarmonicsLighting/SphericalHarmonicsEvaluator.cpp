#include "SphericalHarmonicsEvaluator.h"

SphericalHarmonicsEvaluator::SphericalHarmonicsEvaluator(const QVector<Sample*>& samples, int level) :
	samples(samples), level(level) {
}

SphericalHarmonicsEvaluator::~SphericalHarmonicsEvaluator() {
}

QVector<float> SphericalHarmonicsEvaluator::BasisCoefficient(QVector3D & verCoord) {

	int n = pow(level + 1, 2);
	QVector<float> Y(n);
	QVector3D normal = verCoord;
	normal.normalize();
	float x = normal.x();
	float y = normal.y();
	float z = normal.z();

	if (level >= 0) {
		Y[0] = 1.0f / 2.0f * sqrt(1.0f / M_PI);
	}
	if (level >= 1) {
		Y[1] = sqrt(3.0f / (4.0f * M_PI))*z;
		Y[2] = sqrt(3.0f / (4.0f*M_PI))*y;
		Y[3] = sqrt(3.0f / (4.0f*M_PI))*x;
	}
	if (level >= 2) {
		Y[4] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * z;
		Y[5] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * z * y;
		Y[6] = 1.0f / 4.0f * sqrt(5.0f / M_PI) * (-x * x - z * z + 2 * y * y);
		Y[7] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * y * x;
		Y[8] = 1.0f / 4.0f * sqrt(15.0f / M_PI) * (x * x - z * z);
	}
	if (level >= 3) {
		Y[9] = 1.0f / 4.0f*sqrt(35.0f / (2.0f * M_PI)) * (3 * x * x - z * z)*z;
		Y[10] = 1.0f / 2.0f*sqrt(105.0f / M_PI) * x * z * y;
		Y[11] = 1.0f / 4.0f*sqrt(21.0f / (2.0f * M_PI)) * z * (4 * y * y - x * x - z * z);
		Y[12] = 1.0f / 4.0f*sqrt(7.0f / M_PI) * y * (2 * y*y - 3 * x*x - 3 * z*z);
		Y[13] = 1.0f / 4.0f*sqrt(21.0f / (2.0f * M_PI))*x*(4 * y*y - x*x - z*z);
		Y[14] = 1.0f / 4.0f*sqrt(105.0f / M_PI)*(x*x - z*z)*y;
		Y[15] = 1.0f / 4.0f*sqrt(35.0f / (2.0f * M_PI))*(x*x - 3 * z*z) * x;
	}

	return Y;
}

void SphericalHarmonicsEvaluator::Evaluate() {

	int n = pow(level + 1, 2);
	coefs = QVector<QVector3D>(n, QVector3D());

	for (int i = 0; i < samples.size(); i++) {
		auto Y = BasisCoefficient((samples[i])->verCoord);
		for (int j = 0; j < n; j++) {
			float r = (samples[i])->verColor.red();
			float g = (samples[i])->verColor.green();
			float b = (samples[i])->verColor.blue();
			coefs[j] = coefs[j] + Y[j] * QVector3D(r, g, b);
		}
	}
	for (auto coef = coefs.begin(); coef != coefs.end(); coef++) {
		(*coef) = 4 * M_PI * (*coef) / (float)samples.size() / 300;
	}

	//// save
	//QFile file("./Resources/Output/outputCoef.txt");
	//if (file.open(QIODevice::ReadWrite)) {
	//	QTextStream output(&file);
	//	for (int i = 0; i < coefs.size(); i++) {
	//		output << coefs[i][0] << '\t' << coefs[i][1] << '\t' << coefs[i][2] << endl;
	//	}
	//}
}

const QVector<QVector3D>& SphericalHarmonicsEvaluator::getCoefficients() const {
	// TODO: insert return statement here
	return coefs;
}
