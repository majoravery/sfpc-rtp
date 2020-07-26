#pragma once

#include "ofMain.h"

class Pt2 {
    public:
        float x;
        float y;
        float deltaX;
        float deltaY;
};

class Pt {
    public:
        float delta;
        float x;
        float y;
        float xOrig;
        float yOrig;
        deque < Pt2 > pts;
};

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
    
        vector < Pt > points;
        ofPolyline line;
        float constraint;
    
        float speedX;
        float speedY;
};
