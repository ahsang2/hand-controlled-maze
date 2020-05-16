//
//  maze_map.cpp
//
//
//  Created by Ahsan Gilani on 12/9/19.
//

#include "map.h"



using namespace maze;

Map::Map() {
    playerXCor = 1;  //7;
    playerYCor = 1;  // 19;
    
    maze.makeMaze(WIDTH/2, HEIGHT/2);
    right_walls = maze.getRightWalls();
    down_walls = maze.getDownWalls();
}

void Map::generateGrid() {
    int row = 0;
    
    //top edge walls
    map.push_back(vector<char>());
    for(int i = 0; i < WIDTH+2; i++) {
        map[row].push_back('W');
    }
    
    row++;
    
    for(int level = 0; level < HEIGHT/2; level++) {
        //add 2 rows (one for tiles, other for walls)
        map.push_back(vector<char>());
        map.push_back(vector<char>());
        
        //left edge walls
        map[row].push_back('W');
        map[row+1].push_back('W');
        
        for(int tile = 0; tile < WIDTH/2; tile++) {
            int tile_cord = maze.getTileValue(tile, level);
            map[row].push_back(' ');
            
            if(right_walls[tile_cord] == false)
                map[row].push_back(' ');
            else
                map[row].push_back('W');
            
            if(down_walls[tile_cord] == false)
                map[row+1].push_back(' ');
            else
                map[row+1].push_back('W');
            
            map[row+1].push_back('W');
        }
        
        //right edge walls - taken care of
        //map[row].push_back('W');
       // map[row+1].push_back('W');
        
        //update position for next iteration
        row += 2;
    }

    //bottom edge walls - taken care of
   /* map.push_back(vector<char>());
    for(int i = 0; i < WIDTH+2; i++) {
        map[row].push_back('W');
    }*/
    
    maze.solveMaze();
    exitXCor = maze.getExitTile() % (WIDTH/2);
    exitXCor = 1+(exitXCor*2);
    exitYCor = map.size() - 1;
    map[exitYCor][exitXCor] = 'E';
}

std::tuple<int,int> Map::getInitPosition() {
    return {playerXCor,playerYCor};
}

std::tuple<int,int> Map::getEndPosition() {
    return {exitXCor,exitYCor};
}

/*
    ***Implement random maze generator and an algorithm to check if it's solvan;e
    ***Game layout is set up to make this implementation smooth
 */
