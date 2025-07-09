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

	void setMin(int min);
	void setMax(int max);
	void setValue(int value);
	void increaseValue(int amount);
	void decreaseValue(int amount);
	void setGaugeImage(gImage gaugebg, gImage stick);

	int getValue();

private:
	int min;
	int max;
	int value;
	int bgx, bgy, stickx, sticky;

	gImage gaugebg, gaugestick;
};

#endif /* SRC_GIPGAUGE_H_ */
