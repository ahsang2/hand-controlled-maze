//
//  dsets.h
//  Maze
//
//  Created by Ahsan Gilani on 5/15/20.
//

#pragma once

#include <vector>

class DisjointSets {
    private:
        std::vector<int> sets;
    public:
        void addelements(int num);
        int find(int elem);
        int size(int elem);
        void setunion(int a, int b);

};

