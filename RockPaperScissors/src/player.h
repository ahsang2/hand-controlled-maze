//
//  player.hpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once

#include <stdio.h>

namespace maze {

class Player {
    private:
        int posX;
        int posY;
        int start_squareX;
        int start_squareY;
    
    public:
        void moveLeft();
        void moveRight();
        void moveDown();
        void moveUp();
    

};
}


