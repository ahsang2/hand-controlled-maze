#pragma once

#include "ofMain.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include "hand_recognizer.h"
#include "SnakeFood.h"
#include "ofMain.h"
#include "snake.h"



namespace snakelinkedlist {

enum State {STARTING, PLAYING, PAUSED, IN_PROGRESS, FINISHED};

class ofApp : public ofBaseApp{
    private:
        void drawGameDisplay();
    
        ofTrueTypeFont title_font;
        ofTrueTypeFont sub_font;
        HandRecognizer recognizer;
        Gesture gesture;
        State cur_state;
        
    Snake game_snake_;  // The object that represents the user controlled snake
        SnakeFood game_food_;  // The object that represents the food pellet the
                               // user is attempting to eat with the snake
    
        bool should_update_ =
            true;
    
    void drawFood();
        void drawSnake();
        void drawGameOver();
        void drawGamePaused();
    
        // Resets the game objects to their original state.
        void reset();
    
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
}
