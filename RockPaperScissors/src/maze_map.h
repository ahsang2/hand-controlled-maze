//
//  maze_map.h
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once
#include <iostream>
#include <tuple>

namespace maze {
    static const int HEIGHT = 21;
    static const int WIDTH = 41;

struct MazeMap{
    
    MazeMap();
    char map[WIDTH][HEIGHT];
    void generateGrid();
    std::tuple<int,int> getInitPosition();
    std::tuple<int,int> getEndPosition();
    int exitXCor;
    int exitYCor;
    int playerXCor;
    int playerYCor;
};
}
