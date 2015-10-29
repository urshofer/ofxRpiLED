#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(25);
	ofSetLogLevel(OF_LOG_ERROR);	
	led.setup();
	image.load("image.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPixels & pixels = image.getPixels();
	led.draw(pixels);
}