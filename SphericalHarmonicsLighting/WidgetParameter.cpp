#include "Widget.h"

/*
Description:
	This function is used to set projection matrix for shader programs;
Input:
	@ const QMatrix4x4 & projectMatrix: a projection matrix;
Output:
	@ void returnValue: void;
*/
void Widget::setProjectionMatrix(const QMatrix4x4 & projectMatrix) {
	this->projectionMatrix = projectionMatrix;
}

/*
Description:
	This function is used to get projection matrix;
Input:
	@ void parameter: void;
Output:
	@ const QMatrix4x4 & returnValue: a projection matrix;
*/
const QMatrix4x4 & Widget::getProjectionMatrix() const {
	return this->projectionMatrix;
}

/*
Description:
	This function is used to set mesh scale;
	PS: since the mesh able to be reloaded is only the last object in the object list (QVector<ObjectEngine3D*>), since the function is designed to scale only the last object;
Input:
	@ const float ambientFactor: a mesh scale;
Output:
	@ void returnValue: void;
*/
void Widget::setMeshScale(const float meshScale) {
	objects[objects.size() - 1]->scale(meshScale / this->meshScale);
	this->meshScale = meshScale;
}

/*
Description:
	This function is used to get mesh scale;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a mesh scale;
*/
const float Widget::getMeshScale() const {
	return this->meshScale;
}

/*
Description:
	This function is used to set material type for shader programs;
Input:
	@ const float ambientFactor: a brightness;
Output:
	@ void returnValue: void;
*/
void Widget::setMaterialType(const float materialType) {
	this->materialType = materialType;
}

/*
Description:
	This function is used to set material type for shader programs by its name;
Input:
	@ const QString & materialType: a string indicates material type;
Output:
	@ void returnValue: void;
*/
void Widget::setMaterialType(const QString & materialType) {
	if (materialType == "Diffuse") this->materialType = 0.0f;
	else if (materialType == "Diffuse_SphericalHarmonic") this->materialType = 1.0f;
	else if (materialType == "Mirror") this->materialType = 2.0f;
	else if (materialType == "Glass") this->materialType = 3.0f;
	else this->materialType = 0.0f;
}

/*
Description:
	This function is used to get material type;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a material type;
*/
const float Widget::getMaterialType() const {
	return this->materialType;
}

/*
Description:
	This function is used to set ambient factor for shader programs;
Input:
	@ const float ambientFactor: an ambient factor;
Output:
	@ void returnValue: void;
*/
void Widget::setAmbientFactor(const float ambientFactor) {
	this->ambientFactor = ambientFactor;
}

/*
Description:
	This function is used to get ambient factor;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a ambient factor;
*/
const float Widget::getAmbientFactor() const {
	return this->ambientFactor;
}

/*
Description:
	This function is used to set contrast for shader programs;
Input:
	@ const float ambientFactor: a contrast;
Output:
	@ void returnValue: void;
*/
void Widget::setContrast(const float contrast) {
	this->contrast = contrast;
}

/*
Description:
	This function is used to get contrast;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a contrast;
*/
const float Widget::getContrast() const {
	return this->contrast;
}

/*
Description:
	This function is used to set brightness for shader programs;
Input:
	@ const float ambientFactor: a brightness;
Output:
	@ void returnValue: void;
*/
void Widget::setBrightness(const float brightness) {
	this->brightness = brightness;
}

/*
Description:
	This function is used to get brightness;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a brightness;
*/
const float Widget::getBrightness() const {
	return this->brightness;
}

/*
Description:
	This function is used to set refraction ratio for shader programs;
Input:
	@ const float ambientFactor: a refraction ratio;
Output:
	@ void returnValue: void;
*/
void Widget::setRefractRatio(const float refractRatio) {
	this->refractRatio = refractRatio;
}

/*
Description:
	This function is used to get refraction ratio;
Input:
	@ void parameter: void;
Output:
	@ const float returnValue: a refraction ratio;
*/
const float Widget::getRefractRatio() const {
	return this->refractRatio;
}

/*
Description:
	This function is used to reload the mesh by its filePath path;
Input:
	@ const QString & filePath: a filePath path;
Output:
	@ void returnValue: void;
*/
void Widget::reloadMesh(const QString & filePath) {
	if (groups.size() <= 0) {
		qDebug() << "ERROR::Carl::Widget::reloadMesh::groups: no group available;";
	}
	if (objects.size() <= 0) {
		qDebug() << "ERROR::Carl::Widget::reloadMesh::objects: no object available;";
	}

	transformObjects.pop_back();
	objects.pop_back();
	groups.pop_back();

	groups.append(new Group3D());
	objects.append(new ObjectEngine3D());
	objects[objects.size() - 1]->loadObjectFromFile(filePath);
	groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
	groups[groups.size() - 1]->translate(QVector3D(0.0, 0.0, 0.0));
	transformObjects.append(groups[groups.size() - 1]);
}
