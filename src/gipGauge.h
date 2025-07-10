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
	void update() override;
	void draw();

	void increaseValue(int amount);
	void decreaseValue(int amount);
	void setPosition(int x, int y);

	void setMin(int min);
	void setMax(int max);
	void setValue(int value);
	void setGaugeImage(gImage* gaugebg, gImage* stick);

	int getValue();
	float getAngle();
	void setAngle();

private:

	int min, max;
	int value;
	float angle, imageoffset;
	int bgx, bgy, stickx, sticky;
	int width, height;

	gImage* gaugebg;
	gImage* gaugestick;

};

#endif /* SRC_GIPGAUGE_H_ */
