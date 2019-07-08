#include "Object3D.h"

Object3D::Object3D() :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
	v_scale = 1.0f;
}

Object3D::Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& texImage) :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
	v_scale = 1.0f;
	init(vertices, indices, texImage);
}

Object3D::~Object3D() {
	// release vertexBuffer
	if (vertexBuffer.isCreated())
		vertexBuffer.destroy();
	// release indexBuffer
	if (indexBuffer.isCreated())
		indexBuffer.destroy();
	// release texture
	if (texture != 0)
		if (texture->isCreated())
			texture->destroy();
}

void Object3D::init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& texImage) {
	// load vertex data
	vertexBuffer.create();
	vertexBuffer.bind();
	vertexBuffer.allocate(vertices.constData(), vertices.size() * sizeof(Vertex));
	vertexBuffer.release();

	// load index data
	indexBuffer.create();
	indexBuffer.bind();
	indexBuffer.allocate(indices.constData(), indices.size() * sizeof(GLuint));
	indexBuffer.release();

	// load texture
	texture = new QOpenGLTexture(texImage.mirrored());

	// set texture property
	texture->setMinificationFilter(QOpenGLTexture::Linear); // nearest filtering mode
	texture->setMagnificationFilter(QOpenGLTexture::Linear); // bilinear filtering mode
	texture->setWrapMode(QOpenGLTexture::Repeat); // wrap texture coordinates by repreating
}

void Object3D::setTexture(QImage& texImage) {
	texture->setData(texImage);
}

void Object3D::rotate(const QQuaternion& r) {
	v_rotation = r * v_rotation;
}

void Object3D::translate(const QVector3D& t) {
	v_translation += t;
}

void Object3D::scale(const float& s) {
	v_scale += s;
}

void Object3D::setGlobalTransform(const QMatrix4x4& g) {
	v_globalTransformation = g;
}

void Object3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	if (!vertexBuffer.isCreated() || !indexBuffer.isCreated()) return;

	// bind texture
	texture->bind(0);
	shaderProgram->setUniformValue("u_texture", 0);

	// set modelMatrix
	modelMatrix.setToIdentity();
	modelMatrix.translate(v_translation);
	modelMatrix.rotate(v_rotation);
	modelMatrix.scale(v_scale);
	modelMatrix = v_globalTransformation * modelMatrix;
	shaderProgram->setUniformValue("u_modelMatrix", modelMatrix);

	// bind vertexBuffer
	vertexBuffer.bind();

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
	indexBuffer.bind();

	// draw
	functions->glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

	// release
	vertexBuffer.release();
	indexBuffer.release();
	texture->release();
}

