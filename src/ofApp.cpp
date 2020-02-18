#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(255);
    ofSetColor(0);
    timerStart = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update(){
    timer = ofGetElapsedTimeMillis() - timerStart;
    
    if(timer > 100){
        timerElapsed();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
}

void ofApp::drawLines(ofPoint startPoint){
    
    if(startPoint.y > ofGetHeight() - 100){
        return;
    }
    
    drawSections(startPoint);
    ofPoint nextLine;
    nextLine.x = startPoint.x;
    nextLine.y = startPoint.y + 20;
    drawLines(nextLine);
}

void ofApp::drawSections(ofPoint startPoint){
    
    if(startPoint.x > ofGetWidth() - 100){
        return;
    }
    
    ofPoint nextSection;
    nextSection.x = startPoint.x + 20;
    nextSection.y = (ofRandom(20) - 10) + startPoint.y;
    ofDrawLine(startPoint.x, startPoint.y, nextSection.x, nextSection.y);
    drawSections(nextSection);
}

void ofApp::timerElapsed(){
    timerStart = ofGetElapsedTimeMillis();
    ofClear(255);
    ofPoint point;
    point.x = 100;
    point.y = 100;
    drawLines(point);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofClear(255);
    ofPoint point;
    point.x = 100;
    point.y = 100;
    drawLines(point);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    ofClear(255);
    ofPoint point;
    point.x = 100;
    point.y = 100;
    drawLines(point);
}
