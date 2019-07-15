#pragma once
#include "Transformational.h"
#include <qvector3d.h>
#include <qopenglbuffer.h>
#include <qopengltexture.h>
#include <qquaternion.h>
#include <qmatrix4x4.h>
#include <qopenglshaderprogram.h>
#include <qopenglfunctions.h>
#include "Material.h"

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

	// initialization
	void init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material);
	bool setTexture(QImage& image);

	// interface implementation
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	// object buffer
	QOpenGLBuffer vertexBuffer;
	QOpenGLBuffer indexBuffer;
	QOpenGLTexture* texture;
	Material* material;

	// linear transformation
	QVector3D v_translation;
	QQuaternion v_rotation;
	float v_scale;
	QMatrix4x4 v_globalTransformation;

	// mMatrix
	QMatrix4x4 modelMatrix;
};

