//
//  hand_recognizer.h
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/4/19.
//

#pragma once

#include "ofCamera.h"
#include "ofxOpenCv.h"


enum Gesture { WEST, EAST, NORTH, SOUTH, NOWHERE};

// https://sites.google.com/site/ofauckland/examples/10-testing
class HandRecognizer{
    private:
        ofVideoGrabber webcam;
        ofxCvColorImage rgb,hsb;
        ofxCvGrayscaleImage hue,sat,bri,filtered;
        ofxCvContourFinder contours;
        int w,h;
        int findHue;
    
    public:
        void setup();
        void update();
        void draw(int x, int y);
        void mousePressed(int x, int y, int button);
        Gesture getGesture();
};
