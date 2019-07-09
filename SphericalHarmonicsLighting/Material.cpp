#include "Material.h"

Material::Material() {
}

Material::~Material() {
}

void Material::setMaterialName(const QString & materialName) {
	this->materialName = materialName;
}

const QString & Material::getMaterialName() const {
	// TODO: insert return statement here
	return this->materialName;
}

void Material::setAmbientColor(const QVector3D & ambientColor) {
	this->ambientColor = ambientColor;
}

const QVector3D & Material::getAmbientColor() const {
	// TODO: insert return statement here
	return this->ambientColor;
}

void Material::setDiffuseColor(const QVector3D & diffuseColor) {
	this->diffuseColor = diffuseColor;
}

const QVector3D & Material::getDiffuseColor() const {
	// TODO: insert return statement here
	return this->diffuseColor;
}

void Material::setSpecularColor(const QVector3D & specularColor) {
	this->specularColor = specularColor;
}

const QVector3D & Material::getSpecularColor() const {
	// TODO: insert return statement here
	return this->specularColor;
}

void Material::setShinnes(const float & shinnes) {
	this->shinnes = shinnes;
}

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
