#include "Object3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Object3D::Object3D() :
	texture(0), scalar(1.0f) {
}

/*
Description:
	This function is a constructor with vertices reference, indices reference, and material;
Input:
	@ const QVector<Vertex>& vertices: the vertex list of a given object;
	@ const QVector<GLuint>& indices: the index list of a given object;
	@ Material* material: a given material;
*/
Object3D::Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material) :
	texture(0), scalar(1.0f) {

	// load vertex data
	vertexBuffer = new QOpenGLBuffer();
	vertexBuffer->create();
	vertexBuffer->bind();
	vertexBuffer->allocate(vertices.constData(), vertices.size() * sizeof(Vertex));
	vertexBuffer->release();

	// load index data
	indexBuffer = new QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
	indexBuffer->create();
	indexBuffer->bind();
	indexBuffer->allocate(indices.constData(), indices.size() * sizeof(GLuint));
	indexBuffer->release();

	// load material
	this->material = material;

	// load texture
	if (material) {
		this->texture = new QOpenGLTexture((material->getDiffuseMap()).mirrored());
	} 
	else {
		QImage image(1, 1, QImage::Format_RGB32);
		image.fill(Qt::white);
		this->texture = new QOpenGLTexture(image);
	}

	// set texture property
	this->texture->setMinificationFilter(QOpenGLTexture::Linear); // nearest filtering mode
	this->texture->setMagnificationFilter(QOpenGLTexture::Linear); // bilinear filtering mode
	this->texture->setWrapMode(QOpenGLTexture::Repeat); // wrap texture coordinates by repreating
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Object3D::~Object3D() {
	delete vertexBuffer;
	delete indexBuffer;
	delete texture;
	delete material;
}

/*
Description:
	This function is used to set a new texture for the given object
Input:
	@ const QImage& image: an image used as the object texture;
Output:
	@ bool returnValue: whether the texture is successfully set or not;
*/
bool Object3D::setTexture(const QImage& image) {
	// clear previous texture
	this->texture->destroy();
	this->texture->create();

	// load texture
	if (this->texture->isCreated()) {
		this->texture->setData(image);
		return true;
	}
	else {
		qDebug() << "ERROR::Carl::Object3D::setTexture::texture: texture is not created successfully";
		return false;
	}
}

void Object3D::setTexture(QOpenGLTexture * texture) {
	this->texture = texture;
}

QOpenGLTexture * Object3D::getTexture() const {
	return this->texture;
}

void Object3D::setVerCoordCount(const int verCoordCount) {
	this->verCoordCount = verCoordCount;
}

const int Object3D::getVerCoordCount() const {
	return this->verCoordCount;
}

void Object3D::setTexCoordCount(const int texCoordCount) {
	this->texCoordCount = texCoordCount;
}

const int Object3D::getTexCoordCount() const {
	return this->texCoordCount;
}

void Object3D::setNormalCount(const int normalCount) {
	this->normalCount = normalCount;
}

const int Object3D::getNormalCount() const {
	return this->normalCount;
}

void Object3D::setFaceCount(const int faceCount) {
	this->faceCount = faceCount;
}

const int Object3D::getFaceCount() const {
	return this->faceCount;
}

/*
Description:
	This function is used to rotate the object;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Object3D::rotate(const QQuaternion& r) {
	rotation = r * rotation;
}

/*
Description:
	This function is used to translate the object;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Object3D::translate(const QVector3D& t) {
	translation += t;
}

/*
Description:
	This function is used to scale the object;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Object3D::scale(const float& s) {
	scalar *= s;
}

/*
Description:
	This function is used to set the global transform for the object;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Object3D::setGlobalTransform(const QMatrix4x4& g) {
	globalTransformation = g;
}

/*
Description:
	This function is used to set parameters for the vertex shader, fragment shader and etc. and draw the object;
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Object3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	if (!vertexBuffer->isCreated()) {
		qDebug() << "ERROR::Carl::Object3D::draw:vertexBuffer: the vertex buffer is not created successfully;";
		return;
	}
	if (!indexBuffer->isCreated()) {
		qDebug() << "ERROR::Carl::Object3D::draw:indexBuffer: the skyboxIndex buffer is not created successfully;";
		return;
	}

	// bind texture
	auto index = shaderProgram->property("textureIndex").toInt();
	texture->bind(index);
	shaderProgram->setUniformValue("u_texture", index);

	// set modelMatrix
	modelMatrix.setToIdentity();
	modelMatrix.translate(translation);
	modelMatrix.rotate(rotation);
	modelMatrix.scale(scalar);
	modelMatrix = globalTransformation * modelMatrix;
	shaderProgram->setUniformValue("u_modelMatrix", modelMatrix);

	// bind vertexBuffer
	vertexBuffer->bind();

	int offset = 0;

	int verLoc = shaderProgram->attributeLocation("a_position");
	shaderProgram->enableAttributeArray(verLoc);
	shaderProgram->setAttributeBuffer(verLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	offset += sizeof(QVector3D);

	int texLoc = shaderProgram->attributeLocation("a_texcoord");
	shaderProgram->enableAttributeArray(texLoc);
	shaderProgram->setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(Vertex));

	offset += sizeof(QVector2D);

	int normLoc = shaderProgram->attributeLocation("a_normal");
	shaderProgram->enableAttributeArray(normLoc);
	shaderProgram->setAttributeBuffer(normLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	// bind indexBuffer
	indexBuffer->bind();

	// draw
	functions->glDrawElements(GL_TRIANGLES, indexBuffer->size(), GL_UNSIGNED_INT, 0);

	// release
	vertexBuffer->release();
	indexBuffer->release();
	texture->release();
}

