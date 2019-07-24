#include "SphericalHarmonicsSampler.h"

SphericalHarmonicsSampler::SphericalHarmonicsSampler() {
}

SphericalHarmonicsSampler::~SphericalHarmonicsSampler() {
	qDeleteAll(images);
}

QOpenGLTexture * SphericalHarmonicsSampler::getTexture() {
	return this->texture;
}

QImage & SphericalHarmonicsSampler::getTextureImage() {
	return this->texImage;
}

void SphericalHarmonicsSampler::loadImage(QString & name, QString & filePath) {

	QImage *image = new QImage(filePath);
	if (image && image->width() != 0) {
		images.insert(name, image);
	}
	else {
		qDebug() << "Carl::SphericalHarmonicsSampler::TextureImageExpand::images.size() error: image load failed";
	}
}

QImage &SphericalHarmonicsSampler::TextureImageExpand(bool isSave, float scaleRatio) {
	if (images.size() < 6) {
		qDebug() << "Carl::SphericalHarmonicsSampler::TextureImageExpand::images.size() error: not enough images";
		exit(-1);
	}

	int width = (images.begin()).value()->width();
	int height = (images.begin()).value()->height();

	// paint image
	// |Black | PosY |Black |Black |
	// | NegX | NegY | PosX | PosZ |
	// |Black | NegY |Black |Black |
	texImage = QImage(width * 4, height * 3, QImage::Format_RGB32);
	QImage blackImage(width, height, QImage::Format_RGB32);
	blackImage.fill(Qt::black);
	QPainter *painter = new QPainter(&texImage);
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

	// scale
	texImage = texImage.scaled(texImage.width() * scaleRatio, texImage.height() * scaleRatio, Qt::KeepAspectRatio);

	// save
	if (isSave) {
		if (!texImage.save("./Resources/Output/texImage.jpg")) {
			qDebug() << "Carl::SphericalHarmonicsSampler::TextureImageExpand::images.size() error: save failed";
		}
	}

	return texImage;
}

QOpenGLTexture * SphericalHarmonicsSampler::TextureExpand() {
	if (images.size() < 6) {
		qDebug() << "Carl::SphericalHarmonicsSampler::TextureExpand::images.size() error: not enough images";
		exit(-1);
	}
	texture = new QOpenGLTexture(QOpenGLTexture::TargetCubeMap);
	texture->create();
	texture->setSize((*images.find("posx").value()).width(), (*images.find("posx").value()).height(), (*images.find("posx").value()).depth());
	texture->setFormat(QOpenGLTexture::RGBAFormat);
	texture->allocateStorage();
	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveX, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("posx").value()).constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveY, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("posy").value()).constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapPositiveZ, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("posz").value()).constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeX, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("negx").value()).constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeY, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("negy").value()).constBits(), 0);
	texture->setData(0, 0, QOpenGLTexture::CubeMapNegativeZ, QOpenGLTexture::BGRA, QOpenGLTexture::UInt8, (const void*)(*images.find("negz").value()).constBits(), 0);
	texture->setWrapMode(QOpenGLTexture::ClampToEdge);
	texture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->setMagnificationFilter(QOpenGLTexture::LinearMipMapLinear);
	texture->generateMipMaps();

	return texture;
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
			uvPair = QPair<QString, QVector2D>(QString("negy"), QVector2D(x / absY, -z / y));
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

	int width = (images.begin()).value()->width();
	int height = (images.begin()).value()->height();

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
	}
}

const QVector<Sample*>& SphericalHarmonicsSampler::getSamples() const {
	// TODO: insert return statement here
	return samples;
}