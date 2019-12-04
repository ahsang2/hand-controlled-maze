#pragma once

#include "ofMain.h"
#include "capture_image.h"




enum State {STARTING, PLAYING, PAUSED};

class ofApp : public ofBaseApp{
    private:
        void drawGameDisplay();
  std::unique_ptr<cv::Mat> updateHandPosition();
   void contourHandPosition(cv::Mat thresholdedImage);
     ofxPanel hsvValues;
    ofParameter<float> lowH, highH, lowS, highS, lowV, highV;
    
        State cur_state;
        ofTrueTypeFont title_font;
        ofTrueTypeFont sub_font;
        ofVideoGrabber webcam;
        ofxCvColorImage cameraImage;
        ofxCvGrayscaleImage grayImage, learnedBackground;
        ofImage displayImage;
        ofxCvGrayscaleImage differences;
        ofxCv::ContourFinder contourFinder;
    
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

};
