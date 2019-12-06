//
//  hand_recognizer.hpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/4/19.
//
#pragma once

#include "ofCamera.h"
#include "ofxOpenCv.h"
#include <stdio.h>
#include "ofxCv.h"
#include "ofxGui.h"


enum Gesture { ROCK, PAPER, SCISSORS};

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
        void draw();
        void mousePressed(int x, int y, int button);
        Gesture getGesture();
};
