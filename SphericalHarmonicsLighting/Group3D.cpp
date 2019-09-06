#include "Group3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Group3D::Group3D() {
	scalar = 1.0f;
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Group3D::~Group3D() {
	delete &translation;
	delete &rotation;
	delete &scalar;
	delete &globalTransformation;
	delete &localMatrix;
	qDeleteAll(objects);
}

/*
Description:
	This function is used to rotate all the objects in a group, which calls Object3D::rotate(const QQuaternion&) for object rotation;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Group3D::rotate(const QQuaternion& r) {
	rotation = r * rotation;
	
	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

/*
Description:
	This function is used to translate all the objects in a group, which calls Object3D::translate(const QVector3D&) for object translation;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Group3D::translate(const QVector3D& t) {
	translation += t;
	
	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

/*
Description:
	This function is used to scale all the objects in a group, which calls Object3D::scale(const float&) for object scaling;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Group3D::scale(const float& s) {
	scalar += s;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

/*
Description:
	This function is used to set the global transform for all the objects in a group, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Group3D::setGlobalTransform(const QMatrix4x4& g) {
	globalTransformation = g;

	// apply on each objects
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

/*
Description:
	This function is used to draw all the objects in a group, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Group3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	// call draw for each objects
	localMatrix.setToIdentity();
	localMatrix.translate(translation);
	localMatrix.rotate(rotation);
	localMatrix.scale(scalar);
	localMatrix = globalTransformation * localMatrix;
	for (int i = 0; i < objects.size(); i++)
		objects[i]->draw(shaderProgram, functions);
}

/*
Description:
	This function is used to add object into the group list. An initialization of its position is necessary;
Input:
	@ Transformational * object: a given object;
Output:
	@ void returnValue: void;
*/
void Group3D::addObject(Transformational* object) {
	objects.append(object);

	// set local matrix
	localMatrix.setToIdentity();
	localMatrix.translate(translation);
	localMatrix.rotate(rotation);
	localMatrix.scale(scalar);
	localMatrix = globalTransformation * localMatrix;

	// apply on the added object
	objects[objects.size() - 1]->setGlobalTransform(localMatrix);
}

/*
Description:
	This function is used to remove an object from the group.
Input:
	@ Transformational * object: a given object;
Output:
	@ void returnValue: void;
*/
void Group3D::delObject(Transformational* object) {
	objects.removeAll(object);
}