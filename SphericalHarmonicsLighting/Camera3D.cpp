#include "Camera3D.h"

Camera3D::Camera3D() {
	v_scale = 1.0f;
	v_globalTransformation.setToIdentity();
}

void Camera3D::rotate(const QQuaternion& r) {
	v_rotation = r * v_rotation;
}

void Camera3D::translate(const QVector3D& t) {
	v_translation += t;
}

void Camera3D::scale(const float& s) {
	v_scale += s;
}

void Camera3D::setGlobalTransform(const QMatrix4x4& g) {
	v_globalTransformation = g;
}

void Camera3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	if (functions != 0) return;

	viewMatrix.setToIdentity();
	viewMatrix.translate(v_translation);
	viewMatrix.rotate(v_rotation);
	viewMatrix.scale(v_scale);
	viewMatrix = viewMatrix * v_globalTransformation.inverted();

	shaderProgram->setUniformValue("u_viewMatrix", viewMatrix);
	shaderProgram->setUniformValue("u_rotation", v_rotation.toVector4D());
	// try to pass camera pos to the shader program
	getCameraPos(viewMatrix);
	qDebug() << v_rotation;
	qDebug() << v_rotation.rotatedVector(viewMatrix.column(3).toVector3D());
	qDebug();
}

const QMatrix4x4 & Camera3D::getViewMatrix() const {
	// TODO: insert return statement here
	return viewMatrix;
}

const QVector3D Camera3D::getCameraPos(QMatrix4x4 & viewMatrix) {
	QMatrix3x3 rotation = viewMatrix.normalMatrix();
	qDebug() << rotation;
	QQuaternion quaternion = QQuaternion::fromRotationMatrix(rotation);
	qDebug() << quaternion;
	QVector3D result = quaternion.rotatedVector(viewMatrix.column(3).toVector3D());
	qDebug() << result;
	qDebug() << viewMatrix.mapVector(viewMatrix.column(3).toVector3D());
	return result;
}