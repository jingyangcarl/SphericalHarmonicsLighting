#include "Object3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Object3D::Object3D() :
	scalar(1.0f) {
}

/*
Description:
	This function is a constructor with vertices reference, indices reference, and material;
	If material is not provided, then create one;
	If only texture is not provided, then create texture;
Input:
	@ const QVector<Vertex>& vertices: the vertex list of a given object;
	@ const QVector<GLuint>& indices: the index list of a given object;
	@ Material* material: a given material;
*/
Object3D::Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material) :
	scalar(1.0f) {

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

	if (!material->isCreated()) {
		// the mateiral is not created
		material = new Material;
		material->create();
		// this->material = material;
	}
	else if (!material->isTextureCreated()) {
		// texture is not created in the material
		material->createTexture();
		// this->material = material;
	}

	if (material->isCreated() && material->isTextureCreated()) {
		// material is created
		this->material = material;
	}
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
	this->material->destroy();
	this->material->create();

	// load texture
	if (this->material->isCreated()) {
		this->material->setTexture(image);
		return true;
	}
	else {
		qDebug() << "ERROR::Carl::Object3D::setTexture::image: texImage is not created yet;";
		return false;
	}
}

/*
Description:
	This function is used to set a given texture for the object;
Input:
	@ QOpenGLTexture * texture: a given texture;
Output:
	@ bool returnValue: whether the texture is set successfully;
*/
bool Object3D::setTexture(QOpenGLTexture * texture) {
	// load texture
	if (texture) {
		this->material->setTexture(texture);
		return true;
	}
	else {
		qDebug() << "ERROR::Carl::Object3D::setTexture::texture: texture is not created yet;";
		return false;
	}
}

/*
Description:
	This function is used to get current texture of the object;
Input:
	@ void parameter: void;
Output:
	@ QOpenGLTexture *: the current texture;
*/
QOpenGLTexture * Object3D::getTexture() const {
	return this->material->getTexture();
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
	material->bind(index);
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
	material->release();
}

