//
//  dsets.cpp
//  Maze
//
//  Created by Ahsan Gilani on 5/15/20.
//

#include "dsets.h"

void DisjointSets::addelements(int num) {
   sets.insert(sets.begin(), num, -1);
   
}

 int DisjointSets::find(int elem) {
    if(sets[elem] < 0) {
        return elem;
    }

    sets[elem] =  find(sets[elem]);
    return sets[elem];
 }

 int DisjointSets::size(int elem) {
     return -1 * sets[find(elem)];
 }

 void DisjointSets::setunion(int a, int b) {
     int par1 = find(a);
     int par2 = find(b);
     int newsize = sets[par1] + sets[par2];

     if(sets[par1] <= sets[par2]) {
         sets[par2] = par1;
         sets[par1] = newsize;
     }
     else {
         sets[par1] = par2;
         sets[par2] = newsize;
     }
 }
