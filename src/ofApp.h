#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void drawLines(ofPoint startPoint);
        void drawSections(ofPoint startPoint);
        void timerElapsed();
        void keyReleased(int key);
    
    float timerStart;
    float timer;
    int animationSpeed;
    float waveVolume;
    int spacing;
    
    struct pianoNote{
        int timer;
        ofSoundPlayer sound;
    };
    
    ofSoundPlayer pinkNoise;
    
};
