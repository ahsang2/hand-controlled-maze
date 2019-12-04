#pragma once

#include "ofMain.h"
#include "capture_image.h"




enum State {STARTING, PLAYING, PAUSED};

class ofApp : public ofBaseApp{
    private:
        void drawGameDisplay();

    
        State cur_state;
        ofTrueTypeFont title_font;
        ofTrueTypeFont sub_font;
        ofVideoGrabber webcam;
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
