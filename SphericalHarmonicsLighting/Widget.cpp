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
		QString log = objectShader.log();
		close();
	}
	if (!objectShader.addShaderFromSourceFile(QOpenGLShader::Fragment, "./Object.fsh")) {
		QString log = objectShader.log();
		close();
	}
	if (!objectShader.link()) {
		QString log = objectShader.log();
		close();
	}
	// skyboxShader
	if (!skyboxShader.addShaderFromSourceFile(QOpenGLShader::Vertex, "./Skybox.vsh")) {
		QString log = skyboxShader.log();
		close();
	}
	if (!skyboxShader.addShaderFromSourceFile(QOpenGLShader::Fragment, "./Skybox.fsh")) {
		QString log = skyboxShader.log();
		close();
	}
	if (!skyboxShader.link()) {
		QString log = skyboxShader.log();
		close();
	}
}

void Widget::loadObj(const QString& objPath, const QString& imgPath = "./defaultTexture.jpg") {
	QFile objFile(objPath);
	if (!objFile.exists()) return;

	QVector<QVector3D> verCoords;
	QVector<QVector2D> texCoords;
	QVector<QVector3D> normals;
	QVector<Vertex> vertices;
	QVector<GLuint> indices;

	objFile.open(QIODevice::ReadOnly);
	QTextStream input(&objFile);

	while (!input.atEnd()) {
		QString line = input.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "v") {
			verCoords << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
		} else if (list[0] == "vt") {
			texCoords << QVector2D(list[1].toFloat(), list[2].toFloat());
		} else if (list[0] == "vn") {
			normals << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
		} else if (list[0] == "f") {
			for (int i = 1; i <= 3; i++) {
				QStringList v = list[i].split("/");
				vertices.append(Vertex(verCoords[v[0].toLong() - 1], texCoords[v[1].toLong() - 1], normals[v[2].toLong() - 1]));
				indices.append(indices.size());
			}
		}
	}

	objFile.close();
	objects.append(new Object3D(vertices, indices, QImage(imgPath)));
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
	skybox = new Skybox(70, QImage("./Skybox01.jpg"));

	// add object groups
	// if you change the order/number of objects, remember to edit timerEvent
	// Add model
	groups.append(new Group3D());
	//this->loadObj("./human.obj", "./human.jpg");
	this->loadObj("./spaceship.obj");
	groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
	groups[groups.size() - 1]->translate(QVector3D(0.0, 0.0, 0.0));
	transformObjects.append(groups[groups.size() - 1]);

	// add stars
	groups.append(new Group3D());
	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 2; y++) {
			for (int z = 0; z < 2; z++) {
				this->loadObj("./estrellica.obj", "./texture1.jpg");
				float dis = 8.0;
				objects[objects.size() - 1]->translate(QVector3D(dis*(2.0*x - 1.0), dis*(2.0*y - 1.0), dis*(2.0*z - 1.0)));
				groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
			}
		}
	}
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
	camera->draw(&skyboxShader);
	skybox->draw(&skyboxShader, context()->functions());
	skyboxShader.release();

	// draw objects
	objectShader.bind();
	//objectShader.setAttributeArray();
	objectShader.setUniformValue("u_projectionMatrix", projectionMatrix);
	objectShader.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 1.0));
	objectShader.setUniformValue("u_lightPower", 1.0f);
	objectShader.setUniformValueArray("u_coef", (skybox->getSHCoefficient(0)).constData(), 16);
	camera->draw(&objectShader);
	for (int i = 0; i < transformObjects.size(); i++)
		transformObjects[i]->draw(&objectShader, context()->functions());
	objectShader.release();
}
