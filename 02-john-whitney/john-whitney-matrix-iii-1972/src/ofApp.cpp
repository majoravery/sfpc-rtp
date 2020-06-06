#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofScale(1, -1);
    delta = 0;
    additonalRads = 0;
    timeRed = 0;
    timePink = 0;
    paused = false; // Use true when controlling with keys
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetLineWidth(3);
    
    float dimension = ofGetWidth();
    
    // Use amplitude to change distance between triangle
    // Use frequency to change speed of movement
    
    // Red background triangle
    ofSetColor(255, 0, 0, 127);
    for (int i = 0; i < 16; i++){
        float xorig = dimension / 2;
        float yorig = dimension / 2;
        float radius = 120;
        // stumbled upon 30 which seemed like the perfect number
        float angle = ofMap(i, 0, 15, 1, 30) * timeRed + PI + additonalRads;
        float x = xorig + 4 * radius / 3 * cos(angle); // 1.3x radius to make it more oval
        float y = yorig + radius * sin(angle);

        ofDrawTriangle(- (i * 10) + x,
                    - (i * 5) + y,
                    + (i * 10) + x,
                    - (i * 5) + y,
                    + x,
                    + (i * 10) + y);
    }
    
    // Pink foreground triangle
    ofSetColor(225, 170, 190);
    for (int i = 0; i < 16; i++){
        float xorig = dimension / 2;
        float yorig = dimension / 2;
        float radius = 120;
        float angle = ofMap(i, 0, 15, 1, 30) * timePink;
        float x = xorig + 4 * radius / 3 * cos(angle); // 1.3x radius to make it more oval
        float y = yorig + radius * sin(angle);

        ofDrawTriangle(- (i * 10) + x,
                    - (i * 5) + y,
                    + (i * 10) + x,
                    - (i * 5) + y,
                    + x,
                    + (i * 10) + y);
    }
    
    // Uncomment to control with keys
    // if (!paused) {
    //     timeRed -= delta;
    //     timePink += delta;
        
    // }
    
    // Comment out when controlling with keys
    if (!paused) {
        float time = ((float)ofGetFrameNum() / 60.0);
        delta = 0.001355 * sin(0.2 * time); // precariously perched...
        timeRed -= delta;
        timePink += delta;
        cout << "delta: " << delta << ", time: " << time << endl;

        if (additonalRads < PI / 4) { // Only want it to rotate 45deg
            additonalRads += (2 * PI / 360) * 0.05;
            cout << "additonalRads: " << additonalRads << endl;
        }

        if (delta < 0) {
            paused = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        paused = paused == true ? false : true;
        cout << "timeRed: " << timeRed << ", timePink: " << timePink << endl;
    }
    
    // up key
    if (key == 57357) {
        delta += 0.0001;
        cout << "delta: " << delta << endl;
    }
    
    // down key
    if (key == 57359) {
        delta -= 0.0001;
        cout << "delta: " << delta << endl;
    }
    
    // w key
    if (key == 'w') {
        float val = additonalRads + 2 * PI / 360;
        additonalRads = ofClamp(val, 0, PI / 4);
        cout << "additonalRads: " << additonalRads << endl;
    }
    
    // s key
    if (key == 's') {
        float val = additonalRads - 2 * PI / 360;
        additonalRads = ofClamp(val, 0, PI / 4);
        cout << "additonalRads: " << additonalRads << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
