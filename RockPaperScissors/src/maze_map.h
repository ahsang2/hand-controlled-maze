//
//  maze_map.h
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once

#include "player.h"

namespace maze {

struct MazeMap{
        
    char map[41][21];
    void generateGrid();
    Player maze_runner;
    int exitXCor;
    int exitYCor;
        

    
};
}
