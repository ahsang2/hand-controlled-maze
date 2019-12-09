#pragma once
#include <cstdlib>
#include <ctime>
#include <utility>

#include "SnakeFood.h"
#include "ofMain.h"
#include "snake.h"
#include "hand_recognizer.h"
#include "maze_map.h"

namespace maze {

// Enum to represent the current state of the game
enum GameState {START = 0, IN_PROGRESS, PAUSED, FINISHED };


class Maze : public ofBaseApp {
private:
    GameState current_state_;  // The current state of the game, used to determine
                        // possible actions
    Snake game_snake_;  // The object that represents the user controlled snake
    SnakeFood game_food_;  // The object that represents the food pellet the
                           // user is attempting to eat with the snake

    bool should_update_ =
        true;  // A flag boolean used in the update() function. Due to the frame
               // dependent animation we've written, and the relatively low
               // framerate, a bug exists where users can prefire direction
               // changes faster than a frame update. Our solution is to force a
               // call to update on direction changes and then not update on the
               // next frame to prevent the snake from skipping across the
               // screen.

    // Private helper methods to render various aspects of the game on screen.
    void drawFood();
    void drawSnake();
    void drawGameOver();
    void drawGamePaused();
    void processGesture();

    // Resets the game objects to their original state.
    void reset();
    
    ofTrueTypeFont title_font;
    ofTrueTypeFont sub_font;
    HandRecognizer recognizer;
    Gesture gesture;
    ofEasyCam cam;

public:
    // Function used for one time setup
    void setup();

    // Main event loop functions called on every frame
    void update();
    void draw();

    // Event driven functions, called on appropriate user action
    void keyPressed(int key);
    void windowResized(int w, int h);
    void mousePressed(int x, int y, int button);
};
}  // namespace snakelinkedlist
