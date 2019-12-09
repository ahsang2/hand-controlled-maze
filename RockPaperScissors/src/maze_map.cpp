//
//  maze_map.cpp
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "maze_map.h"

const char HEIGHT = 21;
const char WIDTH = 41;

void generateGrid() {
    unsigned char maze[WIDTH][HEIGHT];
    
    unsigned char maze2[HEIGHT][WIDTH] = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
        {'#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#'},
        {'#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#'},
        {'#',' ','#','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#','#','#',' ','#','#','#','#','#','#','#'},
        {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','E','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        
    };
    
    for(int y=0 ; y< HEIGHT ; y++){
        for(int x=0 ; x< WIDTH ; x++){
            maze[x][y] = maze2[y][x];
        }
    }
    
}
