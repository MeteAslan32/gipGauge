/*
* gCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
*/

#include "gCanvas.h"

gCanvas::gCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
}

gCanvas::~gCanvas() {
}

void gCanvas::setup() {
	button.setup();
	button.setCallback(G_BIND_FUNCTION(onButtonPressed));
	button.setPosition(900, 250);
	button.setText("+");
	button.setSize(50, 50);

	button2.setup();
	button2.setCallback(G_BIND_FUNCTION(onButton2Pressed));
	button2.setPosition(970, 250);
	button2.setText("++");
	button2.setSize(50, 50);

	button3.setup();
	button3.setCallback(G_BIND_FUNCTION(onButton3Pressed));
	button3.setPosition(1040, 250);
	button3.setText("+++");
	button3.setSize(50, 50);

	button4.setup();
	button4.setCallback(G_BIND_FUNCTION(onButton4Pressed));
	button4.setPosition(900, 330);
	button4.setText("-");
	button4.setSize(50, 50);

	button5.setup();
	button5.setCallback(G_BIND_FUNCTION(onButton5Pressed));
	button5.setPosition(970, 330);
	button5.setText("--");
	button5.setSize(50, 50);

	button6.setup();
	button6.setCallback(G_BIND_FUNCTION(onButton6Pressed));
	button6.setPosition(1040, 330);
	button6.setText("---");
	button6.setSize(50, 50);

	button7.setup();
	button7.setCallback(G_BIND_FUNCTION(onButton7Pressed));
	button7.setPosition(970, 180);
	button7.setText("o");
	button7.setSize(50, 50);

	gauge.setup(gipGauge::DEFAULT);
	gaugebg.loadImage("gauge/GaugeBG.png");
	gaugestick.loadImage("gauge/GaugeStick.png");

	gaugebgptr = &gaugebg;
	gaugestickptr = &gaugestick;

	gauge.setGaugeImage(gaugebgptr, gaugestickptr);
	gauge.setValue(0);
	gauge.setSize(200, 200);
	gauge.setPosition(600, 300);

	gauge2.setup(gipGauge::ALT1);
	gaugebg2.loadImage("gauge/GaugeAltBG_1.png");
	gaugestick2.loadImage("gauge/GaugeAltStick_1.png");

	gaugebgptr2 = &gaugebg2;
	gaugestickptr2 = &gaugestick2;

	gauge2.setGaugeImage(gaugebgptr2, gaugestickptr2);
	gauge2.setMin(100);
	gauge2.setMax(200);
	gauge2.setValue(gauge2.getMin());
	gauge2.setSize(200, 200);
	gauge2.setPosition(100, 300);

	gauge3.setup(gipGauge::ALT2);
	gaugebg3.loadImage("gauge/GaugeAltBG_2.png");
	gaugestick3.loadImage("gauge/GaugeAltStick_2.png");

	gaugebgptr3 = &gaugebg3;
	gaugestickptr3 = &gaugestick3;
	gauge3.setGaugeImage(gaugebgptr3, gaugestickptr3);
	gauge3.setMin(-100);
	gauge3.setMax(200);
	gauge3.setValue(gauge3.getMin());
	gauge3.setSize(200, 200);
	gauge3.setPosition(350, 300);
}

void gCanvas::update() {
	float deltaTime = appmanager->getElapsedTime();
	gauge.update(deltaTime);
	gauge2.update(deltaTime);
	gauge3.update(deltaTime);
}

void gCanvas::draw() {
	button.draw();
	button2.draw();
	button3.draw();
	button4.draw();
	button5.draw();
	button6.draw();
	button7.draw();

	gauge.draw();
	gauge2.draw();
	gauge3.draw();
}

void gCanvas::onButtonPressed(int mousebutton){
	gauge.increaseValue(10);
	gauge2.increaseValue(10);
	gauge3.increaseValue(10);
}

void gCanvas::onButton2Pressed(int mousebutton){
	gauge.increaseValueSmoothly(10);
	gauge2.increaseValueSmoothly(10);
	gauge3.increaseValueSmoothly(10);
}
void gCanvas::onButton3Pressed(int mousebutton){
	gauge.setValueSmoothly(gauge.getMax());
	gauge2.setValueSmoothly(gauge2.getMax());
	gauge3.setValueSmoothly(gauge3.getMax());
}

void gCanvas::onButton4Pressed(int mousebutton) {
	gauge.decreaseValue(10);
	gauge2.decreaseValue(10);
	gauge3.decreaseValue(10);
}
void gCanvas::onButton5Pressed(int mousebutton) {
	gauge.decreaseValueSmoothly(10);
	gauge2.decreaseValueSmoothly(10);
	gauge3.decreaseValueSmoothly(10);
}
void gCanvas::onButton6Pressed(int mousebutton) {
	gauge.setValueSmoothly(gauge.getMin());
	gauge2.setValueSmoothly(gauge2.getMin());
	gauge3.setValueSmoothly(gauge3.getMin());
}
void gCanvas::onButton7Pressed(int mousebutton) {
	gLogi("gCanvas:") << "gauge1 current angle = " << gauge.getAngle();
	gLogi("gCanvas:") << "gauge2 current angle = " << gauge2.getAngle();
	gLogi("gCanvas:") << "gauge3 current angle = " << gauge3.getAngle();
}

void gCanvas::keyPressed(int key) {
//	gLogi("gCanvas") << "keyPressed:" << key;
}

void gCanvas::keyReleased(int key) {
//	gLogi("gCanvas") << "keyReleased:" << key;
}

void gCanvas::charPressed(unsigned int codepoint) {
//	gLogi("gCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void gCanvas::mouseMoved(int x, int y) {
//	gLogi("gCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mousePressed(int x, int y, int button) {
//	gLogi("gCanvas") << "mousePressed" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void gCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("gCanvas") << "mouseReleased" << ", button:" << button;
}

void gCanvas::mouseScrolled(int x, int y) {
//	gLogi("gCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void gCanvas::mouseEntered() {

}

void gCanvas::mouseExited() {

}

void gCanvas::windowResized(int w, int h) {

}

void gCanvas::showNotify() {

}

void gCanvas::hideNotify() {

}
