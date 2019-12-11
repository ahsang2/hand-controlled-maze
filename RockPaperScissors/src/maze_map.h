//
//  maze_map.h
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once

#include "player.h"

namespace maze {
    static const int HEIGHT = 21;
    static const int WIDTH = 41;

struct MazeMap{
        
    char map[WIDTH][HEIGHT];
    void generateGrid();
    Player maze_runner;
    int exitXCor;
    int exitYCor;
    void resetMap();
    bool foundWinner();
};
}
