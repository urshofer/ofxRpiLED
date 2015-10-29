#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(25);
	ofBackground(0,0,0);
	led.setup();
	box[0].set( 10 );
	box[0].setPosition(16,16,1);
	box[1].set( 10 );
	box[1].setPosition(32,16,1);
	box[2].set( 10 );
	box[2].setPosition(48,16,1);
	std::cout << "[ofApp::setup] Ready..." << endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(ofGetFrameRate(),1,30);
	
	float spinX = sin(ofGetElapsedTimef()*.35f);
	float spinY = cos(ofGetElapsedTimef()*.075f);	
	ofSetColor(0, 255, 0);
	box[0].rotate(spinX, 1.0, 0.0, 0.0);
	box[0].rotate(spinY, 0, 1.0, 0.0);
	box[0].drawWireframe();

	ofSetColor(255, 0, 0);
	box[1].rotate(spinX, 1.0, 0.0, 0.0);
	box[1].rotate(spinY, 0, 1.0, 0.0);
	box[1].drawWireframe();

	ofSetColor(0, 0, 255);
	box[2].rotate(spinX, 1.0, 0.0, 0.0);
	box[2].rotate(spinY, 0, 1.0, 0.0);
	box[2].drawWireframe();

	image.grabScreen(0,0,64,32);
	led.draw(image);
}
