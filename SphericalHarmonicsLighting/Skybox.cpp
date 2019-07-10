#include "Skybox.h"

Skybox::Skybox(float width, const QImage& texture) :
	skyboxIndex(0) {
	QVector<Vertex> vertices;
	vertices <<
		// front
		Vertex(QVector3D(-width, width, width), QVector2D(4.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(4.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<

		// left
		Vertex(QVector3D(width, width, width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<

		// top
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<

		// 
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<

		Vertex(QVector3D(-width, width, width), QVector2D(0.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(0.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 1.0, 0.0));

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
	loadCoefficients();

	Material* material = new Material;
	material->setAmbientColor(QVector3D(1.0, 1.0, 1.0));
	material->setDiffuseColor(QVector3D(1.0, 1.0, 1.0));
	material->setSpecularColor(QVector3D(1.0, 1.0, 1.0));
	material->setShinnes(96);
	material->setDiffuseMap(texture);

	skybox = new Object3D(vertices, indices, material);
}

Skybox::~Skybox() {
	delete skybox;
}

void Skybox::loadTextures() {
	textures <<
		QImage("./Skybox01.jpg").mirrored() <<
		QImage("./Skybox02.jpg").mirrored() <<
		QImage("./Skybox03.jpg").mirrored() <<
		QImage("./Skybox04.jpg").mirrored() <<
		QImage("./Skybox05.jpg").mirrored() <<
		QImage("./Skybox06.jpg").mirrored() <<
		QImage("./Skybox07.jpg").mirrored() <<
		QImage("./Skybox08.jpg").mirrored() <<
		QImage("./Skybox09.jpg").mirrored() <<
		QImage("./Skybox10.jpg").mirrored() <<
		QImage("./Skybox11.jpg").mirrored() <<
		QImage("./Skybox12.jpg").mirrored() <<
		QImage("./Skybox13.jpg").mirrored() <<
		QImage("./Skybox14.jpg").mirrored() <<
		QImage("./Skybox15.jpg").mirrored() <<
		QImage("./Skybox16.jpg").mirrored();
}

void Skybox::loadCoefficients() {

	for (int i = 1; i <= 16; i++) {
		QString filePath = "./coefficients" + QString::number(i) + ".txt";
		QFile file(filePath);
		if (file.open(QIODevice::ReadOnly)) {
			QTextStream input(&file);
			QVector<QVector3D> coefs;
			while (!input.atEnd()) {
				QString line = input.readLine();
				QStringList list = line.split('\t');
				QVector3D coef = { list[0].toFloat(), list[1].toFloat(), list[2].toFloat() };
				coefs << coef;
			}
			shCoefficients << coefs;
		}
		file.close();
	}

}

void Skybox::setTexture(QImage& texImage) {
	skybox->setTexture(texImage);
}

void Skybox::setTexture(int index) {
	skybox->setTexture(textures[index % textures.size()]);
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
	skybox->rotate(r);
}

void Skybox::translate(const QVector3D& t) {
	(void)t;
	skybox->translate(t);
}

void Skybox::scale(const float& s) {
	(void)s;
	skybox->scale(s);
}

void Skybox::setGlobalTransform(const QMatrix4x4& g) {
	(void)& g;
	skybox->setGlobalTransform(g);
}

void Skybox::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	skybox->draw(shaderProgram, functions);
}
