#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cur_state = STARTING;
    title_font.load("BD.TTF", 80);
    sub_font.load("riffic.otf", 42);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    switch(cur_state) {
        case(STARTING):
            title_font.drawString("Rock Paper Scissors", 40, 100);
            sub_font.drawString("Press Space To Start", 220, 600);
            break;
            
        case(PLAYING):
            ofSetColor(130, 100, 70);
            drawGameDisplay();
            sub_font.drawString("Rock", 200, 100);
            break;
            
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
