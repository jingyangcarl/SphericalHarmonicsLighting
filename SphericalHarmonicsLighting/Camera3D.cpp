#include "Camera3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Camera3D::Camera3D() {
	scalar = 1.0f;
	globalTransformation.setToIdentity();
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Camera3D::~Camera3D() {
	delete &translation;
	delete &rotation;
	delete &scalar;
	delete &globalTransformation;
	delete &viewMatrix;
}

/*
Description:
	This function is used to rotate the camera;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Camera3D::rotate(const QQuaternion& r) {
	rotation = r * rotation;
}

/*
Description:
	This function is used to translate the camera;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Camera3D::translate(const QVector3D& t) {
	translation += t;
}

/*
Description:
	This function is used to scale the camera;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Camera3D::scale(const float& s) {
	scalar += s;
}

/*
Description:
	This function is used to set the global transform for the camera;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Camera3D::setGlobalTransform(const QMatrix4x4& g) {
	globalTransformation = g;
}

/*
Description:
	This function is used to set parameters for the vertex shader, fragment shader and etc.;
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Camera3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	if (functions != 0) return;

	viewMatrix.setToIdentity();
	viewMatrix.translate(translation);
	viewMatrix.rotate(rotation);
	viewMatrix.scale(scalar);
	viewMatrix = viewMatrix * globalTransformation.inverted();

	shaderProgram->setUniformValue("u_viewMatrix", viewMatrix);
	shaderProgram->setUniformValue("u_rotation", rotation.toVector4D());
	// try to pass camera pos to the shader program
	qDebug() << rotation;
	qDebug() << rotation.rotatedVector(viewMatrix.column(3).toVector3D());
	qDebug();
}