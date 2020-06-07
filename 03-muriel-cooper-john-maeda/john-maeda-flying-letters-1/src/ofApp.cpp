#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("framd.ttf", 50, true, true, true);
    alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ofSetBackgroundColor(13, 13, 13);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i = 0; i < visibleOnScreen.size(); i++) {
        int a = ofMap(i, 0, visibleOnScreen.size(), 0, 255);
        ofSetColor(255, 255, 255, a);
        string s(1, alphabets[visibleOnScreen[i].letter]);
        font.drawString(s, visibleOnScreen[i].posX, visibleOnScreen[i].posY);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // Throttling
    if (ofGetFrameNum() % 3 != 0) {
        return;
    }
    
    struct Prints Print;
    Print.letter = counter;
    Print.posX = x;
    Print.posY = y;

    visibleOnScreen.push_back(Print);
    if (visibleOnScreen.size() > 20) {
        visibleOnScreen.pop_front();
    }
    
    counter += 1;
    if (counter == 26) {
        counter = 0;
    }
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
