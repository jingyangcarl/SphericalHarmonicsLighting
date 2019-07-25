#pragma once

#include "Transformational.h"
#include <qopenglshaderprogram.h>

class Camera3D : public Transformational {
public:
	// constructor
	Camera3D();
	~Camera3D();

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0);

private:
	// linear transformation
	QVector3D translation;
	QQuaternion rotation;
	float scalar;
	QMatrix4x4 globalTransformation;

	// vMatrix
	QMatrix4x4 viewMatrix;
};

