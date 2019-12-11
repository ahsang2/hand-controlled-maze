//
//  player.hpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once

#include <stdio.h>
#include "hand_recognizer.h"
#include "maze_map.h"

namespace maze {

class Player {
    private:
        int posX;
        int posY;
        int start_squareX;
        int start_squareY;
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();
    
    public:
        void movePlayer(Gesture &gesture);
        void setupPlayer();
        int getX();
        int getY();
        int getStartX();
        int getStartY();
    

};
}


