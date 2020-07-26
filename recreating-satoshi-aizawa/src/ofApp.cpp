#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetColor(0);
    ofSetLineWidth(2);
    
    int width = ofGetWidth();
    int height = ofGetHeight();
    constraint = 50;
    speedX = 1;
    speedY = 1;

    Pt point;
    point.x = (width / 2) - constraint;
    point.y = 4 * height / 5;
    point.xOrig = (width / 2) - constraint;
    point.yOrig = 4 * height / 5;
    point.delta = 0;
    points.push_back(point);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    line.clear();
    for (int i = 0; i < points.size(); i++) {
        float x = points[i].x;
        float min = points[i].xOrig;
        float max = min + constraint * 2;
        
        if (x == max) {
            points[i].delta = -speedX;
    
            Pt2 pt1;
            pt1.x = x;
            pt1.y = points[i].y;
            pt1.deltaX = -speedX;
            pt1.deltaY = -speedY; // travels upwards
            points[i].pts.push_back(pt1);
        }
        
        if (x == min) {
            points[i].delta = speedX;
            
            Pt2 pt2;
            pt2.x = x;
            pt2.y = points[i].y;
            pt2.deltaX = speedX;
            pt2.deltaY = -speedY; // travels upwards
            points[i].pts.push_back(pt2);
        }
            
        points[i].x += points[i].delta;
        
        if (!points[i].pts.empty()) {
            // when point reaches top of screen, it moves
            // along the x axis, giving the impression that
            // the line continues but out of screen
            if (points[i].pts[0].y < constraint) {
                points[i].pts[0].x += points[i].pts[0].deltaX;
                
                ofPoint pt5;
                pt5.set(points[i].pts[0].x, points[i].pts[0].y);
                line.addVertex(pt5);
                
                for (int j = 1; j < points[i].pts.size(); j++) {
                    points[i].pts[j].y += points[i].pts[j].deltaY;

                    ofPoint pt4;
                    pt4.set(points[i].pts[j].x, points[i].pts[j].y);
                    line.addVertex(pt4);
                }
                
                if ((points[i].pts[0].deltaX == speedX && points[i].pts[0].x == max) ||
                    (points[i].pts[0].deltaX == -speedX && points[i].pts[0].x == min)) {
                    points[i].pts.pop_front();
                }
            } else {
                // initial run
                for (int j = 0; j < points[i].pts.size(); j++) {
                    points[i].pts[j].y += points[i].pts[j].deltaY;

                    ofPoint pt6;
                    pt6.set(points[i].pts[j].x, points[i].pts[j].y);
                    line.addVertex(pt6);
                }
            }
        }
        
        // "source point" should always be connected last
        ofPoint pt3;
        pt3.set(points[i].x, points[i].y);
        line.addVertex(pt3);
    }
    line.draw();

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
