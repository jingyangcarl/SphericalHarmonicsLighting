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

class Widget :
	public QOpenGLWidget {
public:
	Widget(QWidget* parent = 0);
	~Widget();

	/*------------------WidgetParameter.cpp-------------------*/
	void setProjectionMatrix(const QMatrix4x4 & projectMatrix);
	const QMatrix4x4 & getProjectionMatrix() const;
	void setMeshScale(const float meshScale);
	const float getMeshScale() const;
	void setMaterialType(const float materialType);
	void setMaterialType(const QString & materialType);
	const float getMaterialType() const;
	void setAmbientFactor(const float ambientFactor);
	const float getAmbientFactor() const;
	void setContrast(const float contrast);
	const float getContrast() const;
	void setBrightness(const float brightness);
	const float getBrightness() const;
	void setRefractRatio(const float refractRatio);
	const float getRefractRatio() const;
	void reloadMesh(const QString & file);

protected:
	/*----------------Widget.cpp-------------------*/
	void initShaders();
protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	/*----------------WidgetCallback.cpp-------------------*/
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

	// pMatrix
	QMatrix4x4 projectionMatrix;

	// paramters
	float meshScale = 1.0f;
	float materialType = 0.0f;
	float ambientFactor = 0.35f;
	float contrast = 2.0f;
	float brightness = 0.13f;
	float refractRatio = 0.6f;

	// timer
	QBasicTimer timer;
	float angleObject = 0.0f;
	float angleGroup = 0.0f;

	// mouse
	QVector2D mousePosition;
};

