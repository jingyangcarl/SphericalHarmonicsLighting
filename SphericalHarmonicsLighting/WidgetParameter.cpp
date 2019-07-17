#include "Widget.h"

void Widget::setAmbientFactor(const float ambientFactor) {
	this->ambientFactor = ambientFactor;
}

const float Widget::getAmbientFactor() const {
	return this->ambientFactor;
}

void Widget::setContrast(const float contrast) {
	this->contrast = contrast;
}

const float Widget::getContrast() const {
	return this->contrast;
}

void Widget::setBrightness(const float brightness) {
	this->brightness = brightness;
}

const float Widget::getBrightness() const {
	return this->brightness;
}

void Widget::setMeshScale(const float meshScale) {
	objects[objects.size() - 1]->scale(meshScale/ this->meshScale);
	this->meshScale = meshScale;
}

const float Widget::getMeshScale() const {
	return this->meshScale;
}

void Widget::reloadMesh(const QString file) {
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
	objects[objects.size() - 1]->loadObjectFromFile(file);
	groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
	groups[groups.size() - 1]->translate(QVector3D(0.0, 0.0, 0.0));
	transformObjects.append(groups[groups.size() - 1]);
}
