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
