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
	Skybox(const float& width = 70.0f);
	~Skybox();

	// load data
	bool loadCube(int width, QVector<Vertex>& desVertices, QVector<GLuint>& desIndices);
	bool loadTextures();
	bool loadMaterial(Material& material);

	// change texture
public:
	bool setTexture(QImage& image);
private:
	bool setTexture(int index);
public:
	QImage& getTexture(const int index) const;
	QVector<QVector3D>& getCoefficient() const;
	QVector<QVector3D>& getCoefficient(const int index) const;

	// change status
	void loadNext();
	void loadPrev();

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	// object
	Object3D* object;

	// list
	QVector<QImage*> textures;
	QVector<QVector<QVector3D>*> coefficients;

	// current status
	int index;
	QImage* currentTex = 0;
	QVector<QVector3D>* currentCoef = 0;

	// Spherical Harmonics
	SphericalHarmonicsSampler *sampler = 0;
	SphericalHarmonicsEvaluator *evaluator = 0;
};