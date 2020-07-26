#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofImage imgOriginal;
        ofImage imgMain;
        ofImage imgHold;
        ofImage imgToDisplay;
    
    void erode(ofImage &imgSrc, ofImage &imgDest);
    void dilate(ofImage &imgSrc, ofImage &imgDest);
    void convolute(ofImage &imgSrc, ofImage &imgDest);
    void subtract(ofImage &imgSrc, ofImage &imgSub, ofImage &imgDest);
    void add(ofImage &imgSrc, ofImage &imgSub, ofImage &imgDest);
};
