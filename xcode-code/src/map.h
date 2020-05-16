//
//  maze_map.h
//  
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once
#include <iostream>
#include <tuple>
#include <vector>
#include "maze.h"

using std::vector;
namespace maze {
    static const int HEIGHT = 20;
    static const int WIDTH = 40;

struct Map{
    
        Map();
        vector<vector<char>> map;
        void generateGrid();
        std::tuple<int,int> getInitPosition();
        std::tuple<int,int> getEndPosition();
    
    private:
        vector<bool> right_walls;
        vector<bool> down_walls;
        SquareMaze maze;
        int exitXCor;
        int exitYCor;
        int playerXCor;
        int playerYCor;
    
};
}
