#include "Skybox.h"

Skybox::Skybox(float width, const QImage& texture) :
	skyboxIndex(0) {
	QVector<Vertex> vertices;
	vertices <<
		// front
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<

		// right
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<

		// top
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<

		// back
		Vertex(QVector3D(width, width, -width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(4.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(4.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<

		// left
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(0.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(0.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<

		// bottom
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, 1.0, 0.0));

	QVector<GLuint> indices;
	indices << 0 << 1 << 2 << 2 << 1 << 3;
	for (int i = 0; i < 24; i += 4)
		indices <<
		i + 0 <<
		i + 2 <<
		i + 1 <<
		i + 2 <<
		i + 3 <<
		i + 1;

	loadTextures();

	Material* material = new Material;
	material->setAmbientColor(QVector3D(1.0, 1.0, 1.0));
	material->setDiffuseColor(QVector3D(1.0, 1.0, 1.0));
	material->setSpecularColor(QVector3D(1.0, 1.0, 1.0));
	material->setShinnes(96);
	material->setDiffuseMap(texture);

	skyboxObj = new Object3D(vertices, indices, material);
}

Skybox::~Skybox() {
	delete skyboxObj;
}

void Skybox::loadTextures() {

	QString dirPath = "./Resources/Skybox/";
	QDir directory(dirPath);
	if (!directory.exists()) {
		qDebug() << "Carl::Skybox::loadTextures error: no such directory";
	}

	QStringList dirList = directory.entryList(QDir::Dirs);

	for (int i = 2; i < 5; i++) {
		directory.cd(dirList[i]);
		QStringList jpgList = directory.entryList(QStringList() << "*.jpg");
		sampler = new SphericalHarmonicsSampler();
		sampler->loadImage(QString("posx"), QString(directory.path() + "/posx.jpg"));
		sampler->loadImage(QString("posy"), QString(directory.path() + "/posy.jpg"));
		sampler->loadImage(QString("posz"), QString(directory.path() + "/posz.jpg"));
		sampler->loadImage(QString("negx"), QString(directory.path() + "/negx.jpg"));
		sampler->loadImage(QString("negy"), QString(directory.path() + "/negy.jpg"));
		sampler->loadImage(QString("negz"), QString(directory.path() + "/negz.jpg"));
		textures << QImage(sampler->ImageComposition());
		sampler->RandomSampling(1000000);
		directory.cd("..");

		evaluator = new SphericalHarmonicsEvaluator(sampler->getSamples(), 3);
		evaluator->Evaluate();
		
		shCoefficients << QVector<QVector3D>(evaluator->getCoefficients());

		evaluator->~SphericalHarmonicsEvaluator();
		sampler->~SphericalHarmonicsSampler();
	}
}

void Skybox::setTexture(QImage& texImage) {
	skyboxObj->setTexture(texImage);
}

void Skybox::setTexture(int index) {
	skyboxObj->setTexture(textures[index % textures.size()]);
}

QVector<QVector3D>& Skybox::getSHCoefficient(int index) {
	// TODO: insert return statement here
	return shCoefficients[index];
}

int Skybox::loadNext() {
	skyboxIndex++;
	setTexture(abs(skyboxIndex));
	return abs(skyboxIndex) % textures.size();
}

int Skybox::loadPrevious() {
	skyboxIndex--;
	setTexture(abs(skyboxIndex));
	return abs(skyboxIndex) % textures.size();
}

void Skybox::rotate(const QQuaternion& r) {
	(void)r;
	skyboxObj->rotate(r);
}

void Skybox::translate(const QVector3D& t) {
	(void)t;
	skyboxObj->translate(t);
}

void Skybox::scale(const float& s) {
	(void)s;
	skyboxObj->scale(s);
}

void Skybox::setGlobalTransform(const QMatrix4x4& g) {
	(void)& g;
	skyboxObj->setGlobalTransform(g);
}

void Skybox::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	skyboxObj->draw(shaderProgram, functions);
}
