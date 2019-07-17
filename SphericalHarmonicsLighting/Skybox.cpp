#include "Skybox.h"

/*
Description:
	This function is a constructor;
Input:
	@ const float width: width of the skybox, where the default value is 70.0f;
*/
Skybox::Skybox(const float& width) :
	index(0) {

	QVector<Vertex> vertices;
	QVector<GLuint> indices;
	Material material;

	// load data
	bool isCube = loadCube(width, vertices, indices);
	bool isTexture = loadTextures();
	bool isMaterial = loadMaterial(material);

	// create skybox
	if (isCube && isTexture && isMaterial) {
		object = new Object3D(vertices, indices, &material);
	}
	else {
		if (!isCube) {
			qDebug() << "ERROR::Carl::Skybox::Skybox::isCube: cube initialization failed;";
		}
		else if (!isTexture) {
			qDebug() << "ERROR::Carl::Skybox::skybox::isTexture: texture initialization failed;";
		}
		else if (!isMaterial) {
			qDebug() << "ERROR::Carl::Skybox::skybox::isMaterial: material initialization failed;";
		}
	}
}

/*
Description:
	This function is a destructor;
Input:
	@ void paramter: void;
*/
Skybox::~Skybox() {
	delete object;
	qDeleteAll(textures);
	qDeleteAll(coefficients);
	delete currentTex;
	delete currentCoef;
	delete sampler;
	delete evaluator;
}

/*
Description:
	This function is used to load graphics data for skybox, including vertex data and index data;
Input:
	@ int width: the width of the cube;
	@ QVector<Vertex>& desVertices: a container reference for cube vertices;
	@ QVector<GLuint>& desIndices: a container reference for cube indices;
Output:
	@ QVector<Vertex>& desVertices: the container reference with cube vertices loaded;
	@ QVector<GLuint>& desIndices: the container reference with cube indices loaded;
	@ void returnValue: void;
*/
bool Skybox::loadCube(int width, QVector<Vertex>& desVertices, QVector<GLuint>& desIndices) {

	// detection
	if (width <= 0) {
		qDebug() << "ERROR::Carl::Skybox::loadCube::width: invalid width for skybox";
		exit(-1);
	}

	// initialization
	desVertices.clear();
	desIndices.clear();

	// load vertices
	desVertices <<
		// front face
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<

		// right face
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<

		// top face
		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<

		// back face
		Vertex(QVector3D(width, width, -width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(4.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(4.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<

		// left face
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(0.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(0.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<

		// bottom face
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, 1.0, 0.0));

	// load indices
	desIndices << 0 << 1 << 2 << 2 << 1 << 3;
	for (int i = 0; i < 24; i += 4)
		desIndices <<
		i + 0 <<
		i + 2 <<
		i + 1 <<
		i + 2 <<
		i + 3 <<
		i + 1;

	if (!desVertices.isEmpty() && !desIndices.isEmpty()) {
		return true;
	}
	else {
		if (desVertices.empty()) {
			qDebug() << "ERROR::Carl::Skybox::loadCube::desVertices: vertices are not loaded;";
			return false;
		}
		else if (desIndices.empty()) {
			qDebug() << "ERROR::Carl::Skybox::loadCube::desIndices: indices are not loaded;";
			return false;
		}
		else {
			qDebug() << "ERROR::Carl::Skybox::loadCube::unknown: unknown;";
			return false;
		}
	}
}

bool Skybox::loadTextures() {

	// init
	QString dirPath = "./Resources/Skybox/";
	QDir directory(dirPath);
	if (!directory.exists()) {
		qDebug() << "ERROR::Carl::Skybox::loadTextures::dirPath: no such directory";
	}

	// load
	QStringList dirList = directory.entryList(QDir::Dirs);
	dirList.removeFirst(); // remove ./
	dirList.removeFirst(); // remove ../
	for (int i = 1; i < 17; i++) {
		directory.cd(dirList[i]);
		QStringList jpgList = directory.entryList(QStringList() << "*.jpg");
		sampler = new SphericalHarmonicsSampler();
		sampler->loadImage(QString("posx"), QString(directory.path() + "/posx.jpg"));
		sampler->loadImage(QString("posy"), QString(directory.path() + "/posy.jpg"));
		sampler->loadImage(QString("posz"), QString(directory.path() + "/posz.jpg"));
		sampler->loadImage(QString("negx"), QString(directory.path() + "/negx.jpg"));
		sampler->loadImage(QString("negy"), QString(directory.path() + "/negy.jpg"));
		sampler->loadImage(QString("negz"), QString(directory.path() + "/negz.jpg"));
		textures << new QImage(sampler->ImageExpand());

		// sampling
		sampler->RandomSampling(10000);
		directory.cd("..");

		// calculate coefficients
		evaluator = new SphericalHarmonicsEvaluator(sampler->getSamples(), 3);
		evaluator->Evaluate();
		
		// load coefficients
		coefficients << new QVector<QVector3D>(evaluator->getCoefficients());

		// release
		evaluator->~SphericalHarmonicsEvaluator();
		sampler->~SphericalHarmonicsSampler();
	}

	if (coefficients.size() > 0) {
		currentCoef = new auto(*(*coefficients.begin()));
		return true;
	}
	else {
		qDebug() << "ERROR::Carl::Skybox::loadTextures::coefficients: no available coefficients;";
		return false;
	}
}

/*
Description:
	This function is used to load material for the skybox;
Input:
	@ Material& material: the reference to a unloaded material;
Output:
	@ Material& material: the loaded material;
*/
bool Skybox::loadMaterial(Material& material) {
	if (textures.size() > 0) {
		material.setAmbientColor(QVector3D(1.0, 1.0, 1.0));
		material.setDiffuseColor(QVector3D(1.0, 1.0, 1.0));
		material.setSpecularColor(QVector3D(1.0, 1.0, 1.0));
		material.setShinnes(100);
		material.setDiffuseMap((*(*textures.begin())).mirrored());
		return true;
	}
	else {
		qDebug() << "ERROR::Carl::Skybox::loadMaterial::textures: no available textures;";
		return false;
	}
}

/*
Description:
	This function is used to change the texture of the skybox, which calls Object3D::setTexture(QImage &) for texture setting;
Input:
	@ QImage& image: an image used as the skybox texture, which should be an expanded image of a 6-sided cube;
Output:
	@ bool returnValue: whether the texture is successfully set or not;
*/
bool Skybox::setTexture(QImage& image) {
	if (object->setTexture(image)) {
		qDebug() << "ERROR::Carl::Skybox::setTexture::object: texture is not load loaded successfully;";
		return false;
	}
	return true;
}

/*
Description:
	This funciton is an overloaded function, which sets the texture getting from the loaded texture list by its index;
Input:
	@ int index: an image index refer to the texture image in the texture list;
Output:
	@ bool returnValue: whether the texture is successfuly set or not;
*/
bool Skybox::setTexture(int index) {
	int i = index % textures.size();
	if (!object->setTexture(*textures[i])) {
		qDebug() << "ERROR::Carl::Skybox::setTexture::object: texture is not loaded successfully;";
		return false;
	}
	return true;
}

/*
Description:
	This function is used to get texture from texture list by its index;
Input:
	@ const int index: an image index refer to the texture image in the texture list;
Output:
	@ QImage& returnValue: the texture image;
*/
QImage& Skybox::getTexture(const int index) const {
	if (index >= textures.size() || index < 0) {
		qDebug() << "ERROR::Carl::Skybox::getTexture::index: invalid texture index;";
		exit(-1);
	}
	return *textures[index];
}

/*
Description:
	This function is used to get spherical harmonic (SH) lighting coefficients from coefficients list by its current status
Input:
	@ void paramter: void;
Output:
	QVector<QVector3D>& returnValue: the current spherical harmonic (SH) lighting coefficients;
*/
QVector<QVector3D>& Skybox::getCoefficient() const {
	if (!currentCoef) {
		qDebug() << "ERROR::Carl::Skybox::getCoefficient::currentCoef: currentCoef is not initialized;";
		exit(-1);
	}
	return *currentCoef;
}

/*
Description:
	This function is used to get spherical harmonic (SH) lighting coefficients from coefficients list by its index;
Input:
	@ const int index: an coefficient index refer to the spherical harmonic (SH) lighting coefficients in the coefficients list;
Output:
	@ QVector<QVector3D>& returnValue: the spherical harmonic (SH) lighting coefficients;
*/
QVector<QVector3D>& Skybox::getCoefficient(const int index) const {
	if (index >= coefficients.size() || index < 0) {
		qDebug() << "ERROR::Carl::Skybox::getCoefficient::index: invalid coefficient index;";
		exit(-1);
	}
	return *coefficients[index];
}

/*
Description:
	This function is used to load next texture and spherical harmonic lighting coefficients;
Input:
	@ void paramter: void;
Output:
	@ void returnValue: void;
*/
void Skybox::loadNext() {
	// change current status
	auto i = (abs(++index) % textures.size());
	// set current texture
	setTexture(i);
	// set current coefficients;
	if (currentCoef) currentCoef->~QVector();
	if (i >= coefficients.size() || i < 0) {
		qDebug() << "ERROR::Carl::Skybox::loadNext::index: invalid coefficient index;";
		exit(-1);
	}
	currentCoef = new auto(*coefficients[i]);
	return;
}

/*
Description:
	This function is used to load previous skybox texture and spherical harmonic lighting coefficients;
Input:
	@ void paramter: void;
Output:
	@ void returnValue: void;
*/
void Skybox::loadPrev() {
	// change current status
	auto i = (abs(--index) % textures.size());
	// set current texture
	setTexture(i);
	// set current coefficients;
	if (currentCoef) currentCoef->~QVector();
	if (i >= coefficients.size() || i < 0) {
		qDebug() << "ERROR::Carl::Skybox::loadPrev::index: invalid coefficient index;";
		exit(-1);
	}
	currentCoef = new auto(*coefficients[i]);
	return;
}

/*
Description:
	This function is used to rotate the skybox, which calls Object3D::rotate(const QQuaternion&) for object rotation;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Skybox::rotate(const QQuaternion& r) {
	object->rotate(r);
}

/*
Description:
	This function is used to translate the skybox, which calls Object3D::translate(const QVector3D&) for object translation;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Skybox::translate(const QVector3D& t) {
	object->translate(t);
}

/*
Description:
	This function is used to scale the skybox, which calls Object3D::scale(const float&) for object scaling;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Skybox::scale(const float& s) {
	object->scale(s);
}

/*
Description:
	This function is used to set the global transform for the skybox, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Skybox::setGlobalTransform(const QMatrix4x4& g) {
	object->setGlobalTransform(g);
}

/*
Description:
	This function is used to draw the skybox, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Skybox::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	object->draw(shaderProgram, functions);
}
