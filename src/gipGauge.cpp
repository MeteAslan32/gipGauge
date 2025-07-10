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

void gipGauge::update() {
}

void gipGauge::draw() {
	gaugebg->draw(bgx,bgy,width,height);
	gaugestick->draw(bgx+5, bgy-20 ,width,height,angle);
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

void gipGauge::setGaugeImage(gImage* gaugebg, gImage* gaugestick) {
	this->gaugebg = gaugebg;
	this->gaugestick = gaugestick;

}

void gipGauge::increaseValue(int amount) {
	if(value + amount > max){
		value = max;
	}else{
		value += amount;
	}
	setAngle();
}

void gipGauge::decreaseValue(int amount) {
	if(value - amount < min){
		value = min;
	}else{
		value -= amount;
	}
	setAngle();
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

	stickx = x + 10;
	sticky = y - 20;
}
