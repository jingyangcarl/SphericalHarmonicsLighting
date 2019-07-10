#include "SphericalHarmonicsSampler.h"

SphericalHarmonicsSampler::SphericalHarmonicsSampler() {
}

SphericalHarmonicsSampler::~SphericalHarmonicsSampler() {
}

void SphericalHarmonicsSampler::loadImage(QString & filePath) {

	QImage *image = new QImage(filePath);
	if (image) {
		images << image;
	}
}

void SphericalHarmonicsSampler::loadImages(QVector<QString>& filePaths) {
	for (int i = 0; i < filePaths.size(); i++) {
		loadImage(filePaths[i]);
	}
}

void SphericalHarmonicsSampler::ImageComposition() {
	if (images.size() < 6) {
		qDebug() << "Carl::SphericalHarmonicsSampler::ImageComposition::images.size() error: not enough images";
		exit(-1);
	}
	QImage destImage(images[0]->width() * 4, images[0]->height() * 3, QImage::Format_RGB32);
	QPainter painter(&destImage);
	painter.drawImage(QPoint(0, 0), *images[0]);
	painter.end();
	if (!destImage.save("./Resources/Output/test.jpg")) {
		qDebug() << "Carl::SphericalHarmonicsSampler::ImageComposition::images.size() error: save failed";
	}
}
