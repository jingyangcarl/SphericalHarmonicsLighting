#pragma once
#include "Object3D.h"
#include "MaterialLibrary.h"

class ObjectEngine3D : public Transformational {
public:
	ObjectEngine3D();
	~ObjectEngine3D();

	// getter
	void addObject(Object3D* object);
	const Object3D* getObject(int index) const;
	const int getVerCoordCount(const int index) const;
	const int getTexCoordCount(const int index) const;
	const int getNormalCount(const int index) const;
	const int getFaceCount(const int index) const;

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

	// load mesh
	void loadObjectFromFile(const QString & filePath);

private:
	QVector<Object3D *> objects;
	MaterialLibrary materials;
};

