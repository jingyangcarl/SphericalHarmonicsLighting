#pragma once
#include <qopenglwidget.h>
#include <qopenglshaderprogram>
#include <qopengldebug.h>
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

	/*------------------WidgetParameter.cpp-------------------*/
	void setAmbientFactor(const float ambientFactor);
	const float getAmbientFactor() const;
	void setContrast(const float contrast);
	const float getContrast() const;
	void setBrightness(const float brightness);
	const float getBrightness() const;
	void setMeshScale(const float meshScale);
	const float getMeshScale() const;
	void reloadMesh(const QString file);

protected:
	/*----------------Widget.cpp-------------------*/
	void initShaders();
protected:
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
	QOpenGLDebugLogger * debugLogger;

	// object
	Skybox* skybox;
	QVector<ObjectEngine3D*> objects;
	QVector<Group3D*> groups;
	QVector<Transformational*> transformObjects;

	// index
	int skyboxIndex = 0;

	// camera
	Camera3D* camera;

	// pMatrix
	QMatrix4x4 projectionMatrix;

	// mouse
	QVector2D mousePosition;

	// timer
	QBasicTimer timer;
	float angleObject = 0.0f;
	float angleGroup = 0.0f;

	// paramters
	float ambientFactor = 0.35f;
	float contrast = 2.0f;
	float brightness = 0.13f;
	float meshScale = 1.0f;
};

