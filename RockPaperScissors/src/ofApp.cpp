#include "ofApp.h"


using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    cur_state = STARTING;
    title_font.load("BD.TTF", 80);
    sub_font.load("riffic.otf", 42);
    
    webcam.setVerbose(true);
    webcam.initGrabber(320,240);
    CvSeq n;

}

//--------------------------------------------------------------
void ofApp::update(){
     webcam.update();
    
    if(webcam.isFrameNew()) {
        contourFinder.setMinArea(60);
         contourFinder.setMaxArea(600);
         contourFinder.setThreshold(60);
    contourFinder.findContours(webcam);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch(cur_state) {
        case(STARTING):
            title_font.drawString("Rock Paper Scissors", 40, 100);
            sub_font.drawString("Press Space To Start", 220, 600);
            break;
            
        case(PLAYING): {
            ofSetColor(130, 100, 70);
            drawGameDisplay();
            sub_font.drawString("Rock", 200, 100);
            webcam.draw(0, 200);
            contourFinder.draw();
            break;
        }
            
        case(PAUSED):
            title_font.drawString("Paused", 267, 450);
            
        default:
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(cur_state != STARTING && key == 'p')
    {
        cur_state = PAUSED;
    }
    else if(key == ' ') {
        cur_state = PLAYING;
    }
    else if(cur_state == PAUSED) {
        cur_state = PLAYING;
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

void ofApp::drawGameDisplay() {
    //draw
}



