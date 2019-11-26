#include "ofMain.h"
#include "ofApp.h"

//========================================================================
using namespace std;
using namespace cv;

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
    
    /*Mat image;
    VideoCapture cap;
    cap.open(0);
    namedWindow("window", 1);
    while (1){
        cap >> image;
        imshow("window", image);
        waitKey(33);
    }*/
    return 0;
    
}
