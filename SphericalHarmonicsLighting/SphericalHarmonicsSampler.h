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

	// setter and getter
	QOpenGLTexture * getTexture();
	QImage & getTextureImage();

	// skybox initialization
	void loadImage(QString &name, QString & filePath);
	QImage &TextureImageExpand(bool isSave = false, float scaleRatio = 0.5f);
	QOpenGLTexture * TextureExpand();


	// uv mapping
	QVector3D &CubeUV2XYZ(QVector2D &uv);
	QPair<QString, QVector2D> CubeXYZ2UV(QVector3D &verCoord);

	// sampling
	float NormalRandom(const float mu = 0.0f, const float sigma = 1.0f);
	void RandomSampling(int number);

	// get
	const QVector<Sample*> & getSamples() const;

private:
	// input
	QMap<QString, QImage*> images;
	QOpenGLTexture * texture;
	QImage texImage;

	// samples
	QVector<Sample*> samples;
};

