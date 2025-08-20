 /*
 * gCanvas.h
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */

#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gBaseCanvas.h"
#include "gApp.h"
#include "gImage.h"
#include "gipButton.h"
#include "gipGauge.h"

class gCanvas : public gBaseCanvas {
public:
	gCanvas(gApp* root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void charPressed(unsigned int codepoint);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseScrolled(int x, int y);
	void mouseEntered();
	void mouseExited();
	void windowResized(int w, int h);

	void showNotify();
	void hideNotify();

	void onButtonPressed(int mousebutton);
	void onButton2Pressed(int mousebutton);
	void onButton3Pressed(int mousebutton);
	void onButton4Pressed(int mousebutton);
	void onButton5Pressed(int mousebutton);
	void onButton6Pressed(int mousebutton);
	void onButton7Pressed(int mousebutton);

private:
	gApp* root;
	gipButton button, button2, button3, button4, button5, button6, button7;
	gipGauge gauge, gauge2, gauge3;
	gImage gaugebg, gaugestick, gaugebg2, gaugestick2,  gaugebg3, gaugestick3;
	gImage* gaugebgptr;
	gImage* gaugebgptr2;
	gImage* gaugebgptr3;
	gImage* gaugestickptr;
	gImage* gaugestickptr2;
	gImage* gaugestickptr3;
};

#endif /* GCANVAS_H_ */
