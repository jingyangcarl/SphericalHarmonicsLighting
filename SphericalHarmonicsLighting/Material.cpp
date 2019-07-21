#include "Material.h"

Material::Material() : 
	texture(0) {
}

Material::Material(Material & material) {
	this->materialName = material.getMaterialName();
	this->ambientColor = material.getAmbientColor();
	this->diffuseColor = material.getDiffuseColor();
	this->specularColor = material.getSpecularColor();
	this->shinnes = material.getShinnes();
	this->diffuseMap = material.getDiffuseMap();
	this->usingDiffuseMap = material.isUsingDiffuseMap();
	if (material.getTexture()) {
		this->texture = material.getTexture();
	}
	else {
		this->texture = new QOpenGLTexture(QImage());
	}
}

Material::~Material() {
}

/*
Description:
	This function is used to set material name;
Input:
	@ const QString & materialName: material name;
Output:
	@ void returnValue: void;
*/
void Material::setMaterialName(const QString & materialName) {
	this->materialName = materialName;
}

/*
Description:
	This function is used to get material name;
Input:
	@ void parameter: void;
Output:
	@ const QString & returnValue: material name;
*/
const QString & Material::getMaterialName() const {
	// TODO: insert return statement here
	return this->materialName;
}

/*
Description:
	This function is used to set ambient color for the material;
Input:
	@ const QVector3D & ambientColor: ambient color;
Output:
	@ void returnValue: void;
*/
void Material::setAmbientColor(const QVector3D & ambientColor) {
	this->ambientColor = ambientColor;
}

/*
Description:
	This function is used to get ambient color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: ambient color;
*/
const QVector3D & Material::getAmbientColor() const {
	// TODO: insert return statement here
	return this->ambientColor;
}

/*
Description:
	This function is used to set diffuse color for the material;
Input:
	@ const QVector3D & diffuseColor: diffuse color;
Output:
	@ void returnValue: void;
*/
void Material::setDiffuseColor(const QVector3D & diffuseColor) {
	this->diffuseColor = diffuseColor;
}

/*
Description:
	This function is used to get diffuse color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: diffuse color;
*/
const QVector3D & Material::getDiffuseColor() const {
	// TODO: insert return statement here
	return this->diffuseColor;
}

/*
Description:
	This function is used to set specular color for the material;
Input:
	@ const QVector3D & specularColor: specular color;
Output:
	@ void returnValue: void;
*/
void Material::setSpecularColor(const QVector3D & specularColor) {
	this->specularColor = specularColor;
}

/*
Description:
	This function is used to get specular color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: specular color;
*/
const QVector3D & Material::getSpecularColor() const {
	// TODO: insert return statement here
	return this->specularColor;
}

/*
Description:
	This function is used to set shinnes for the material;
Input:
	@ const QVector3D & shinnes: shinnes;
Output:
	@ void returnValue: void;
*/
void Material::setShinnes(const float & shinnes) {
	this->shinnes = shinnes;
}

/*
Description:
	This function is used to get shinnes of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: shinnes;
*/
const float & Material::getShinnes() const {
	// TODO: insert return statement here
	return this->shinnes;
}

void Material::setDiffuseMap(const QImage & diffuseMap) {
	this->diffuseMap = diffuseMap;
	usingDiffuseMap = true;
}

void Material::setDiffuseMap(const QString & diffuseMapPath) {
	this->diffuseMap = QImage(diffuseMapPath);
	usingDiffuseMap = true;
}

const QImage & Material::getDiffuseMap() const {
	// TODO: insert return statement here
	return this->diffuseMap;
}

void Material::setUsingDiffuseMap(bool usingDiffuseMap) {
	this->usingDiffuseMap = usingDiffuseMap;
}

const bool Material::isUsingDiffuseMap() const {
	// TODO: insert return statement here
	return this->usingDiffuseMap;
}

void Material::setTexture(QOpenGLTexture * texture) {
	this->texture = texture;
}

void Material::setTexture(const QImage & image) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setTexture::texture: texture is not created yet;";
		return;
	}
	this->texture->setData(image);
}

QOpenGLTexture * Material::getTexture() const {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::getMaterial::texture: texture is not created yet;";
		return 0;
	}
	return this->texture;
}

bool Material::create() {
	if (!this) return false;
	this->setAmbientColor(QVector3D(1.0, 1.0, 1.0));
	this->setDiffuseColor(QVector3D(1.0, 1.0, 1.0));
	this->setSpecularColor(QVector3D(1.0, 1.0, 1.0));
	this->setShinnes(100);
	this->createTexture();
	return true;
}

bool Material::createTexture() {
	QImage image(1, 1, QImage::Format_RGB32);
	image.fill(Qt::white);
	this->texture = new QOpenGLTexture(image);
	this->setMinificationFilter(QOpenGLTexture::Linear); // nearest filtering mode
	this->setMagnificationFilter(QOpenGLTexture::Linear); // bilinear filtering mode
	this->setWrapMode(QOpenGLTexture::Repeat); // wrap texture coordinates by repreating
	return true;
}

bool Material::isCreated() {
	if (!this) return false;
	return true;
}

bool Material::isTextureCreated() {
	if (!this->texture) return false;
	return true;
}

void Material::bind() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::bind::texture: texture is not created yet;";
		return;
	}
	this->texture->bind();
}

void Material::bind(const int index) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::bind::texture: texture is not created yet;";
		return;
	}
	this->texture->bind(index);
}

void Material::setMinificationFilter(QOpenGLTexture::Filter filter) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setMinificationFilter::texture: texture is not created yet;";
		return;
	}
	this->texture->setMinificationFilter(filter);
}

void Material::setMagnificationFilter(QOpenGLTexture::Filter filter) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setMagnificationFilter::texture: texture is not created yet;";
		return;
	}
	this->texture->setMagnificationFilter(filter);
}

void Material::setWrapMode(QOpenGLTexture::WrapMode wrapMode) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setWrapMode::texture: texture is not created yet;";
		return;
	}
	this->texture->setWrapMode(wrapMode);
}

void Material::release() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::release::texture: texture is not created yet;";
		return;
	}
	this->texture->release();
}

void Material::destroy() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::destroy::texture: texture is not created yet;";
		return;
	}
	this->texture->destroy();
}
