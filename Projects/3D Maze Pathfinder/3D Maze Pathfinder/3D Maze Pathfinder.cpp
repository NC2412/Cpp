#include <iostream>
#include "Maze.h"
using namespace std;

// SOLUTION IS: R, I, D, D, I, R, U, R, I, D, D, O
//
// KEY: 0 = OPEN
//      -1 = BLOCKED
//      1 = VISITED
//
int g_maze[4][4][4] = { { {0,-1,-1,-1}, {0,0,-1,-1}, {0,0,-1,-1}, {-1,-1,-1,0} },
                            { {0,-1,-1,-1}, {-1,0,-1,-1}, {-1,-1,0,-1}, {-1,-1,0,0} },
                            { {-1,-1,0,-1}, {-1,0,0,-1}, {-1,-1,0,-1}, {-1,-1,-1,0} },
                            { {-1,0,0,-1}, {-1,0,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,0} }, };


int main()
{
    int xLen = sizeof(g_maze) / sizeof(g_maze[0]);
    int yLen = sizeof(g_maze[0]) / sizeof(g_maze[0][0]);
    int zLen = sizeof(g_maze[0][0]) / sizeof(int);
    //int*** p_maze = g_maze;
    Maze maze = Maze();
}