#include "ofxRpiLED.h"


// Constructor
ofxRpiLED::ofxRpiLED() {
	rows = 32;    // A 32x32 display. Use 16 when this is a 16x32 display.
	chain = 2;    // Number of boards chained together.
	parallel = 1; // Number of chains in parallel (1..3). > 1 for plus or Pi2
}

// Desonstructor
ofxRpiLED::~ofxRpiLED() {
	canvas->Clear();
	delete canvas;
}

void ofxRpiLED::setup() {
	/*
	* Set up GPIO pins. This fails when not running as root.
	*/
	if (!io.Init())
		return;

	canvas = new RGBMatrix(&io, rows, chain, parallel);

	/* 
	* Clear and cache size 
	*/
	
	canvas->Fill(0,0,0);
	cW = canvas->width();
	cH = canvas->height();
}

void ofxRpiLED::setup(int _rows, int _chain, int _parallel){
	rows 		= _rows;
	chain 		= _chain;
	parallel 	= _parallel;
	setup();
}

void ofxRpiLED::clear(){
	canvas->Clear();
}

void ofxRpiLED::draw(ofPixels &p){
	int w = cW > p.getWidth()  ? cW : p.getWidth();
	int h = cH > p.getHeight() ? cH : p.getHeight();	
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			ofColor c = p.getColor(x, y);
			canvas->SetPixel(x, y, c.r, c.g, c.b);
		}
	}	
}

void ofxRpiLED::draw(ofImage &i){
	int w = cW > i.getWidth()  ? cW : i.getWidth();
	int h = cH > i.getHeight() ? cH : i.getHeight();	
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			ofColor c = i.getColor(x, y);
			canvas->SetPixel(x, y, c.r, c.g, c.b);
		}
	}	
}
