#pragma once
#include <qopenglwidget.h>
#include <qopenglshaderprogram>
#include <QKeyEvent>
#include <QtMath>
#include <qbasictimer.h>

#include "Object3D.h"
#include "Group3D.h"
#include "Camera3D.h"
#include "SkyBox.h"

class Widget :
	public QOpenGLWidget {
public:
	Widget(QWidget* parent = 0);
	~Widget();

protected:
	// initialization
	void initShaders();
	void loadObj(const QString& objPath, const QString &imgPath);

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	// callback
	void keyPressEvent(QKeyEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);
	void timerEvent(QTimerEvent* event);

private:
	// shader
	QOpenGLShaderProgram skyboxShader;
	QOpenGLShaderProgram objectShader;

	// object
	Skybox* skybox;
	QVector<Object3D*> objects;
	QVector<Group3D*> groups;
	QVector<Transformational*> transformObjects;

	// camera
	Camera3D* camera;

	// mouse
	QVector2D mousePosition;

	// timer
	QBasicTimer timer;
	float angleObject = 0.0f;
	float angleGroup = 0.0f;

	// pMatrix
	QMatrix4x4 projectionMatrix;
};

