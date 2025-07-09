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
	int getValue();

private:
	int min;
	int max;
	int value;
};

#endif /* SRC_GIPGAUGE_H_ */
