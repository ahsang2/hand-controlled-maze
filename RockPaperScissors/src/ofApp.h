#pragma once

#include "ofMain.h"
#include "capture_image.h"

enum State {STARTING, PLAYING, PAUSED};

class ofApp : public ofBaseApp{
    private:
        State cur_state;
        ofTrueTypeFont title_font;
        ofTrueTypeFont sub_font;
        void drawGameDisplay();
        ofVideoGrabber cam;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    
    ofxPanel gui;
    ofParameter<bool> resetBackground;
    ofParameter<float> learningTime, thresholdValue;
    
    
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
