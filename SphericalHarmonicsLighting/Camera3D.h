#pragma once

#include "Transformational.h"
#include <qopenglshaderprogram.h>

class Camera3D : public Transformational {
public:
	// constructor
	Camera3D();

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0);

private:
	// linear transformation
	QVector3D v_translation;
	QQuaternion v_rotation;
	float v_scale;
	QMatrix4x4 v_globalTransformation;

	// vMatrix
	QMatrix4x4 viewMatrix;
};

