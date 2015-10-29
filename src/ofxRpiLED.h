#include "ofMain.h"
#include "../libs/rgb_matrix/include/led-matrix.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

class ofxRpiLED {
    
private:
	int 		rows;		// A 32x32 display. Use 16 when this is a 16x32 display.
	int 		chain;		// Number of boards chained together.
	int 		parallel;	// Number of chains in parallel (1..3). > 1 for plus or Pi2
	int 		cW;
	int 		cH;
	Canvas 		*canvas;
	GPIO 		io;

public:
	ofxRpiLED();
	~ofxRpiLED();
	void setup();
	void setup(int _rows, int _chain, int _parallel);
	void clear();
	void draw(ofImage &i);
	void draw(ofPixels &p);
};
