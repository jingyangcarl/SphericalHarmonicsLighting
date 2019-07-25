#include "Widget.h"

Widget::Widget(QWidget* parent) :
	QOpenGLWidget(parent) {
	camera = new Camera3D();
	camera->translate(QVector3D(0.0, 0.0, -35.0));
}

Widget::~Widget() {}

void Widget::initShaders() {
	// objectShader
	if (!objectShader.addShaderFromSourceFile(QOpenGLShader::Vertex, "./Object.vsh")) {
		qDebug() << objectShader.log();
		close();
	}
	if (!objectShader.addShaderFromSourceFile(QOpenGLShader::Fragment, "./Object.fsh")) {
		qDebug() << objectShader.log();
		close();
	}
	if (!objectShader.link()) {
		qDebug() << objectShader.log();
		close();
	}
	// skyboxShader
	if (!skyboxShader.addShaderFromSourceFile(QOpenGLShader::Vertex, "./Skybox.vsh")) {
		qDebug() << skyboxShader.log();
		close();
	}
	if (!skyboxShader.addShaderFromSourceFile(QOpenGLShader::Fragment, "./Skybox.fsh")) {
		qDebug() << skyboxShader.log();
		close();
	}
	if (!skyboxShader.link()) {
		qDebug() << skyboxShader.log();
		close();
	}
}

void Widget::initializeGL() {

	// Enable Keyboard
	setFocusPolicy(Qt::StrongFocus);

	// clear the screen with black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// initialize shaders
	initShaders();

	// create skybox
	skybox = new Skybox();

	// add object groups
	// if you change the order/number of objects, remember to edit timerEvent

	// add stars
	groups.append(new Group3D());
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				objects.append(new ObjectEngine3D());
				objects[objects.size() - 1]->loadObjectFromFile("./Resources/Model/Triangle Mesh/Cube/cube.obj");
				float dis = 8.0;
				objects[objects.size() - 1]->translate(QVector3D(dis*(2.0*x - 1.0), dis*(2.0*y - 1.0), dis*(2.0*z - 1.0)));
				objects[objects.size() - 1]->scale(0.5);
				groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
			}
		}
	}
	groups[groups.size() - 1]->translate(QVector3D(0.0, 0.0, 0.0));
	transformObjects.append(groups[groups.size() - 1]);

	// Add model
	groups.append(new Group3D());
	objects.append(new ObjectEngine3D());
	objects[objects.size() - 1]->loadObjectFromFile("./Resources/Model/Triangle Mesh/Intergalactic Spaceship/Intergalactic_Spaceship.obj");
	groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
	groups[groups.size() - 1]->translate(QVector3D(0.0, 0.0, 0.0));
	transformObjects.append(groups[groups.size() - 1]);

	// start timer
	timer.start(10, this);
}

void Widget::resizeGL(int width, int height) {
	float aspect = width / (float)height;
	projectionMatrix.setToIdentity();
	projectionMatrix.perspective(45, aspect, 0.01f, 500.0f);
}

void Widget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// draw skybox
	skyboxShader.bind();
	skyboxShader.setUniformValue("u_projectionMatrix", projectionMatrix);
	skyboxShader.setProperty("textureIndex", 0);
	camera->draw(&skyboxShader);
	skybox->draw(&skyboxShader, context()->functions());
	skyboxShader.release();

	// get skybox texture
	QOpenGLTexture *skyboxTexture = skybox->getTexture();
	skyboxTexture->bind(0);

	// draw objects
	objectShader.bind();
	objectShader.setProperty("textureIndex", 1);
	objectShader.setUniformValue("u_skyboxTexture", 0);
	objectShader.setUniformValueArray("u_coef", (skybox->getCoefficient()).constData(), 16);
	objectShader.setUniformValue("u_projectionMatrix", projectionMatrix);
	objectShader.setUniformValue("u_materialType", getMaterialType());
	objectShader.setUniformValue("u_ambientFactor", getAmbientFactor());
	objectShader.setUniformValue("u_contrast", getContrast());
	objectShader.setUniformValue("u_brightness", getBrightness());
	objectShader.setUniformValue("u_refractRatio", getRefractRatio());
	camera->draw(&objectShader);
	for (int i = 0; i < transformObjects.size(); i++)
		transformObjects[i]->draw(&objectShader, context()->functions());
	objectShader.release();
	skyboxTexture->release();
}