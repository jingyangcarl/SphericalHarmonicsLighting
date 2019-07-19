#pragma once
#include <qstring.h>
#include <qvector3d.h>
#include <qimage.h>
#include <qopengltexture.h>

class Material {
public:
	Material();
	~Material();

	void setMaterialName(const QString & materialName);
	const QString& getMaterialName() const;
	void setAmbientColor(const QVector3D & ambientColor);
	const QVector3D& getAmbientColor() const;
	void setDiffuseColor(const QVector3D & diffuseColor);
	const QVector3D& getDiffuseColor() const;
	void setSpecularColor(const QVector3D & specularColor);
	const QVector3D& getSpecularColor() const;
	void setShinnes(const float & shinnes);
	const float& getShinnes() const;
	void setDiffuseMap(const QImage & diffuseMap);
	void setDiffuseMap(const QString & diffuseMapPath);
	const QImage& getDiffuseMap() const;
	void setUsingDiffuseMap(bool usingDiffuseMap);
	const bool isUsingDiffuseMap() const;
	void setTexture(QOpenGLTexture * texture);
	QOpenGLTexture * getTexture() const;

private:
	QString materialName;
	QVector3D ambientColor;
	QVector3D diffuseColor;
	QVector3D specularColor;
	float shinnes;
	QImage diffuseMap;
	bool usingDiffuseMap = false;
	QOpenGLTexture * texture;
};