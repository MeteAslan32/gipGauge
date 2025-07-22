/*
 * gipEmptyPlugin.cpp
 *
 *  Created on: Mar 11, 2023
 *      Author: Noyan Culum
 *      Created by: kayra
 */

#include "gipGauge.h"


gipGauge::gipGauge() {
}

gipGauge::~gipGauge() {
}

void gipGauge::setup(GaugeType type) {
	this->type = type;
	min = 0;
	max = 100;
	value = min;
	width = 400;
	height = 400;
	startangle = 0.0f;

    if (type != DEFAULT && type != ALT1 && type != ALT2) {
        type = DEFAULT;
    }

	if(type == DEFAULT){
		endangle = 240.0f;
		imageoffset = -75; // add to the angle so the angle shows 0 at min
	}

	else if(type == ALT1){
		endangle = 240.0f;
		imageoffset = -75; // add to the angle so the angle shows 0 at min
	}

	else if(type == ALT2){
		endangle = 280.0f;
		imageoffset = -272; // add to the angle so the angle shows 0 at min
	}

	shownangle = angle + imageoffset;
	textfont.loadFont("FreeSans.ttf", 20);

	setText(gToStr(value));
}

void gipGauge::update(float deltaTime) {
    if (isanimating) {
        if (value < targetvalue) {
            value += animationspeed * deltaTime;
            if (value > targetvalue) {
                value = targetvalue;
                isanimating = false;
            }
        }
        else if (value > targetvalue) {
            value -= animationspeed * deltaTime;
            if (value < targetvalue) {
                value = targetvalue;
                isanimating = false;
            }
        }
        else {
            isanimating = false;
        }
        setAngle();
    }
}

void gipGauge::draw() {
	renderer->enableAlphaBlending();
	renderer->setColor(255, 255, 255);
	gaugebg->draw(bgx, bgy, width, height);

	if(type == DEFAULT){
		renderer->setColor(0, 0, 0);
			textfont.drawText(gToStr(min), mintextx , mintexty);
			textfont.drawText(gToStr(max), maxtextx , maxtexty);

			renderer->setColor(255, 255, 255);
			//gaugestick->draw(bgx + width * 22/100, bgy + height * 40/100, width/3, height/3, shownangle);
			//gaugestick->draw(x, y, w, h, pivotx, pivoty, rotate)
			gaugestick->draw(stickx, sticky, width/3, height/3, width * 53/200, height * 53/200,  shownangle);

			renderer->setColor(0, 0, 0);
			gDrawRectangle(rectanglex, rectangley, rectanglew, rectangleh, false);

			textfont.drawText(gToStr(value), rectanglex , rectangley + rectangleh * 70/100);
	}

	if(type == ALT1){
		renderer->setColor(0, 0, 0);
			textfont.drawText(gToStr(min), mintextx , mintexty + height * 12/100);
			textfont.drawText(gToStr(max), maxtextx , maxtexty + height * 12/100);

			renderer->setColor(255, 255, 255);
			//gaugestick->draw(bgx + width * 22/100, bgy + height * 40/100, width/3, height/3, shownangle);
			//gaugestick->draw(x, y, w, h, pivotx, pivoty, rotate)
			gaugestick->draw(stickx, sticky, width/3, height/3, width * 53/200, height * 53/200,  shownangle);

			renderer->setColor(0, 0, 0);
			gDrawRectangle(rectanglex, rectangley, rectanglew, rectangleh, false);

			textfont.drawText(gToStr(value), rectanglex , rectangley + rectangleh * 70/100);
	}

	if(type == ALT2){
		renderer->setColor(0, 0, 0);
			textfont.drawText(gToStr(min), mintextx , mintexty);
			textfont.drawText(gToStr(max), maxtextx , maxtexty);

			renderer->setColor(255, 255, 255);
			//gaugestick->draw(bgx + width * 22/100, bgy + height * 40/100, width/3, height/3, shownangle);
			//gaugestick->draw(x, y, w, h, pivotx, pivoty, rotate)
			gaugestick->draw(stickx, sticky, width/3, height/3, width * 12/100 , height * 12/100,  shownangle);

			renderer->setColor(0, 0, 0);
			gDrawRectangle(rectanglex, rectangley, rectanglew, rectangleh, false);

			textfont.drawText(gToStr(value), rectanglex + rectanglew * 19/100 , rectangley + rectangleh * 68/100);
	}

	renderer->disableAlphaBlending();
}

void gipGauge::setMin(int min) {
	this->min = min;
}

void gipGauge::setMax(int max) {
	this->max = max;
}

void gipGauge::setValue(int value) {
	this->value = value;
	setAngle();
}

int gipGauge::getValue() {
	return this->value;
}

int gipGauge::getMax() {
	return this->max;
}

int gipGauge::getMin() {
	return this->min;
}

void gipGauge::setValueSmoothly(int value) {
    targetvalue = value;
    isanimating = true;
}

void gipGauge::setAnimationSpeed(float animationspeed) {
	this->animationspeed = animationspeed;
}

void gipGauge::setGaugeImage(gImage* gaugebg, gImage* gaugestick) {
	this->gaugebg = gaugebg;
	this->gaugestick = gaugestick;
}

void gipGauge::increaseValue(int amount) {
	if(value + amount > max){
		value = max;
		targetvalue = max;
	}else{
		value += amount;
		targetvalue += amount;
	}
	setAngle();
}

void gipGauge::increaseValueSmoothly(int amount) {
	if(value + amount > max){
			targetvalue = max;
			isanimating = true;
		}
	else{
			targetvalue += amount;
			isanimating = true;
	}
}

void gipGauge::decreaseValue(int amount) {
	if(value - amount < min){
		value = min;
		targetvalue = min;
	}
	else{
		value -= amount;
		targetvalue -= amount;
	}
	setAngle();
}

void gipGauge::decreaseValueSmoothly(int amount) {
	if(value - amount < min){
			targetvalue = min;
			isanimating = true;
		}
	else{
			targetvalue -= amount;
			isanimating = true;
		}
}

void gipGauge::setAngle(){
	float normalized = (float)(value - min) / (max - min); // value from 0 to 1
	angle = startangle + normalized * (endangle - startangle);

	shownangle = angle + imageoffset;
}

float gipGauge::getAngle(){
	return this->angle;
}

void gipGauge::setPosition(int x, int y) {
	bgx = x;
	bgy = y;

	if(type == DEFAULT){
		stickx = bgx + width * 23/100;
		sticky = bgy + height * 24/100;

		rectanglex = x + width * 37/100;
		rectangley = y + height * 70/100;

		mintextx = x + width * 17/100;
		mintexty = y + height * 67/100;

		maxtextx = x + width * 62/100;
		maxtexty = y + height * 67/100;
	}
	else if(type == ALT1){
		stickx = bgx + width * 23/100;
		sticky = bgy + height * 24/100;

		rectanglex = x + width * 37/100;
		rectangley = y + height * 70/100;

		mintextx = x + width * 17/100;
		mintexty = y + height * 55/100;

		maxtextx = x + width * 62/100;
		maxtexty = y + height * 55/100;
	}
	else if(type == ALT2){
		stickx = bgx + width * 38/100;
		sticky = bgy + height * 37/100;

		rectanglex = x + width * 36/100;
		rectangley = y + height * 70/100;

		mintextx = x + width * 20/100;
		mintexty = y + height * 70/100;

		maxtextx = x + width * 62/100;
		maxtexty = y + height * 71/100;
	}

}

void gipGauge::setSize(int width, int height) {
	this->width = width;
	this->height = height;

	if(type == DEFAULT){
		rectanglew = width/4;
		rectangleh = height/6;
		textfont.loadFont("FreeSans.ttf", rectangleh / 2);
	}
	else if(type == ALT1){
		rectanglew = width/4;
		rectangleh = height/6;
		textfont.loadFont("FreeSans.ttf", rectangleh / 2);
	}
	else if(type == ALT2){
		rectanglew = width/4;
		rectangleh = height/6;
		textfont.loadFont("FreeSans.ttf", rectangleh / 3);
	}

}

void gipGauge::setText(std::string text) {
	this->text = text;
}

void gipGauge::setMinText(std::string text) {
	mintext = text;
}

void gipGauge::setMaxText(std::string text) {
	maxtext = text;
}

void gipGauge::setGaugeType(GaugeType type) {
	this->type = type;
}
