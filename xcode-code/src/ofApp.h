#pragma once
#include <cstdlib>
#include <ctime>
#include <utility>

#include "ofMain.h"
#include "map.h"
#include "player.h"
#include "hand_recognizer.h"


namespace maze {

// Enum to represent the current state of the game
enum GameState {START = 0, IN_PROGRESS, PAUSED, FINISHED };

class Maze : public ofBaseApp {
private:
    GameState current_state;  // The current state of the game, used to determine
                        // possible actions

    bool should_update = true;  // A flag boolean used in the update() function. Due to the frame
               // dependent animation we've written, and the relatively low
               // framerate, a bug exists where users can prefire direction
               // changes faster than a frame update. Our solution is to force a
               // call to update on direction changes and then not update on the
               // next frame to prevent the snake from skipping across the
               // screen.

    bool show_webcam;
    bool slow_mode;
    bool key_mode;
    // Private helper methods to render various aspects of the game on screen.
    void drawGameOver();
    void drawGamePaused();
    void drawInstructions();
    void processDirection();
    void drawWalls();
    void drawPlayer();
    void showDirection();
    void useArrowKeys(int key);

    // Resets the game objects to their original state.
    void reset();
    
    ofTrueTypeFont title_font;
    ofTrueTypeFont sub_font;
    ofTrueTypeFont small_font;
    HandRecognizer recognizer;
    Direction direction;
    ofEasyCam virtual_cam;
    Map cur_map;
    Player maze_runner;

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
