#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyReleased(int key);
        void keyPressed(int key);
        void drawLines(ofPoint startPoint);
        void drawSections(ofPoint startPoint);
        void timerElapsed();
    
    float timerStart;
    float timer;
};
