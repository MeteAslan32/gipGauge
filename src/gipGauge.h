/*
 * gipEmptyPlugin.h
 *
 *  Created on: Mar 11, 2023
 *      Author: Noyan Culum
 *      Created by: kayra
 */

#ifndef SRC_GIPGAUGE_H_
#define SRC_GIPGAUGE_H_

#include "gBasePlugin.h"


class gipGauge : public gBasePlugin{
public:
	gipGauge();
	virtual ~gipGauge();

	void setup() override;
	void update(float deltaTime);
	void draw();

	void increaseValue(int amount);
	void decreaseValue(int amount);
	void increaseValueSmoothly(int amount);
	void decreaseValueSmoothly(int amount);

	void setMin(int min);
	void setMax(int max);
	void setPosition(int x, int y);
	void setValue(int value);
	void setValueSmoothly(int value);
	void setAnimationSpeed(float animationspeed);
	void setGaugeImage(gImage* gaugebg, gImage* stick);
	void setAngle();
	void setSize(int width, int height);

	int getValue();
	int getMax();
	int getMin();
	float getAngle();

private:

	int min, max;
	int value;
	int targetvalue;

	float angle, imageoffset;
	int bgx, bgy;
	int width, height;

	float animationspeed = 100;
	bool isanimating = false;

	gImage* gaugebg;
	gImage* gaugestick;
};

#endif /* SRC_GIPGAUGE_H_ */
