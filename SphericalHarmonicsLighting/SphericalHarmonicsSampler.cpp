#include "SphericalHarmonicsSampler.h"

SphericalHarmonicsSampler::SphericalHarmonicsSampler() {
}

SphericalHarmonicsSampler::~SphericalHarmonicsSampler() {
}

void SphericalHarmonicsSampler::loadImage(QString & name, QString & filePath) {

	QImage *image = new QImage(filePath);
	if (image) {
		images.insert(name, image);
	}
	else {
		qDebug() << "Carl::SphericalHarmonicsSampler::ImageComposition::images.size() error: image load failed";
	}
}

void SphericalHarmonicsSampler::ImageComposition() {
	if (images.size() < 6) {
		qDebug() << "Carl::SphericalHarmonicsSampler::ImageComposition::images.size() error: not enough images";
		exit(-1);
	}

	int width = (images.begin()).value()->width();
	int height = (images.begin()).value()->height();
	texture = new QImage(width * 4, height * 3, QImage::Format_RGB32);
	QImage blackImage(width, height, QImage::Format_RGB32);
	blackImage.fill(Qt::black);

	// paint image
	// |Black | PosY |Black |Black |
	// | NegX | NegY | PosX | PosZ |
	// |Black | NegY |Black |Black |
	QPainter *painter = new QPainter(texture);
	painter->drawImage(QPoint(0 * width, 0 * height), blackImage);
	painter->drawImage(QPoint(1 * width, 0 * height), *images.find("posy").value());
	painter->drawImage(QPoint(2 * width, 0 * height), blackImage);
	painter->drawImage(QPoint(3 * width, 0 * height), blackImage);
	painter->drawImage(QPoint(0 * width, 1 * height), *images.find("negx").value());
	painter->drawImage(QPoint(1 * width, 1 * height), *images.find("posz").value());
	painter->drawImage(QPoint(2 * width, 1 * height), *images.find("posx").value());
	painter->drawImage(QPoint(3 * width, 1 * height), *images.find("negz").value());
	painter->drawImage(QPoint(0 * width, 2 * height), blackImage);
	painter->drawImage(QPoint(1 * width, 2 * height), *images.find("negy").value());
	painter->drawImage(QPoint(2 * width, 2 * height), blackImage);
	painter->drawImage(QPoint(3 * width, 2 * height), blackImage);
	painter->end();
	painter->~QPainter();

	// save
	if (!texture->save("./Resources/Output/texture.jpg")) {
		qDebug() << "Carl::SphericalHarmonicsSampler::ImageComposition::images.size() error: save failed";
	}
}

QVector3D & SphericalHarmonicsSampler::CubeUV2XYZ(QVector2D & uv) {
	// TODO: insert return statement here
	return QVector3D();
}

QPair<QString, QVector2D> SphericalHarmonicsSampler::CubeXYZ2UV(QVector3D &verCoord) {
	float x = verCoord[0];
	float y = verCoord[1];
	float z = verCoord[2];
	float absX = abs(verCoord[0]);
	float absY = abs(verCoord[1]);
	float absZ = abs(verCoord[2]);
	QPair<QString, QVector2D> uvPair;
	
	if (absX >= absY && absX >= absZ) {
		if (x >= 0) {
			// right
			uvPair = QPair<QString, QVector2D>(QString("posx"), QVector2D(-z / x, y / absX));
		}
		else {
			// left
			uvPair = QPair<QString, QVector2D>(QString("negx"), QVector2D(-z / x, y / absX));
		}
	}
	else if (absY >= absZ) {
		if (y >= 0) {
			// top
			uvPair = QPair<QString, QVector2D>(QString("posy"), QVector2D(x / absY, -z / y));
		}
		else {
			// bottom
			uvPair = QPair<QString, QVector2D>(QString("negx"), QVector2D(x / absY, -z / y));
		}
	}
	else {
		if (z >= 0) {
			// front
			uvPair = QPair<QString, QVector2D>(QString("posz"), QVector2D(x / z, y / absZ));
		}
		else {
			// back
			uvPair = QPair<QString, QVector2D>(QString("negz"), QVector2D(x / z, y / absZ));
		}
	}
	// mapping in a single pic
	uvPair.second[0] = uvPair.second[0] * 0.5f + 0.5f;
	uvPair.second[1] = uvPair.second[1] * 0.5f + 0.5f;
	return uvPair;
}

float SphericalHarmonicsSampler::NormalRandom(const float mu, const float sigma) {
	// Gaussian distribution
	static std::default_random_engine generator;
	static std::normal_distribution<float> distribution(mu, sigma);
	return distribution(generator);
}

void SphericalHarmonicsSampler::RandomSampling(int number) {
	for (int i = 0; i < number; i++) {
		float x = NormalRandom(0.0f, 1.0f);
		float y = NormalRandom(0.0f, 1.0f);
		float z = NormalRandom(0.0f, 1.0f);
		Sample *sample = new Sample();
		sample->verCoord = QVector3D(x, y, z);
		auto uvPair = CubeXYZ2UV(sample->verCoord);
		sample->verColor = (images.find(uvPair.first).value())->pixel(uvPair.second[0], uvPair.second[1]);
		samples << sample;
	}
}

void SphericalHarmonicsSampler::Evaluate(int degree) {
	int n = degree * degree;
	for (const Sample* sample : samples) {

	}
}
