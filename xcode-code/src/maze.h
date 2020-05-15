//
//  maze.h
//  Maze
//
//  Created by Ahsan Gilani on 5/15/20.
//
#pragma once


#include <vector>
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <random>
//#include "cs225/PNG.h"
#include "dsets.h"

//using namespace cs225;
using std::vector;
using std::tuple;
class SquareMaze {
    public:
        void makeMaze (int width, int height);
        bool canTravel (int x, int y, int dir) const;
        void setWall (int x, int y, int dir, bool exists);
        vector<int> solveMaze ();
     //  PNG * drawMaze () const;
    //PNG * drawMazeWithSolution ();
    //  PNG* drawCreativeMaze();

    private:
       // DisjointSets connections;
       int getTileValue(int x, int y) const;
       void setLists(vector<tuple<int, int>> &rightWalls, vector<tuple<int, int>> &bottomWalls);
       vector<bool> right_;
       vector<bool> down_;
       int w;
       int h;

       int tileToMoveTo(int elem, int dir);
       void dfs(int elem, int prev, int dist);
       vector<bool> visited_;
       vector<tuple<int,int>> pd_; //stores previous and distance
       int dest_tile;

       
};
