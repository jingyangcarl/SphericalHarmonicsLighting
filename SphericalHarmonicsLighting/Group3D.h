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
	void delObject(const int& index);

	// setter and getter


private:
	// linear transformation
	QVector3D v_translation;
	QQuaternion v_rotation;
	float v_scale;
	QMatrix4x4 v_globalTransformation;

	// mMatrix
	QMatrix4x4 localMatrix;

	// objects;
	QVector<Transformational*> objects;
	int textureIndex = 0;
};

