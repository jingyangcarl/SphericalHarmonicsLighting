#pragma once
#include "Transformational.h"
#include "Object3D.h"

class Group3D :
	public Transformational {
public:
	// constructor
	Group3D();
	~Group3D();

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

	// operation
	void addObject(Transformational* object);
	void delObject(Transformational* object);

private:
	// linear transformation
	QVector3D translation;
	QQuaternion rotation;
	float scalar;
	QMatrix4x4 globalTransformation;

	// mMatrix
	QMatrix4x4 localMatrix;

	// objects;
	QVector<Transformational*> objects;
};

