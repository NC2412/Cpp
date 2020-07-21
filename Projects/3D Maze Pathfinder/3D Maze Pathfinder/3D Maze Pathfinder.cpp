#include <iostream>
using namespace std;

// SOLUTION IS: R, I, D, D, I, R, U, R, I , D, D, O
const int maze[4][4][4] = { { {0,-1,-1,-1}, {0,0,-1,-1}, {0,0,-1,-1}, {-1,-1,-1,0} },
                            { {0,-1,-1,-1}, {-1,0,-1,-1}, {-1,-1,0,-1}, {-1,-1,0,0} },
                            { {-1,-1,0,-1}, {-1,0,0,-1}, {-1,-1,0,-1}, {-1,-1,-1,0} },
                            { {-1,0,0,-1}, {-1,0,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,0} }, };



string findPath(int x, int y, int z) {
    // Check if we are at the end of the maze
    if (x ==3 && y == 3 && z == 3)
        return "O!";

    // Check if up is 0
    if (maze[x - 1][y][z] == 0 && x - 1 > -1) {
        string result = findPath(x - 1, y, z);
        return result == "" ? result : "U, " + result;
    }

    // Check if left is 0
    if (maze[x][y - 1][z] == 0 && y - 1 > -1) {
        string result = findPath(x, y - 1, z);
        return result == "" ? result : "L, " + result;
    }

    // Check if down is 0
    if (maze[x + 1][y][z] == 0 && (x + 1 < sizeof(maze) / sizeof(maze[0]))) {
        string result = findPath(x + 1, y, z);
        return result == "" ? result : "D, " + result;
    }

    // Check if right is 0
    if (maze[x][y + 1][z] == 0 && (y + 1 < sizeof(maze[0]) / sizeof(maze[0][0]))) {
        string result = findPath(x, y + 1, z);
        return result == "" ? result : "R, " + result;
    }

    // Check if in is 0
    if (maze[x][y][z + 1] == 0 && (z + 1 < sizeof(maze[0][0]) / sizeof(int))) {
        string result = findPath(x, y, z + 1);
        return result == "" ? result : "I, " + result;
    }

    return "";
}

int main()
{
    cout << sizeof(maze) << endl;
    cout << sizeof(maze) / sizeof(maze[0]) << endl;
    cout << sizeof(maze[0]) / sizeof(int) << endl;
    cout << findPath(0, 0, 0) << endl;
}