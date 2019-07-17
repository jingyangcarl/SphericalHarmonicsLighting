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
