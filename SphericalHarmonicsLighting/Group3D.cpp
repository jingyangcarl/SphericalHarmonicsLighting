#include "Group3D.h"

Group3D::Group3D() {
	v_scale = 1.0f;
}

Group3D::~Group3D() {}

void Group3D::rotate(const QQuaternion& r) {
	v_rotation = r * v_rotation;

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(v_translation);
	localMatrix.rotate(v_rotation);
	localMatrix.scale(v_scale);
	localMatrix = v_globalTransformation * localMatrix;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::translate(const QVector3D& t) {
	v_translation += t;

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(v_translation);
	localMatrix.rotate(v_rotation);
	localMatrix.scale(v_scale);
	localMatrix = v_globalTransformation * localMatrix;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::scale(const float& s) {

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(v_translation);
	localMatrix.rotate(v_rotation);
	localMatrix.scale(v_scale);
	localMatrix = v_globalTransformation * localMatrix;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
	v_scale += s;
}

void Group3D::setGlobalTransform(const QMatrix4x4& g) {
	v_globalTransformation = g;

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(v_translation);
	localMatrix.rotate(v_rotation);
	localMatrix.scale(v_scale);
	localMatrix = v_globalTransformation * localMatrix;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	// call draw for each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->draw(shaderProgram, functions);
}

void Group3D::addObject(Transformational* object) {
	objects.append(object);

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(v_translation);
	localMatrix.rotate(v_rotation);
	localMatrix.scale(v_scale);
	localMatrix = v_globalTransformation * localMatrix;

	// apply on the added object
	objects[objects.size() - 1]->setGlobalTransform(localMatrix);
}

void Group3D::delObject(Transformational* object) {
	objects.removeAll(object);
}

void Group3D::delObject(const int& index) {
	objects.remove(index);
}
