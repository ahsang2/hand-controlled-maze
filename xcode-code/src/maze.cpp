//
//  maze.cpp
//  Maze
//
//  Created by Ahsan Gilani on 5/15/20.
//

#include "maze.h"

void SquareMaze::makeMaze(int width, int height) {
    w = width;
    h = height;

    DisjointSets connections;
    connections.addelements(width*height);
    vector<tuple<int, int>> rightWalls;
    vector<tuple<int, int>> bottomWalls;
    setLists(rightWalls, bottomWalls);

    int choose = -1;

    while(connections.size(0) != width * height) {
        if(choose < 0) {
            int curx = std::get<0>(rightWalls[rightWalls.size() - 1] );
            int y = std::get<1>(rightWalls[rightWalls.size() - 1] );
            int rightx = curx + 1;
            
            if(getTileValue(rightx, y) != -1 && connections.find(getTileValue(curx, y)) != connections.find(getTileValue(rightx, y))) {
                setWall(curx, y, 0, false);
                connections.setunion(getTileValue(curx,y), getTileValue(rightx, y));
            }

            rightWalls.pop_back();
        }
        else {
            int x = std::get<0>(bottomWalls[bottomWalls.size() - 1]) ;
            int cury = std::get<1>(bottomWalls[bottomWalls.size() - 1]) ;;
            int bottomy = cury + 1;

            if(getTileValue(x, bottomy) != -1 && connections.find(getTileValue(x, cury)) != connections.find(getTileValue(x, bottomy))) {
                setWall(x, cury, 1, false);
                connections.setunion(getTileValue(x,cury), getTileValue(x, bottomy));
            }


            bottomWalls.pop_back();
        }

        choose *= -1;
    }

}

void SquareMaze::setLists(vector<tuple<int, int>> &rightWalls, vector<tuple<int, int>> &bottomWalls) {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            rightWalls.push_back(tuple<int,int>(i,j));
            bottomWalls.push_back(tuple<int,int>(i,j));
        }
    }

    right_ = vector<bool>(w*h, true);
    down_ = vector<bool>(w*h, true);
    

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle (rightWalls.begin(), rightWalls.end(), g);
    std::shuffle (bottomWalls.begin(), bottomWalls.end(), g);
}

int SquareMaze::getTileValue(int x, int y) const{
    if(x >= w || y >= h || x < 0 || y < 0)
        return -1;

    return y*w + x;
}

int SquareMaze::tileToMoveTo(int elem, int dir) {
        int x = elem % w;
        int y = elem / w;
        int next = 0;

        if(dir == 0 && canTravel(x,y,dir)) {
            next = getTileValue(x+1, y);
            return visited_[next] ? -1 : next;
        }
        else if(dir == 1  && canTravel(x,y,dir)) {
            next = getTileValue(x, y+1);
            return visited_[next] ? -1 : next;
        }
        else if(dir == 2  && canTravel(x,y,dir)) {
            next = getTileValue(x-1, y);
            return visited_[next] ? -1 : next;
        }
        else if(dir == 3  && canTravel(x,y,dir)) {
            next = getTileValue(x, y-1);
            return visited_[next] ? -1 : next;
       }

    return -1;
}

bool SquareMaze::canTravel (int x, int y, int dir) const {
    int curTile = getTileValue(x,y);
    
        if(dir == 0) {
            return !right_[curTile];
        }

        if(dir == 1) {
            return !down_[curTile];
        }

        if(dir == 2) {
            curTile = getTileValue(x-1, y);
            return (curTile != -1) && !right_[curTile];
        }

        if(dir == 3) {
            curTile = getTileValue(x, y-1);
            return (curTile != -1) && !down_[curTile];
        }

         return false;
}
       
 void SquareMaze::setWall (int x, int y, int dir, bool exists) {
     //0 is right,  1 is down
     if(dir == 0) {
         right_[getTileValue(x,y)] = exists;
     }
     else if(dir == 1) {
         down_[getTileValue(x,y)] = exists;
     }
}

std::vector<int> SquareMaze::solveMaze () {
    std::vector<int> path;
    visited_ = vector<bool>(w*h, false);
    pd_ = vector<tuple<int,int>>(w*h);

    dfs(0,0,0);
   
    int dist = std::get<1>(pd_[pd_.size() - 1]);
    unsigned index = pd_.size()-1;

    for(unsigned i = pd_.size() - 2; i > pd_.size() - 1 - w; i--) {
        if(std::get<1>(pd_[i]) >= dist) {
            dist = std::get<1>(pd_[i]);
            index = i;
        }
    }

    
    int idx = index;
    dest_tile = idx;

    while(idx != 0) {
        int prev = std::get<0>(pd_[idx]);
        if(prev == idx - 1) {
            path.insert(path.begin(), 0);
        }
        else if(prev == idx + 1) {
            path.insert(path.begin(), 2);
        }
        else if(prev < idx) {
            path.insert(path.begin(), 1);
        }
        else if (idx < prev) {
            path.insert(path.begin(), 3);
        }

        idx = prev;
    }


    return path;
}

void SquareMaze::dfs(int elem, int prev, int dist) {
    visited_[elem] = true;
    pd_[elem] = tuple<int,int>(prev, dist);

    for(int i = 0; i < 4; i++) {
        int next = tileToMoveTo(elem, i);
        if(next != -1 ) {
            dfs(next, elem, dist+1);
        }
    }

}

int SquareMaze::getExitTile() {
    return dest_tile;
}

vector<bool> SquareMaze::getRightWalls() {
    return right_;
}

vector<bool> SquareMaze::getDownWalls() {
    return down_;
}
     /*
PNG * SquareMaze::drawMaze () const {
    // Create a new PNG with dimensions based on mazeWidth and mazeHeight
    PNG* maze = new PNG(w * 10 + 1, h * 10 + 1);

  for (unsigned i = 10; i < maze->width(); i++){
    HSLAPixel & p = maze->getPixel(i, 0);
    p.h = 0;
    p.s = 0;
    p.l = 0;
    p.a = 1;
  }
 for (unsigned i = 0; i < maze->height(); i++){
    HSLAPixel & p = maze->getPixel(0, i);
    p.h = 0;
    p.s = 0;
    p.l = 0;
    p.a = 1;
  }

  for(int i = 0; i < w*h; i++) {
      int x = i % w;
      int y = i / w;

      if(right_[i]) {
          for(int k = 0; k <= 10; k++) {
            HSLAPixel & p = maze->getPixel((x+1)*10 , y*10+k);
            p.h = 0;
            p.s = 0;
            p.l = 0;
            p.a = 1;
        }
      }
        
     if(down_[i]) {
         for(int k = 0; k <= 10; k++) {
            HSLAPixel & p = maze->getPixel(x*10+k, (y+1)*10);
            p.h = 0;
            p.s = 0;
            p.l = 0;
            p.a = 1;
        }
     }
  }
 


  return maze;
 }

PNG * SquareMaze::drawMazeWithSolution () {
    vector<int> path = solveMaze();
    down_[dest_tile] = false;
   PNG* maze = drawMaze();
   
   
    int x = 5;
    int y = 5;

   for(unsigned i = 0; i < path.size(); i++) {
       if(path[i] == 0) {
           int goal = x + 10;
           while(x <= goal) {
               HSLAPixel & p = maze->getPixel(x, y);
                p.h = 0;
                p.s = 1;
                p.l = .5;
                p.a = 1;
                x++;
           }
           x--;
       }
       else if(path[i] == 1) {
           int goal = y + 10;
           while(y <= goal) {
               HSLAPixel & p = maze->getPixel(x, y);
                p.h = 0;
                p.s = 1;
                p.l = .5;
                p.a = 1;
                y++;
           }
           y--;
       }
       else if(path[i] == 2) {
           int goal = x - 10;
           while(x >= goal) {
               HSLAPixel & p = maze->getPixel(x, y);
                p.h = 0;
                p.s = 1;
                p.l = .5;
                p.a = 1;
                x--;
           }
           x++;
       }
       else if(path[i] == 3) {
           int goal = y - 10;
           while(y >= goal) {
               HSLAPixel & p = maze->getPixel(x, y);
                p.h = 0;
                p.s = 1;
                p.l = .5;
                p.a = 1;
                y--;
           }
           y++;
       }



   }

   


    return maze;
}

PNG* SquareMaze::drawCreativeMaze() {
    PNG* maze = new PNG(w * 10 + 1, h * 10 + 1);

  for (unsigned i = 10; i < maze->width(); i++){
    HSLAPixel & p = maze->getPixel(i, 0);
    p.h = rand() % 360;
    p.s = 1;
    p.l = .5;
    p.a = 1;
  }
 for (unsigned i = 0; i < maze->height(); i++){
    HSLAPixel & p = maze->getPixel(0, i);
    p.h = rand() % 360;
    p.s = 1;
    p.l = .5;
    p.a = 1;
  }

  for(int i = 0; i < w*h; i++) {
      int x = i % w;
      int y = i / w;

      if(right_[i]) {
          for(int k = 0; k <= 10; k++) {
            HSLAPixel & p = maze->getPixel((x+1)*10 , y*10+k);
            p.h = rand() % 360;
            p.s = 1;
            p.l = .5;
            p.a = 1;
        }
      }
        
     if(down_[i]) {
         for(int k = 0; k <= 10; k++) {
            HSLAPixel & p = maze->getPixel(x*10+k, (y+1)*10);
            p.h = rand() % 360;
            p.s = 1;
            p.l = .5;
            p.a = 1;
        }
     }
  }
 


  return maze;
}


*/
