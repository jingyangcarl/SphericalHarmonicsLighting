#pragma once
#include "Transformational.h"
#include "Object3D.h"

#include <qfile.h>

class Skybox : public Transformational {
public:
	// constructor
	Skybox(float width, const QImage& texture = QImage());
	~Skybox();

	// load
	void loadTextures();
	void loadCoefficients();

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
	Object3D* skybox;

	// texture
	QVector<QImage> imgTextures;
	QVector<QVector<QVector3D>> imgSHCoefficients;
	int skyboxIndex;

	// Spherical Harmonics

};