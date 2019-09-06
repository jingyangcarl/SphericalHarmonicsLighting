#include "Material.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Material::Material() : 
	texture(0) {
}

/*
Description:
	This function is a copy construction
Input:
	@ const Material & material: a given material;
*/
Material::Material(const Material & material) {
	this->materialName = material.getMaterialName();
	this->ambientColor = material.getAmbientColor();
	this->diffuseColor = material.getDiffuseColor();
	this->specularColor = material.getSpecularColor();
	this->shinnes = material.getShinnes();
	if (material.getTexture()) {
		this->texture = material.getTexture();
	}
	else {
		this->texture = new QOpenGLTexture(QImage());
	}
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Material::~Material() {
	delete &materialName;
	delete &ambientColor;
	delete &diffuseColor;
	delete &specularColor;
	delete &shinnes;
	delete texture;
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

/*
Description:
	This function is used to set texture for material;
Input:
	@ QOpenGLTexture * texture: a given texture;
Output:
	@ void returnValue: void;
*/
void Material::setTexture(QOpenGLTexture * texture) {
	this->texture = texture;
}

/*
Description:
	This function is used to set texture for material using an image;
Input:
	@ const QImage & image: a given texture image;
Output:
	@ void returnValue: void;
*/
void Material::setTexture(const QImage & image) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setTexture::texture: texture is not created yet;";
		return;
	}
	this->texture->destroy();
	this->texture->create();
	this->texture->setData(image);
}

/*
Description:
	This function is used to set texture for material using an image from path;
Input:
	@ const QString & texPath: a given texture image path;
Output:
	@ void returnValue: void;
*/
void Material::setTexture(const QString & path) {
	QImage image(path);
	if (!image.isNull()) {
		setTexture(image.mirrored());
	}
	else {
		qDebug() << "ERROR::Carl::Material::setTexture::image: there is no such a path;";
	}
}

/*
Description:
	This function is used to get texture of the material;
Input:
	@ void parameter: void;
Output:
	@ QOpenGLTexture *: a texture;
*/
QOpenGLTexture * Material::getTexture() const {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::getMaterial::texture: texture is not created yet;";
		return 0;
	}
	return this->texture;
}

/*
Description:	
	This function is used to bind texture, which calls QOpenGLTexture::bind();
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Material::bind() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::bind::texture: texture is not created yet;";
		return;
	}
	this->texture->bind();
}

/*
Description:
	This function is used to bind texture, which calls QOpenGLTexture::bind(uint);
Input:
	@ cont uint index: bindding index;
Output:
	@ void returnValue: void;
*/
void Material::bind(const uint index) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::bind::texture: texture is not created yet;";
		return;
	}
	this->texture->bind(index);
}

/*
Description:
	This function is used to create a default material;
Input:
	@ void parameter: void;
Output:
	@ bool returnValue: whether the material is successfully created;
*/
bool Material::create() {
	if (!this) return false;
	this->setAmbientColor(QVector3D(1.0, 1.0, 1.0));
	this->setDiffuseColor(QVector3D(1.0, 1.0, 1.0));
	this->setSpecularColor(QVector3D(1.0, 1.0, 1.0));
	this->setShinnes(100);
	if (!this->createTexture()) {
		qDebug() << "ERROR::Carl::Material::create::createTexture: texture is not created successfully;";
		return false;
	}
	return true;
}

/*
Description:	
	This function is used to create a default texture;
Input:
	@ void parameter: void;
Output:
	@ bool returnValue: whether the texture is successfully created;
*/
bool Material::createTexture() {
	QImage image(1, 1, QImage::Format_RGB32);
	image.fill(Qt::white);
	this->texture = new QOpenGLTexture(image);
	this->setMinificationFilter(QOpenGLTexture::Linear); // nearest filtering mode
	this->setMagnificationFilter(QOpenGLTexture::Linear); // bilinear filtering mode
	this->setWrapMode(QOpenGLTexture::Repeat); // wrap texture coordinates by repreating
	return true;
}

/*
Description:
	This function is used to destroy the material, which calls QOpenGLTexture::destroy();
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Material::destroy() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::destroy::texture: texture is not created yet;";
		return;
	}
	this->texture->destroy();
}

/*
Description:
	This function is used to tell if the material is created or not;
Input:
	@ void parameter: void;
Output:
	@ bool returnValue: whether the material is created or not;
*/
bool Material::isCreated() {
	if (!this) return false;
	return true;
}

/*
Description:
	This function is used to tell if the texture is created or not;
Input:
	@ void parameter: void;
Output:
	@ bool returnValue: whether the texture is created or not;
*/
bool Material::isTextureCreated() {
	if (!this->texture) return false;
	return true;
}

/*
Description:	
	This function is used to set minification filter for mateiral, which calls QOpenGLTexture::setMinificationFilter(QOpenGLTexture::Filter);
Input:
	@ QOpenGLTexture::Filter filter: a given filter;
Output:
	@ void returnValue: void;
*/
void Material::setMinificationFilter(QOpenGLTexture::Filter filter) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setMinificationFilter::texture: texture is not created yet;";
		return;
	}
	this->texture->setMinificationFilter(filter);
}

/*
Description:
	This function is used to set magnification filter for mateiral, which calls QOpenGLTexture::setMagnificationFilter(QOpenGLTexture::Filter);
Input:
	@ QOpenGLTexture::Filter filter: a given filter;
Output:
	@ void returnValue: void;
*/
void Material::setMagnificationFilter(QOpenGLTexture::Filter filter) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setMagnificationFilter::texture: texture is not created yet;";
		return;
	}
	this->texture->setMagnificationFilter(filter);
}

/*
Description:	
	This function is used to set wrap mode for material, which calls QOpenGLTexture::setWrapMode(QOpenGLTexture::WrapMode);
Input:
	@ QOpenGLTexture::WrapMode: a given wrap mode
Output:
	@ void returnValue: void;
*/
void Material::setWrapMode(QOpenGLTexture::WrapMode wrapMode) {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::setWrapMode::texture: texture is not created yet;";
		return;
	}
	this->texture->setWrapMode(wrapMode);
}

/*
Description:
	This function is used to release the material;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Material::release() {
	if (!this->texture) {
		qDebug() << "ERROR::Carl::Material::release::texture: texture is not created yet;";
		return;
	}
	materialName = QString();
	ambientColor = QVector3D();
	diffuseColor = QVector3D();
	specularColor = QVector3D();
	shinnes = 0.0;
	this->texture->release();
}