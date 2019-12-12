#include "ofMain.h"
#include "ofApp.h"
#include "opencv2/imgproc.hpp"

//========================================================================
using namespace std;

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);
    //ofSetupOpenGL(640, 480, DISPLAY_MODE);// <-------- setup the GL context
    ofSetFrameRate(12);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new maze::Maze());
    
    return 0;
    
}
