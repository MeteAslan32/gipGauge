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
}

void gipGauge::update() {
}

void gipGauge::draw() {
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

void gipGauge::setGaugeImage(gImage gaugebg, gImage gaugestick) {
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
	angle = (value * 180)/max;
}

float gipGauge::getAngle(){
	return this->angle;
}
