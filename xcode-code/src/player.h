//
//  player.hpp
//  
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once

#include <stdio.h>
#include "hand_recognizer.h"
#include "map.h"

namespace maze {

class Player {
    private:
        int xCor;
        int yCor;
        int start_squareX;
        int start_squareY;
    
    public:
        void movePlayer(Direction &direction, Map &cur_map);
        void movePlayer(int key, Map &cur_map);
        void setupPlayer(Map &cur_map);
        bool foundWinner(Map &cur_map);
        int getX();
        int getY();
        int getStartX();
        int getStartY();
    

};
}


