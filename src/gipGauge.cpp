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

void gipGauge::setup() {
	value = 0;
	min = 0;
	max = 100;
	width = 400;
	height = 400;
	imageoffset = -76; // add to the angle so the angle shows 0 at min
	angle = imageoffset;
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
	//gaugestick->draw(bgx, bgy-15 ,width,height,angle);
	gaugestick->draw(bgx, bgy - height * 18/400, width, height, angle);
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
	angle = (value * 240)/max + imageoffset;
}

float gipGauge::getAngle(){
	return this->angle;
}

void gipGauge::setPosition(int x, int y) {
	bgx = x;
	bgy = y;
}

void gipGauge::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}
