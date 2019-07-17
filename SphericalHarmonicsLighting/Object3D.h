#pragma once
#include "Transformational.h"
#include "Material.h"

#include <qvector3d.h>
#include <qopenglbuffer.h>
#include <qopengltexture.h>
#include <qopenglshaderprogram.h>
#include <qopenglfunctions.h>
#include <qquaternion.h>
#include <qmatrix4x4.h>

struct Vertex {
	Vertex() {};
	Vertex(QVector3D vecCoord, QVector2D texCoord, QVector3D normal) :
		vecCoord(vecCoord), texCoord(texCoord), normal(normal) {};

	QVector3D vecCoord;
	QVector2D texCoord;
	QVector3D normal;
};

class Object3D :
	public Transformational {
public:
	// constructor
	Object3D();
	Object3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material);
	~Object3D();

	// setter and getter
	bool setTexture(const QImage& image);
	void setVerCoordCount(const int verCoordCount);
	const int getVerCoordCount() const;
	void setTexCoordCount(const int texCoordCount);
	const int getTexCoordCount() const;
	void setNormalCount(const int normalCount);
	const int getNormalCount() const;
	void setFaceCount(const int faceCount);
	const int getFaceCount() const;

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	// object buffer
	QOpenGLBuffer* vertexBuffer = 0;
	QOpenGLBuffer* indexBuffer = 0;
	QOpenGLTexture* texture = 0;
	Material* material = 0;

	// linear transformation
	QVector3D translation;
	QQuaternion rotation;
	float scalar;
	QMatrix4x4 globalTransformation;

	// mMatrix
	QMatrix4x4 modelMatrix;

	// data
	int verCoordCount = 0;
	int texCoordCount = 0;
	int normalCount = 0;
	int faceCount = 0;
};

