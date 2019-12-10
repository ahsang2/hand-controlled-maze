//
//  maze_map.h
//  RockPaperScissors
//
//  Created by Ahsan Gilani on 12/9/19.
//

#pragma once


namespace maze {

class MazeMap{
    private:
      
       
    
    public:
        
        char map[41][21];
        void generateGrid();
        int posX;
        int posY;
        int exitPosX;
        int exitPosY;
        

    
};
}
