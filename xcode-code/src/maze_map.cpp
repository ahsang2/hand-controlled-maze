//
//  maze_map.cpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "maze_map.h"

// current maze from https://www.youtube.com/watch?v=9Ozu-B2HLY4, also used the same of display

using namespace maze;

MazeMap::MazeMap() {
    playerXCor = 7;
    playerYCor = 19;
    
    exitXCor = 40;
    exitYCor = 19;
}
void MazeMap::generateGrid() {
    
    char maze2[HEIGHT][WIDTH] = {
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W'},
        {'W',' ',' ',' ','W',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ',' ',' ','W'},
        {'W','W','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W','W','W',' ','W','W','W','W','W',' ','W',' ','W',' ','W','W','W','W','W','W','W',' ','W',' ','W'},
        {'W',' ','W',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ','W'},
        {'W',' ','W','W','W','W','W','W','W','W','W','W','W',' ','W','W','W',' ','W',' ','W','W','W',' ','W','W','W','W','W','W','W','W','W',' ','W',' ','W','W','W',' ','W'},
        {'W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ','W'},
        {'W',' ','W','W','W','W','W','W','W','W','W',' ','W',' ','W',' ','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W',' ','W','W','W','W','W',' ','W','W','W'},
        {'W',' ',' ',' ',' ',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ',' ',' ','W',' ','W',' ','W',' ',' ',' ','W',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W',' ','W',' ','W','W','W','W','W',' ','W','W','W',' ','W',' ','W','W','W','W','W','W','W',' ','W','W','W',' ','W',' ','W','W','W',' ','W'},
        {'W',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ',' ',' ','W',' ','W'},
        {'W',' ','W','W','W','W','W','W','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W',' ','W',' ','W'},
        {'W',' ','W',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ','W',' ',' ',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ','W'},
        {'W',' ','W',' ','W','W','W','W','W','W','W',' ','W','W','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W','W','W','W','W',' ','W',' ','W','W','W',' ','W',' ','W'},
        {'W',' ','W',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ','W',' ','W',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ',' ',' ','W',' ','W',' ','W',' ',' ',' ','W',' ','W'},
        {'W',' ','W','W','W',' ','W','W','W','W','W','W','W',' ','W',' ','W',' ','W','W','W','W','W',' ','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W',' ','W'},
        {'W',' ','W',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ','W',' ','W'},
        {'W',' ','W',' ','W','W','W',' ','W',' ','W','W','W','W','W','W','W','W','W','W','W',' ','W',' ','W','W','W',' ','W',' ','W',' ','W','W','W',' ','W','W','W',' ','W'},
        {'W',' ','W',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ','W',' ','W',' ',' ',' ','W',' ',' ',' ',' ',' ','W'},
        {'W',' ','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W',' ','W',' ','W','W','W','W','W','W','W',' ','W','W','W','W','W','W','W'},
        {'W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ','W',' ',' ',' ',' ',' ',' ',' ','W'},
        {'W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','W','E','W','W','W','W','W','W','W'},
        
    };
    
    for(int y=0 ; y< HEIGHT ; y++){
        for(int x=0 ; x< WIDTH ; x++){
            this->map[x][y] = maze2[y][x];
        }
    }
    
   
   // exitXCor = 39;
    //exitYCor = -19;
}

std::tuple<int,int> MazeMap::getInitPosition() {
    return {playerXCor,playerYCor};
}

std::tuple<int,int> MazeMap::getEndPosition() {
    return {exitXCor,exitYCor};
}

/*
    ***Implement random maze generator and an algorithm to check if it's solvan;e
    ***Game layout is set up to make this implementation smooth
 */