#include "ofApp.h"

#include <iostream>

using namespace maze;


const int HEIGHT = 21, WIDTH = 41;

// Setup method
void Maze::setup() {
    current_state_ = START;
    title_font.load("BD.TTF", 80);
    sub_font.load("riffic.otf", 42);
    
    recognizer.setup();
    ofSetBackgroundColor(200,200,200);
    ofSetWindowTitle("Maze by Hand");

    srand(static_cast<unsigned>(time(0)));  // Seed random with current time
    cam.setDistance(150);
    cur_map.generateGrid();
    cur_map.posX = 7;
    cur_map.posY = 19;
    cur_map.exitPosX = 39;
    cur_map.exitPosY = -19;
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
    /*
    if (should_update_) {
        if (current_state_ == IN_PROGRESS) {
            ofVec2f snake_body_size = game_snake_.getBodySize();
            ofVec2f head_pos = game_snake_.getHead()->position;
            ofRectangle snake_rect(head_pos.x, head_pos.y, snake_body_size.x,
                                   snake_body_size.y);

            if (snake_rect.intersects(game_food_.getFoodRect())) {
                game_snake_.eatFood(game_food_.getColor());
                game_food_.rebase();
            }
            game_snake_.update();

            if (game_snake_.isDead()) {
                current_state_ = FINISHED;
            }
        }
        
        processGesture();
    }

    should_update_ = true;*/
}

/*
Draws the current state of the game with the following logic
1. If the game is paused draw the pause screen
2. If the game is finished draw the game over screen and final score
3. Draw the current position of the food and of the snake
*/
void Maze::draw() {
    switch(current_state_) {
        case(START):
            title_font.drawString("Rock Paper Scissors", 40, 100);
            sub_font.drawString("Press Space To Start", 220, 600);
            return;
            
        case(IN_PROGRESS): {
      
            cam.begin();
            //recognizer.draw();
            for(int y=0 ; y< HEIGHT ; y++){
                for(int x=0 ; x< WIDTH ; x++){
                    
                    if (cur_map.map[x][y] == ' ') {
                        title_font.drawString("maze", 40, 100);
                        ofPushMatrix();
                        ofTranslate(cur_map.exitPosX * 5 - 100, cur_map.exitPosY * 5 + 50,1);
                        ofSetColor(255, 0, 0);
                        ofFill();
                        ofBox(4);
                        ofNoFill();
                        ofSetColor(0);
                        ofBox(4);
                        ofPopMatrix();
                    }
                    
                    

                   
    
                    
                    if (cur_map.map[x][y] == '#'){
                        
                        ofPushMatrix();
                        ofTranslate(x*5-100,-y*5+50,0);
                        ofSetColor(63.0,63.0,63.0);
                        ofFill();
                        ofBox(5);
                        ofNoFill();
                        ofSetColor(0);
                        ofBox(5);
                        ofPopMatrix();
                    }
                    
                    

                    
                   // cout << cur_map.map[x][y];
                     
                   
                    

                }
              //  cout << endl;
            }
            ofPushMatrix();
            ofTranslate(cur_map.posX*5-100,-cur_map.posY*5+50,1);
            ofSetColor(255,255,255);
            ofFill();
            ofBox(4);
            ofNoFill();
            ofSetColor(0);
            ofBox(4);
            ofPopMatrix();
            
            cam.end();
            break;
                     
                    //Declare color
                                       
            /*
            ofSetColor(130, 100, 70);
            drawGameDisplay();
            sub_font.drawString("Rock", 200, 100);
            recognizer.draw();
            if(gesture == ROCK) {
                ofDrawBitmapString("rock", 120, 300);
            }
            if(gesture == PAPER) {
                ofDrawBitmapString("paper", 120, 300);
            }
            if(gesture == SCISSORS) {
                ofDrawBitmapString("scissors", 120, 300);
            }
             ofColor c;

                                switch (cur_map.map[x][y])
                                {
                                case ' ':
                                    c.r = 255;
                                    c.g = 0;
                                    c.b = 0;
                                    break;
                                case '#':
                                    c.r = 0;
                                    c.g = 255;
                                    c.b = 0;
                                    break;
                                }

                                ofSetColor(c);
                                ofDrawRectangle((x * 11) + 11/2, (y * 11) + 11/2, 11, 11);
             */
                    
                   
            
        }
            
        case(PAUSED):
            drawGamePaused();
            title_font.drawString("Paused", 267, 450);
            break;
            
        case(FINISHED):
            drawGameOver();
            break;
            
        default:
            break;
    }
    
    //drawFood();
    //drawSnake();
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
    
    if (key == OF_KEY_F12) {
        ofToggleFullscreen();
        return;
    }
    if(current_state_ != START && key == 'p')
    {
        current_state_ = PAUSED;
    }
    else if(key == ' ') {
        current_state_ = IN_PROGRESS;
    }
    else if(current_state_ == PAUSED) {
        current_state_ = IN_PROGRESS;
    }
    /*
     if (current_state_ == IN_PROGRESS) {
        SnakeDirection current_direction = game_snake_.getDirection();

        // If current direction has changed to a valid new one, force an
        // immediate update and skip the next frame update
        if (upper_key == 'W' && current_direction != DOWN &&
            current_direction != UP) {
            game_snake_.setDirection(UP);
            update();
            should_update_ = false;
        } else if (gesture == WEST && current_direction != RIGHT &&
                   current_direction != LEFT) {
            game_snake_.setDirection(LEFT);
            update();
            should_update_ = false;
        } else if ((upper_key == 'S') && current_direction != UP &&
                   current_direction != DOWN) {
            game_snake_.setDirection(DOWN);
            update();
            should_update_ = false;
        } else if (gesture == EAST && current_direction != LEFT &&
                   current_direction != RIGHT) {
            game_snake_.setDirection(RIGHT);
            update();
            should_update_ = false;
        }
    }
     else if (upper_key == 'R' && current_state_ == FINISHED) {
        reset();
    }
    */
    if(current_state_ == IN_PROGRESS) {
        
    switch(key) {
            case 'a':
                //move left
                if (cur_map.map[cur_map.posX-1][cur_map.posY] != '#') {
                    cur_map.posX--;
                }
                break;
            case 'd':
                //move right
                if (cur_map.map[cur_map.posX+1][cur_map.posY] != '#') {
                    cur_map.posX++;
                }
                break;
            case 'w':
                //move up
                if (cur_map.map[cur_map.posX][cur_map.posY-1] != '#') {
                    cur_map.posY--;;
                }
                break;
            case 's':
                //move down
                if (cur_map.map[cur_map.posX][cur_map.posY+1] != '#') {
                    cur_map.posY++;
                }
                break;
                
            case 'M':
            case 'm':
                if(cam.getMouseInputEnabled()) cam.disableMouseInput();
                else cam.enableMouseInput();
                break;
                
            case 'F':
            case 'f':
                ofToggleFullscreen();
                break;
        }
    }

    }


void Maze::windowResized(int w, int h) {
    game_food_.resize(w, h);
    game_snake_.resize(w, h);
}

//-------------------Helper methods---------------------
void Maze::reset() {
    game_snake_ = Snake();
    game_food_.rebase();
    current_state_ = IN_PROGRESS;
}

void Maze::drawFood() {
    ofSetColor(game_food_.getColor());
    ofDrawRectangle(game_food_.getFoodRect());
}

void Maze::drawSnake() {
    ofVec2f snake_body_size = game_snake_.getBodySize();
    ofVec2f head_pos = game_snake_.getHead()->position;
    ofSetColor(game_snake_.getHead()->color);
    ofDrawRectangle(head_pos.x, head_pos.y, snake_body_size.x,
                    snake_body_size.y);

    for (SnakeBody* curr = game_snake_.getHead(); curr != NULL;
         curr = curr->next) {
        ofVec2f currPos = curr->position;
        ofSetColor(curr->color);
        ofDrawRectangle(currPos.x, currPos.y, snake_body_size.x,
                        snake_body_size.y);
    }
}

void Maze::drawGameOver() {
    string total_food = std::to_string(game_snake_.getFoodEaten());
    string lose_message = "You Lost! Final Score: " + total_food;
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(lose_message, ofGetWindowWidth() / 2,
                       ofGetWindowHeight() / 2);
}

void Maze::drawGamePaused() {
    string pause_message = "P to Unpause!";
    ofSetColor(0, 0, 0);
    ofDrawBitmapString(pause_message, ofGetWindowWidth() / 2,
                       ofGetWindowHeight() / 2);
}

void Maze::mousePressed(int x, int y, int button){
    recognizer.mousePressed(x, y, button);
}

void Maze::processGesture() {
    if(gesture == EAST) {
      //  cout << "left" << endl;
    }
    if(gesture == WEST) {
      //  cout << "right" << endl;
    }
}
