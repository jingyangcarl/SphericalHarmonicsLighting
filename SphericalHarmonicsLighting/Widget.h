#pragma once
#include <qopenglwidget.h>
#include <qopenglshaderprogram>
#include <QKeyEvent>
#include <QtMath>
#include <qbasictimer.h>

#include "ObjectEngine3D.h"
#include "Group3D.h"
#include "Camera3D.h"
#include "SkyBox.h"
#include "SphericalHarmonicsSampler.h"
#include "SphericalHarmonicsEvaluator.h"

class Widget :
	public QOpenGLWidget {
public:
	Widget(QWidget* parent = 0);
	~Widget();

protected:
	/*----------------Widget.cpp-------------------*/
	void initSkybox();
	void initShaders();

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	/*----------------WidgetCallback.cpp-------------------*/
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
	QVector<ObjectEngine3D*> objects;
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

	// index
	int skyboxIndex = 0;
	//SphericalHarmonicsEvaluator *evaluator;
};

