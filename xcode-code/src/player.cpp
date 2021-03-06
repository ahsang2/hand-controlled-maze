//
//  player.cpp
//  
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "player.h"

using namespace maze;

void Player::setupPlayer(Map &cur_map) {
    this->start_squareX = get<0>(cur_map.getInitPosition());
    this->start_squareY = get<1>(cur_map.getInitPosition());
    this->xCor = get<0>(cur_map.getInitPosition());
    this->yCor = get<1>(cur_map.getInitPosition());
}

void Player::movePlayer(Direction &direction, Map &cur_map) {
    if(direction == SOUTH) {
        //move down
        if (cur_map.map[yCor+1][xCor] != 'W') {
            yCor++;
        //    cout << "down" << endl;
        }
    }
    else if(direction == WEST) {
        //move left
        if (cur_map.map[yCor][xCor-1] != 'W') {
            xCor--;;
        //    cout << "left" << endl;

        }
    }
    else if(direction == EAST) {
        //move right
        if (cur_map.map[yCor][xCor+1] != 'W') {
            xCor++;
         //   cout << "right" << endl;

        }
    }
    else if(direction == NORTH){
               //move up
        if (cur_map.map[yCor-1][xCor] != 'W') {
            yCor--;
           // cout << "up" << endl;
           }
    }
    
    direction = NOWHERE;
}

void Player::movePlayer(int key, Map &cur_map) {
    if(key == OF_KEY_DOWN) {
        //move down
        if (cur_map.map[yCor+1][xCor] != 'W') {
            yCor++;
            //cout << "down" << endl;
        }
    }
    else if(key == OF_KEY_LEFT) {
        //move left
        if (cur_map.map[yCor][xCor-1] != 'W') {
            xCor--;;
            //cout << "left" << endl;

        }
    }
    else if(key == OF_KEY_RIGHT) {
        //move right
        if (cur_map.map[yCor][xCor+1] != 'W') {
            xCor++;
           // cout << "right" << endl;

        }
    }
    else if(key == OF_KEY_UP){
               //move up
        if (cur_map.map[yCor-1][xCor] != 'W') {
            yCor--;
            //cout << "up" << endl;
           }
    }
}

bool Player::foundWinner(Map &cur_map) {
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
