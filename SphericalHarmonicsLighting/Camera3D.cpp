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
}

const QMatrix4x4 & Camera3D::getViewMatrix() const {
	// TODO: insert return statement here
	return viewMatrix;
}
