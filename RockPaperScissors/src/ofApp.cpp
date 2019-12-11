#include "ofApp.h"

#include <iostream>

using namespace maze;


const int HEIGHT = 21, WIDTH = 41;

// Setup method
void Maze::setup() {
    recognizer.setup();
    show_webcam = true;
    
    cur_map.generateGrid();
    maze_runner.setupPlayer(cur_map);
    
    current_state = START;
    slow_mode = false;
    ofSetBackgroundColor(0x102178255);
    ofSetWindowTitle("Maze by Hand");
    title_font.load("crushed.TTF", 50);
    sub_font.load("riffic.otf", 42);
    small_font.load("crushed.TTF", 23);
    
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
    
    if(maze_runner.foundWinner(cur_map)) {
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
            //ofSetBackgroundColor(200,200,200);
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
        recognizer.draw(ofGetWindowWidth() - 260, ofGetWindowHeight() - 180);
    }
    
    if(slow_mode && current_state == IN_PROGRESS) {
        showDirection();
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
        return;
    }
    else if(key == ' ') {
        if(current_state != IN_PROGRESS) {
            current_state = IN_PROGRESS;
        }
        else if(slow_mode) {
            processGesture();
        }
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
}


void Maze::windowResized(int w, int h) {
    //game_food_.resize(w, h);
    //game_snake_.resize(w, h);
}

//-------------------Helper methods---------------------
void Maze::reset() {
    maze_runner.setupPlayer(cur_map);
    current_state = IN_PROGRESS;
}

void Maze::drawGameOver() {
   ofSetColor(0, 0, 0);
   title_font.drawString("Good Job", ofGetWindowWidth() / 4, ofGetWindowHeight() / 2);
}

void Maze::drawGamePaused() {
    ofSetColor(0, 0, 0);
    title_font.drawString("Game Paused", ofGetWindowWidth() / 7, ofGetWindowHeight() - 100);
    drawInstructions();
}

void Maze::drawInstructions() {
    string str = "How to play: \n Space - Play \n P - Pause \n F - fullscreen \n W - webcam \n R - Reset \n S - slow mode";
    small_font.drawString(str, ofGetWindowWidth() / 3, ofGetWindowHeight() / 14);
}

void Maze::showDirection() {
    ofSetColor(0,0,0);
    ofDrawBitmapString("Slow mode on | Current Direction: ", 100, 100);
    small_font.drawString("direction", 400, 100);
    small_font.drawString("Press space to move", 50, ofGetWindowHeight() - 100);
}

void Maze::mousePressed(int x, int y, int button){
    recognizer.mousePressed(x, y, button);
} 

void Maze::processGesture() {
    maze_runner.movePlayer(gesture, cur_map);
    
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
    ofTranslate(maze_runner.getX()*5-100,-maze_runner.getY()*5+50,1);
    ofSetColor(255,255,255);
    ofFill();
    ofBox(4);
    ofNoFill();
    ofSetColor(0);
    ofBox(4);
    ofPopMatrix();
}


