//
//  hand_recognizer.cpp
//  
//
//  Created by Ahsan Gilani on 12/4/19.
//

#include "hand_recognizer.h"

void HandRecognizer::setup() {
    ofBackground(0,0,0);
    
    w = 260;//320;
    h = 180;//240;
    
    webcam.initGrabber(w, h);
    
    rgb.allocate(w, h);
    hsb.allocate(w, h);
    hue.allocate(w, h);
    sat.allocate(w, h);
    bri.allocate(w, h);
    filtered.allocate(w, h);
}

void HandRecognizer::update() {
    
    webcam.update();
    
    if (webcam.isFrameNew()) {
        
        //copy webcam pixels to rgb image
        rgb.setFromPixels(webcam.getPixels());
        rgb.resize(w, h);
        
        //mirror horizontal
        rgb.mirror(false, true);
        
        //duplicate rgb
        hsb = rgb;
        
        //convert to hsb
        hsb.convertRgbToHsv();
        
        //store the three channels as grayscale images
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);
        
        //filter image based on the hue value were looking for
        for (int i = 0; i < w*h; i++) {
            filtered.getPixels()[i] = ofInRange(hue.getPixels()[i],findHue-6,findHue+6) ? 255 : 0;
        }
        filtered.flagImageChanged();

        //run the contour finder on the filtered image to find blobs with a certain hue
        contours.findContours(filtered, 100, w*h/2, 1, false);
    }
}

void HandRecognizer::draw(int x, int y) {
    ofSetColor(255,255,255);
    
    //draw all cv images
    rgb.draw(x,y);

    contours.draw(x,y);
}

void HandRecognizer::mousePressed(int x, int y, int button) {
    
    //calculate local mouse x,y in image
    int mx = x % w;
    int my = y % h;
    
    //get hue value on mouse position
    findHue = hue.getPixels()[my*w+mx];
}

Direction HandRecognizer::getDirection() {
    for (int i = 0; i < contours.nBlobs; i++) {
        int x = 0;
        int y = 0;
        int height = 0;
        
     
        if (contours.blobs[i].centroid.y > contours.blobs[i].centroid.x && contours.blobs[i].centroid.y < h - contours.blobs[i].centroid.x){
            return Direction::WEST;
        }
        else if (contours.blobs[i].centroid.y < contours.blobs[i].centroid.x && contours.blobs[i].centroid.y > h - contours.blobs[i].centroid.x){
            return Direction::EAST;
        }
        else if (contours.blobs[i].centroid.y < contours.blobs[i].centroid.x && contours.blobs[i].centroid.y < h - contours.blobs[i].centroid.x){
            return Direction::NORTH;
        }
        else if (contours.blobs[i].centroid.y > contours.blobs[i].centroid.x && contours.blobs[i].centroid.y > h - contours.blobs[i].centroid.x){
            return Direction::SOUTH;
        }
    }
}

string HandRecognizer::getDirectionName() {
    Direction Direction = getDirection();
    
    if(Direction == Direction::WEST) {
        return "Left";
    }
    if(Direction == Direction::EAST) {
        return "Right";
    }
    if(Direction == Direction::NORTH) {
        return "Up";
    }
    if(Direction == Direction::SOUTH) {
        return "Down";
    }
    
    return "Loading..";
}
    

