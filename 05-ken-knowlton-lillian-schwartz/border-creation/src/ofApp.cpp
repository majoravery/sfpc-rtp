#include "ofApp.h"

void ofApp::erode(ofImage &imgSrc, ofImage &imgDest) {
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {
          
            // edges
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);

            // neighbor values
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);

            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor cc = imgSrc.getColor(i,j);
            ofColor e_ = imgSrc.getColor(i_p_1,j);

            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);

            if (
                nw.getBrightness() < 127 ||
                n_.getBrightness() < 127 ||
                ne.getBrightness() < 127 ||
                w_.getBrightness() < 127 ||
                cc.getBrightness() < 127 ||
                e_.getBrightness() < 127 ||
                sw.getBrightness() < 127 ||
                se.getBrightness() < 127 ||
                s_.getBrightness() < 127
            ) {
                imgDest.setColor(i, j, ofColor(0));
            } else {
                imgDest.setColor(i, j, ofColor(255));
            }
        }
    }
            
    imgDest.update();
}

void ofApp::add(ofImage &imgSrc, ofImage &imgSub, ofImage &imgDest) {
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {
            float src = imgSrc.getColor(i, j).getBrightness();
            float sub = imgSub.getColor(i, j).getBrightness();

            imgDest.setColor(i, j, ofClamp(src + sub, 0, 255));
        }
    }
            
    imgDest.update();
}

void ofApp::subtract(ofImage &imgSrc, ofImage &imgSub, ofImage &imgDest) {
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {
            float src = imgSrc.getColor(i, j).getBrightness();
            float sub = imgSub.getColor(i, j).getBrightness();

            imgDest.setColor(i, j, abs(src - sub));
        }
    }
            
    imgDest.update();
}

void ofApp::convolute(ofImage &imgSrc, ofImage &imgDest) {
    
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {
            
            int accumulator = 0;
          
            // edges
            int i_m_1 = ofClamp(i-1, 0, imgSrc.getWidth()-1);
            int i_p_1 = ofClamp(i+1, 0, imgSrc.getWidth()-1);
            int j_m_1 = ofClamp(j-1, 0, imgSrc.getHeight()-1);
            int j_p_1 = ofClamp(j+1, 0, imgSrc.getHeight()-1);

            // neighbor values
            ofColor nw = imgSrc.getColor(i_m_1,j_p_1);
            ofColor n_ = imgSrc.getColor(i,j_p_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_p_1);

            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor cc = imgSrc.getColor(i,j);
            ofColor e_ = imgSrc.getColor(i_p_1,j);

            ofColor sw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor se = imgSrc.getColor(i_p_1,j_m_1);
            ofColor s_ = imgSrc.getColor(i,j_m_1);

            accumulator += nw.getBrightness() * 0.05;
            accumulator += n_.getBrightness() * 0.2;
            accumulator += ne.getBrightness() * 0.05;

            accumulator += w_.getBrightness() * 0.2;
            accumulator += cc.getBrightness() * -1;
            accumulator += e_.getBrightness() * 0.2;

            accumulator += sw.getBrightness() * 0.05;
            accumulator += se.getBrightness() * 0.2;
            accumulator += s_.getBrightness() * 0.05;
            
            imgDest.setColor(i, j, ofColor(accumulator));

        }
    }
            
    imgDest.update();
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(15);
    
//    imgOriginal.load("zongzi.jpg"); // If using, use 602x301 in main.cpp
    imgOriginal.load("2.jpg");

    // Main black and white image
    imgMain.allocate(imgOriginal.getWidth(), imgOriginal.getHeight(), OF_IMAGE_GRAYSCALE);
    
    // Temporary holder for pixels
    imgHold.allocate(imgOriginal.getWidth(), imgOriginal.getHeight(), OF_IMAGE_GRAYSCALE);
    
    // Final image to be displayed - where the add/subtract functions write to
    imgToDisplay.allocate(imgOriginal.getWidth(), imgOriginal.getHeight(), OF_IMAGE_GRAYSCALE);
    
    for (int i = 0; i < imgOriginal.getWidth(); i++) {
        for (int j = 0; j < imgOriginal.getHeight(); j++) {
            float b = imgOriginal.getColor(i, j).getBrightness();
            if (b > 90) {
                imgMain.setColor(i, j, ofColor(255));
                imgToDisplay.setColor(i, j, ofColor(255));
            } else {
                imgMain.setColor(i, j, ofColor(0));
                imgToDisplay.setColor(i, j, ofColor(0));
            }
        }
    }
    
    imgMain.update();
    imgToDisplay.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // shrink a little
    erode(imgMain, imgHold);
    erode(imgHold, imgMain);
    
    // subtract to get border
    subtract(imgToDisplay, imgMain, imgToDisplay);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofScale(0.5, 0.5);
    int dimension = imgOriginal.getWidth();
    imgOriginal.draw(0, 0);
    imgToDisplay.draw(dimension, 0);
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
