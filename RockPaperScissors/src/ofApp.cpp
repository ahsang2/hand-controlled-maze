#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

std::unique_ptr<cv::Mat> ofApp::updateHandPosition() {
    Mat orignalImage = toCv(cameraImage);
    
    Mat hsvImage;
    cvtColor(orignalImage, hsvImage, COLOR_BGR2HSV);
    
    Mat thresholdedImage;
    inRange(hsvImage, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), thresholdedImage);
    
    //remove small objects in foreground
    erode(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    dilate(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    //remove holes in foreground
    dilate(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    erode(thresholdedImage, thresholdedImage, getStructuringElement(MORPH_ELLIPSE, cv::Size(5, 5)));
    
    return std::make_unique<cv::Mat>(thresholdedImage);
}

void ofApp::contourHandPosition(cv::Mat thresholdedImage) {
    Mat grayMat = toCv(grayImage);
    Mat backgroundMat = toCv(learnedBackground);
    Mat differenceMat = toCv(displayImage);
    if (webcam.isFrameNew()){
        grayMat = thresholdedImage;
        absdiff(backgroundMat, thresholdedImage, differenceMat);
        contourFinder.findContours(differenceMat);
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    cur_state = STARTING;
    title_font.load("BD.TTF", 80);
    sub_font.load("riffic.otf", 42);
    
   webcam.setVerbose(true);
    webcam.initGrabber(320,240);
    
    cameraImage.allocate(320,240);
    grayImage.allocate(320,240);
    displayImage.allocate(320, 240, OF_IMAGE_COLOR);
    learnedBackground.allocate(320,240);
    differences.allocate(320,240);
    cameraImage.convertRgbToHsv();
}

//--------------------------------------------------------------
void ofApp::update(){
     webcam.update();
        if (webcam.isFrameNew()) {
            cameraImage.setFromPixels(webcam.getPixels());
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
            //cam.draw(0, 200);
            ofSetHexColor(0xffffff);
    
            ofSetHexColor(0xffffff);
            cameraImage.draw(0, 0, 320, 240);
            contourFinder.draw();
            
            hsvValues.draw();
            
            std::unique_ptr<cv::Mat> thresholdedImagePtr = updateHandPosition();
            contourHandPosition(*thresholdedImagePtr);
            drawMat(*thresholdedImagePtr, 320, 0);
            
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



