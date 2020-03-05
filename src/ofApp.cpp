#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(250);
    ofSetColor(0);
    timerStart = ofGetElapsedTimeMillis();
    pinkNoise.load("PinkNoise.wav");
    pinkNoise.play();
    animationSpeed = 100;
    spacing = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    timer = ofGetElapsedTimeMillis() - timerStart;
    
    waveVolume = ofNoise(ofGetElapsedTimeMillis() * 0.00023) * 0.7;
    pinkNoise.setVolume(waveVolume);
    
    if(timer > animationSpeed){
        timerElapsed();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

void ofApp::drawLines(ofPoint startPoint){
    
    if(startPoint.y > ofGetHeight() - spacing){
        return;
    }
    
    drawSections(startPoint);
    ofPoint nextLine;
    nextLine.x = startPoint.x;
    nextLine.y = startPoint.y + (spacing / 5);
    drawLines(nextLine);
}

void ofApp::drawSections(ofPoint startPoint){
    
    if(startPoint.x > ofGetWidth() - spacing){
        return;
    }
    
    ofPoint nextSection;
    nextSection.x = startPoint.x + (spacing / 5);
    nextSection.y = (ofRandom(spacing / 5) - spacing / 10) + startPoint.y;
    ofDrawLine(startPoint.x, startPoint.y, nextSection.x, nextSection.y);
    drawSections(nextSection);
}

void ofApp::timerElapsed(){
    timerStart = ofGetElapsedTimeMillis();
    ofClear(255);
    ofPoint point;
    point.x = spacing;
    point.y = spacing;
    drawLines(point);
}

void ofApp::keyReleased(int key){
    if(key == 57357){
        if(animationSpeed < 20) return;
        animationSpeed -= 10;
    }
    if(key == 57359){
        if(animationSpeed > 500) return;
        animationSpeed += 10;
    }
    if(key == 'w'){
        if(spacing > 500) return;
        spacing += 10;
    }
    if(key == 's'){
        if(spacing <= 1) return;
        spacing -= 1;
    }
}
