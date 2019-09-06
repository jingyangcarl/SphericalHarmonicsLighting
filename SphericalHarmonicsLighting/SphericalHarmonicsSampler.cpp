#include "SphericalHarmonicsSampler.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
SphericalHarmonicsSampler::SphericalHarmonicsSampler(QMap<QString, QImage*> &images) :
	images(images) {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
SphericalHarmonicsSampler::~SphericalHarmonicsSampler() {
	qDeleteAll(images);
	qDeleteAll(samples);
}

/*
Description:
	This function is used to set spherical harmonics level for the sampler;
Input:
	@ const int level: spherical harmonic level;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsSampler::setSphericalHarmonicLevel(const int level) {
	this->level = level;
}

/*
Description:
	This function is used for getting samples for Spherical Harmonics Evaluator;
Input:
	@ void parameter: void;
Output:
	@ const QVector<Sample*>& returnValue: samples
*/
const QVector<Sample*>& SphericalHarmonicsSampler::getSamples() const {
	return samples;
}

/*
Description:
	This function is used for the transformation from 3D coordination to uv map coordination;
Input:
	@ QVector3D &verCoord: a 3D coordination;
Output:
	@ QPair<QString, QVector2D> returnValue: uv map coordination with its face index;
*/
QPair<QString, QVector2D> SphericalHarmonicsSampler::CubeXYZ2UV(QVector3D &verCoord) {
	float x = verCoord[0];
	float y = verCoord[1];
	float z = verCoord[2];
	float absX = abs(verCoord[0]);
	float absY = abs(verCoord[1]);
	float absZ = abs(verCoord[2]);
	QPair<QString, QVector2D> uvPair;
	
	if (absX >= absY && absX >= absZ) {
		// right / left
		uvPair = QPair<QString, QVector2D>(QString(x >= 0 ? "posx" : "negx"), QVector2D(-z / x, y / absX));
	}
	else if (absY >= absZ) {
		// top / bottom
		uvPair = QPair<QString, QVector2D>(QString(y >= 0 ? "posy" : "negy"), QVector2D(x / absY, -z / y));
	}
	else {
		// front / back
		uvPair = QPair<QString, QVector2D>(QString(z >= 0 ? "posz" : "negz"), QVector2D(x / z, y / absZ));
	}

	// mapping in a single pic
	uvPair.second[0] = uvPair.second[0] * 0.5f + 0.5f;
	uvPair.second[1] = uvPair.second[1] * 0.5f + 0.5f;
	return uvPair;
}

/*
Description:
	This function is used to generate a normal random value;
Input:
	@ const float mu: the mean of the distribution;
	@ const float sigma: the standard deviation;
Output:
	@ float returnValue: a generated random value;
*/
float SphericalHarmonicsSampler::NormalRandom(const float mu, const float sigma) {
	// Gaussian distribution
	static std::default_random_engine generator;
	static std::normal_distribution<float> distribution(mu, sigma);
	return distribution(generator);
}

/*
Description:
	This function is used to generate a given number of samples that consist of coordinations and its corresponding colors on uv map;
Input:
	@ int number: number of samples;
Output:
	@ void returnValue: void;
*/
void SphericalHarmonicsSampler::RandomSampling(int number) {

	int width = (images.begin()).value()->width();
	int height = (images.begin()).value()->height();

	/*-------------------------*/
	//QImage output_negx(width, height, QImage::Format_RGB32);
	//QImage output_negy(width, height, QImage::Format_RGB32);
	//QImage output_negz(width, height, QImage::Format_RGB32);
	//QImage output_posx(width, height, QImage::Format_RGB32);
	//QImage output_posy(width, height, QImage::Format_RGB32);
	//QImage output_posz(width, height, QImage::Format_RGB32);
	//output_negx.fill(Qt::black);
	//output_negy.fill(Qt::black);
	//output_negz.fill(Qt::black);
	//output_posx.fill(Qt::black);
	//output_posy.fill(Qt::black);
	//output_posz.fill(Qt::black);
	//int count_negx(0);
	//int count_negy(0);
	//int count_negz(0);
	//int count_posx(0);
	//int count_posy(0);
	//int count_posz(0);
	/*-------------------------*/

	for (int i = 0; i < number; i++) {
		float x = NormalRandom(0.0f, 1.0f);
		float y = NormalRandom(0.0f, 1.0f);
		float z = NormalRandom(0.0f, 1.0f);
		Sample *sample = new Sample();
		sample->verCoord = QVector3D(x, y, z);
		auto uvPair = CubeXYZ2UV(sample->verCoord);
		int pixelCoordX = uvPair.second[0] * width;
		int pixelCoordY = uvPair.second[1] * height;
		sample->verColor = (images.find(uvPair.first).value())->pixelColor(pixelCoordX, pixelCoordY).rgb();
		samples << sample;

		/*-------------------------*/
		//int colorFactor = 1.5;
		//if (uvPair.first == "negx") {
		//	count_negx++;
		//	output_negx.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//}
		//else if (uvPair.first == "negy") {
		//	count_negy++;
		//	output_negy.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//}
		//else if (uvPair.first == "negz") {
		//	count_negz++;
		//	output_negz.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//}
		//else if (uvPair.first == "posx") {
		//	count_posx++;
		//	output_posx.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//}
		//else if (uvPair.first == "posy") {
		//	count_posy++;
		//	output_posy.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//} 
		//else if (uvPair.first == "posz") {
		//	count_posz++;
		//	output_posz.setPixelColor(int(uvPair.second[0] * width), int(uvPair.second[1] * height), sample->verColor.rgb() * colorFactor);
		//}
		/*-------------------------*/
	}

	//output_negx.save("./Resources/Output/negx.jpg");
	//output_negy.save("./Resources/Output/negy.jpg");
	//output_negz.save("./Resources/Output/negz.jpg");
	//output_posx.save("./Resources/Output/posx.jpg");
	//output_posy.save("./Resources/Output/posy.jpg");
	//output_posz.save("./Resources/Output/posz.jpg");
}