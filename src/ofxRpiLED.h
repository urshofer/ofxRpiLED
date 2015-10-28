#include "ofMain.h"
#include "../libs/rgb_matrix/include/led-matrix.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

class ofxRpiLED {
    
private:
	
    int 		rows = 32;    // A 32x32 display. Use 16 when this is a 16x32 display.
    int 		chain = 1;    // Number of boards chained together.
    int 		parallel = 1; // Number of chains in parallel (1..3). > 1 for plus or Pi2
    int 		cW;
    int 		cH;
    Canvas 		*canvas;
    GPIO 		io;

public:
   
    ofxRpiLED();
    ~ofxRpiLED();

    void setup(int _rows, int _chain, int _parallel);
    void clear();
    void draw(ofPixels p);
  	
};
