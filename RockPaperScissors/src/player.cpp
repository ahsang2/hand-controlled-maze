//
//  player.cpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "player.h"

using namespace maze;

void Player::setupPlayer() {
    this->start_squareX = 7;
    this->start_squareY = 19;
    this->posX = 7;
    this->posY = 19;
}

void Player::movePlayer(Gesture &gesture, MazeMap &cur_map) {
    if(gesture == SOUTH) {
        //move down
        if (cur_map.map[cur_player.getX()][cur_player.getY()+1] != '#') {
            this->moveUp();
            cout << "up" << endl;
        }
    }
    else if(gesture == WEST) {
        //move left
        if (cur_map.map[cur_player.getX()-1][cur_player.getY()] != '#') {
            cur_player.moveLeft();
            cout << "left" << endl;

        }
    }
    else if(gesture == EAST) {
        //move right
        if (cur_map.map[cur_player.getX()+1][cur_player.getY()] != '#') {
            cur_player.moveRight();
            cout << "right" << endl;

        }
    }
    else if(gesture == NORTH){
               //move up
        if (cur_map.map[cur_player.getX()][cur_player.getY()-1] != '#') {
            cur_player.moveDown();
            cout << "down" << endl;
           }
    }
    
    gesture = NOWHERE;
}
void Player::moveLeft() {
    posX--;
}

void Player::moveRight() {
    posX++;
}

void Player::moveDown() {
    posY--;
}

void Player::moveUp() {
    posY++;
}

int Player::getX() {
    return posX;
}

int Player::getY() {
    return posY;
}

int Player::getStartX() {
    return start_squareX;
}

int Player::getStartY() {
    return start_squareY;
}
