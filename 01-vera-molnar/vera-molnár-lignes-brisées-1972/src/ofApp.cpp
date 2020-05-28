#include "ofApp.h"

int ofApp::unit = 50;
int ofApp::cols = 11;
int ofApp::rows = 5;

int margin = ofApp::unit;

int ofApp::width = ofApp::cols * (ofApp::unit * 2) + margin + margin;
int ofApp::height = ofApp::rows * (ofApp::unit * 2) + margin + margin;

int bottomPoint, topPoint, leftPoint, rightPoint;
int buffer = 5; // Prevent point from being too close to edge

int boxDimension = ofApp::unit * 2;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(216);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // Grid
    ofSetLineWidth(2);
    ofSetColor(173);
    ofNoFill();
    
    for (int y = 0; y < ofApp::height; y = y + ofApp::unit){
        for (int x = 0; x < ofApp::width; x = x + ofApp::unit){
            ofRectangle rect;
            rect.x = x;
            rect.y = y;
            rect.width = ofApp::unit;
            rect.height = ofApp::unit;
            ofDrawRectangle(rect);
        }
    }
    
    ofTranslate(ofApp::unit, ofApp::unit);

    ofSeedRandom(0);
    ofSetLineWidth(4);
    ofSetColor(13);
    // REMEMBER TO DRAW FIRST ONE THAT ONLY TOUCHES 3 CORNERS
    for (int y = 0; y < ofApp::rows; y++){
        for (int x = 0; x < ofApp::cols; x++){

            ofPolyline line;
            ofPoint pt;
            bottomPoint = ofRandom((x * boxDimension) + buffer, ((x + 1) * boxDimension) - buffer);
            topPoint = ofRandom((x * boxDimension) + buffer, ((x + 1) * boxDimension) - buffer);

            leftPoint = ofRandom((y * boxDimension) + buffer, ((y + 1) * boxDimension) - buffer);
            rightPoint = ofRandom((y * boxDimension) + buffer, ((y + 1) * boxDimension) - buffer);

            // If true, draw bottom point first, then connect top point
            if (ofRandom(0, 1) > 0.5) {
                pt.set(bottomPoint, (y + 1) * boxDimension);
                line.addVertex(pt);
                pt.set(topPoint, y * boxDimension);
                line.addVertex(pt);
            } else {
                pt.set(topPoint, y * boxDimension);
                line.addVertex(pt);
                pt.set(bottomPoint, (y + 1) * boxDimension);
                line.addVertex(pt);
            }

            // Connect left point first if true, then right
            if (ofRandom(0, 1) > 0.5) {
                pt.set(x * boxDimension, leftPoint);
                line.addVertex(pt);
                pt.set((x + 1) * boxDimension, rightPoint);
                line.addVertex(pt);
            } else {
                pt.set((x + 1) * boxDimension, rightPoint);
                line.addVertex(pt);
                pt.set(x * boxDimension, leftPoint);
                line.addVertex(pt);
            }

           line.draw();

        }
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
