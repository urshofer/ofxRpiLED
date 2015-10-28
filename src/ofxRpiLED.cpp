
#include "ofxRpiLED.h"


// Constructor
ofxRpiLED::ofxRpiLED() {
    rows = 32;    // A 32x32 display. Use 16 when this is a 16x32 display.
    chain = 1;    // Number of boards chained together.
    parallel = 1; // Number of chains in parallel (1..3). > 1 for plus or Pi2
}

// Desonstructor
ofxRpiLED::~ofxRpiLED() {
	canvas->Clear();
	delete canvas;
}

void ofxRpiLED::setup(int _rows, int _chain, int _parallel){
	rows 		= _rows;
	chain 		= _chain;
	parallel 	= _parallel;
	*canvas = new RGBMatrix(&io, rows, chain, parallel);
	canvas->Fill(0, 0, 0);	
    cW = canvas->width();
    cH = canvas->height();
}

void ofxRpiLED::clear(){
	canvas->Clear();
}

void ofxRpiLED::draw(ofPixels p){
	if (cW != p.getWidth() && cH != p.getHeight())
		p.resize(cW, cH);
    for (int x = 0; x < cW; x++) {
		for (int y = 0; y < cH; y++) {
			ofColor c = p.getColor(x, y);
			canvas->SetPixel(x, y, c.r, c.g, c.b);
		}
    }	

}