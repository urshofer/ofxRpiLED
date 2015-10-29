#pragma once

#include "ofMain.h"
#include "ofxRpiLED.h"


class ofApp : public ofBaseApp{

	public:
		
		ofxRpiLED 	led;
		ofImage 	image;
		ofBoxPrimitive box[3];		
		
		void setup();
		void update();
		void draw();
};
