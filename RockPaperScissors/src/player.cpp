//
//  player.cpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "player.h"

using namespace maze;

void Player::setupPlayer(MazeMap &cur_map) {
    this->start_squareX = get<0>(cur_map.getInitPosition());
    this->start_squareY = get<1>(cur_map.getInitPosition());
    this->xCor = get<0>(cur_map.getInitPosition());
    this->yCor = get<1>(cur_map.getInitPosition());
}

void Player::movePlayer(Gesture &gesture, MazeMap &cur_map) {
    if(gesture == SOUTH) {
        //move down
        if (cur_map.map[xCor][yCor+1] != 'W') {
            yCor++;
        //    cout << "down" << endl;
        }
    }
    else if(gesture == WEST) {
        //move left
        if (cur_map.map[xCor-1][yCor] != 'W') {
            xCor--;;
        //    cout << "left" << endl;

        }
    }
    else if(gesture == EAST) {
        //move right
        if (cur_map.map[xCor+1][yCor] != 'W') {
            xCor++;
         //   cout << "right" << endl;

        }
    }
    else if(gesture == NORTH){
               //move up
        if (cur_map.map[xCor][yCor-1] != 'W') {
            yCor--;
           // cout << "up" << endl;
           }
    }
    
    gesture = NOWHERE;
}

void Player::movePlayer(int key, MazeMap &cur_map) {
    if(key == OF_KEY_DOWN) {
        //move down
        if (cur_map.map[xCor][yCor+1] != 'W') {
            yCor++;
            //cout << "down" << endl;
        }
    }
    else if(key == OF_KEY_LEFT) {
        //move left
        if (cur_map.map[xCor-1][yCor] != 'W') {
            xCor--;;
            //cout << "left" << endl;

        }
    }
    else if(key == OF_KEY_RIGHT) {
        //move right
        if (cur_map.map[xCor+1][yCor] != 'W') {
            xCor++;
           // cout << "right" << endl;

        }
    }
    else if(key == OF_KEY_UP){
               //move up
        if (cur_map.map[xCor][yCor-1] != 'W') {
            yCor--;
            //cout << "up" << endl;
           }
    }
}

bool Player::foundWinner(MazeMap &cur_map) {
    return xCor == get<0>(cur_map.getEndPosition()) && yCor == get<1>(cur_map.getEndPosition());
}

int Player::getX() {
    return xCor;
}

int Player::getY() {
    return yCor;
}

int Player::getStartX() {
    return start_squareX;
}

int Player::getStartY() {
    return start_squareY;
}
