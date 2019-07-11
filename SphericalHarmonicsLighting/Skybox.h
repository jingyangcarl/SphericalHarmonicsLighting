#pragma once
#include "Transformational.h"
#include "Object3D.h"

#include <qfile.h>
#include <qdir.h>

#include "SphericalHarmonicsSampler.h"
#include "SphericalHarmonicsEvaluator.h"

class Skybox : public Transformational {
public:
	// constructor
	Skybox(float width, const QImage& texture = QImage());
	~Skybox();

	// load
	void loadTextures();

	// reset texture
	void setTexture(QImage& texture);
	void setTexture(int index);
	QVector<QVector3D>& getSHCoefficient(int index);
	int loadNext();
	int loadPrevious();

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	Object3D* skyboxObj;

	// texture
	QVector<QImage> textures;
	QVector<QVector<QVector3D>> shCoefficients;
	int skyboxIndex;

	// Spherical Harmonics
	SphericalHarmonicsSampler *sampler;
	SphericalHarmonicsEvaluator *evaluator;
};