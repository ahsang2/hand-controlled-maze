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
        int xCor;
        int yCor;
        int start_squareX;
        int start_squareY;
    
    public:
        void movePlayer(Gesture &gesture, MazeMap &cur_map);
        void movePlayer(int key, MazeMap &cur_map);
        void setupPlayer(MazeMap &cur_map);
        bool foundWinner(MazeMap &cur_map);
        int getX();
        int getY();
        int getStartX();
        int getStartY();
    

};
}


