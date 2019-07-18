#include "Material.h"

Material::Material() {
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
