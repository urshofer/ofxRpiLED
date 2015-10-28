
#include "ofMain.h"
#include "led-matrix.h"

using namespace rgb_matrix;

class ofxRpiLED {
    
private:
	
    int 		rows = 32;    // A 32x32 display. Use 16 when this is a 16x32 display.
    int 		chain = 1;    // Number of boards chained together.
    int 		parallel = 1; // Number of chains in parallel (1..3). > 1 for plus or Pi2
	int 		cW;
	int 		cH;	
	Canvas 		*canvas;
		
    
public:
    
    ofxRpiLED();
    ~ofxRpiLED();

    void setup(int _rows, int _chain, int _parallel);
    void clear();
    void draw(ofPixels p);
  	
};

#endif
