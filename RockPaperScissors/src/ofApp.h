
/*
#include "ofMain.h"
#include <cstdlib>
#include <ctime>
#include <utility>
//#include "hand_recognizer.h"
#include "SnakeFood.h"
#include "ofMain.h"
#include "snake.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include <stdio.h>
#include "SnakeFood.h"
#include "ofMain.h"
#include "snake.h"*/
#pragma once
#include <cstdlib>
#include <ctime>
#include <utility>

#include "SnakeFood.h"
#include "ofMain.h"
#include "snake.h"



namespace snakelinkedlist {

enum State {STARTING, PLAYING, PAUSED, IN_PROGRESS, FINISHED};

class ofApp : public ofBaseApp{
    private:
       // void drawGameDisplay();
    
        ofTrueTypeFont title_font;
        ofTrueTypeFont sub_font;
      //  HandRecognizer recognizer;
      //  Gesture gesture;
        State current_state_;
        
    Snake game_snake_;  // The object that represents the user controlled snake
        SnakeFood game_food_;  // The object that represents the food pellet the
                               // user is attempting to eat with the snake
    
        bool should_update_ = true;
    
    void drawFood();
        void drawSnake();
        void drawGameOver();
        void drawGamePaused();
    
        // Resets the game objects to their original state.
        void reset();
    
	public:
		void setup();
        
            // Main event loop functions called on every frame
            void update();
            void draw();
        
            // Event driven functions, called on appropriate user action
            void keyPressed(int key);
            void windowResized(int w, int h);

};
}
