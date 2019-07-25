#pragma once
#include <qstring.h>
#include <qvector3d.h>
#include <qimage.h>
#include <qopengltexture.h>
#include <qdebug.h>

class Material {
public:
	Material();
	Material(const Material & material);
	~Material();

	// material name
	void setMaterialName(const QString & materialName);
	const QString& getMaterialName() const;

	// ambient color
	void setAmbientColor(const QVector3D & ambientColor);
	const QVector3D& getAmbientColor() const;

	// diffuse color
	void setDiffuseColor(const QVector3D & diffuseColor);
	const QVector3D& getDiffuseColor() const;

	// specular color
	void setSpecularColor(const QVector3D & specularColor);
	const QVector3D& getSpecularColor() const;

	// shinnes
	void setShinnes(const float & shinnes);
	const float& getShinnes() const;

	// texture
	void setTexture(QOpenGLTexture * texture);
	void setTexture(const QImage & image);
	void setTexture(const QString & path);
	QOpenGLTexture * getTexture() const;

	// operation based on QOpenGLTexture;
	void bind();
	void bind(const uint index);
	bool create();
	bool createTexture();
	void destroy();
	bool isCreated();
	bool isTextureCreated();
	void setMinificationFilter(QOpenGLTexture::Filter filter);
	void setMagnificationFilter(QOpenGLTexture::Filter filter);
	void setWrapMode(QOpenGLTexture::WrapMode wrapMode);
	void release();

private:
	QString materialName;
	QVector3D ambientColor;
	QVector3D diffuseColor;
	QVector3D specularColor;
	float shinnes;
	QOpenGLTexture * texture;
};