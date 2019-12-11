#include "ofApp.h"

#include <iostream>

using namespace maze;


const int HEIGHT = 21, WIDTH = 41;
const int WINDOWx = 1024, WINDOWy = 768;

// Setup method
void Maze::setup() {
    recognizer.setup();
    show_webcam = true;
    
    cur_map.generateGrid();
    cur_player = cur_map.maze_runner;
    cur_player.setupPlayer();
    
    current_state = START;
    slow_mode = false;
    ofSetBackgroundColor(0x102178255);
    ofSetWindowTitle("Maze by Hand");
    title_font.load("crushed.TTF", 50);
    sub_font.load("riffic.otf", 42);
    
    virtual_cam.setDistance(150);
}

/*
Update function called before every draw
If the function should update when it is called it will:
1. Check to see if the game is in progress, if it is paused or over it should
not update.
2. Check to see if the current head of the snake intersects the food pellet. If
so:
    * The snake should grow by length 1 in its current direction
    * The food should be moved to a new random location
3. Update the snake in the current direction it is moving
4. Check to see if the snakes new position has resulted in its death and the end
of the game
*/
void Maze::update() {
    recognizer.update();
    gesture = recognizer.getGesture();
    cout << gesture << endl;
    
    if(current_state == IN_PROGRESS && should_update && !slow_mode)
     {
        processGesture();
    }
    
    if(cur_map.foundWinner()) {
        current_state = FINISHED;
    }
    
    should_update = true;
}

/*
Draws the current state of the game with the following logic
1. If the game is paused draw the pause screen
2. If the game is finished draw the game over screen and final score
3. Draw the current position of the food and of the snake
*/
void Maze::draw() {
    switch(current_state) {
        case(START):
            ofSetHexColor(0x636363);
            title_font.drawString("The Maze Game", 40, 100);
            sub_font.drawString("Press Space To Start", 220, 600);
            return;
            
        case(IN_PROGRESS):
            ofSetBackgroundColor(200,200,200);
            virtual_cam.begin();
            drawWalls();
            drawPlayer();
            virtual_cam.end();
            break;
  
        case(PAUSED):
            drawGamePaused();
            break;
            
        case(FINISHED):
            drawGameOver();
            break;
            
        default:
            break;
    }
    
    if(show_webcam && current_state == IN_PROGRESS) {
        recognizer.draw(WINDOWx - 320, WINDOWy - 240);
    }
}

/*
Function that handles actions based on user key presses
1. if key == F12, toggle fullscreen
2. if key == p and game is not over, toggle pause
3. if game is in progress handle WASD action
4. if key == r and game is over reset it

WASD logic:
Let dir be the direction that corresponds to a key
if current direction is not dir (Prevents key spamming to rapidly update the
snake) and current_direction is not opposite of dir (Prevents the snake turning
and eating itself) Update direction of snake and force a game update (see
ofApp.h for why)
*/
void Maze::keyPressed(int key) {
    int upper_key = toupper(key);
    
    if (upper_key == OF_KEY_F12) {
        ofToggleFullscreen();
        return;
    }
    else if(current_state != START && upper_key == 'P')
    {
        current_state = PAUSED;
    }
    else if(key == ' ') {
        current_state = IN_PROGRESS;
    }
    else if(upper_key == 'F') {
        ofToggleFullscreen();
    }
    else if(upper_key == 'M') {
        if(virtual_cam.getMouseInputEnabled()) virtual_cam.disableMouseInput();
        else virtual_cam.enableMouseInput();
    }
    else if(upper_key == 'W') {
        show_webcam = !show_webcam;
    }
    else if(upper_key == 'S') {
        slow_mode = !slow_mode;
    }
    else if(upper_key == 'R') {
        reset();
    }
    
    if(current_state == PAUSED) {
        current_state = IN_PROGRESS;
    }
    else if(current_state == IN_PROGRESS && slow_mode) {
        processGesture();
    }
}


void Maze::windowResized(int w, int h) {
    //game_food_.resize(w, h);
    //game_snake_.resize(w, h);
}

//-------------------Helper methods---------------------
void Maze::reset() {
    cur_map.resetMap();
    current_state = IN_PROGRESS;
}

void Maze::drawGameOver() {
   ofSetColor(0, 0, 0);
   title_font.drawString("Good Job", ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

void Maze::drawGamePaused() {
    ofSetColor(0, 0, 0);
    title_font.drawString("Paused", ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

void Maze::mousePressed(int x, int y, int button){
    recognizer.mousePressed(x, y, button);
} 

void Maze::processGesture() {
    cur_player.movePlayer(gesture);
    
    
    should_update = false;
}

void Maze::drawWalls() {
    for(int y=0 ; y< HEIGHT ; y++){
        for(int x=0 ; x< WIDTH ; x++){
            
            if (cur_map.map[x][y] != ' '){
                if (cur_map.map[x][y] == 'E') {
                    ofSetColor(153,255,153);
                }
                else {
                    ofSetColor(63.0,63.0,63.0);
                }
                
                ofPushMatrix();
                ofTranslate(x*5-100,-y*5+50,0);
                ofFill();
                ofBox(5);
                ofNoFill();
                ofSetColor(0);
                ofBox(5);
                ofPopMatrix();
            }
            
        }
    }
}

void Maze::drawPlayer() {
    ofPushMatrix();
    ofTranslate(cur_player.getX()*5-100,-cur_player.getY()*5+50,1);
    ofSetColor(255,255,255);
    ofFill();
    ofBox(4);
    ofNoFill();
    ofSetColor(0);
    ofBox(4);
    ofPopMatrix();
}


