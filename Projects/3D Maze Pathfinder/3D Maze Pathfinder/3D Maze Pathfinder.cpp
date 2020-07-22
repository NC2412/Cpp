#include <iostream>
using namespace std;

// SOLUTION IS: R, I, D, D, I, R, U, R, I, D, D, O
//
// KEY: 0 = OPEN
//      -1 = BLOCKED
//      1 = VISITED
//
int maze[4][4][4] = { { {0,-1,-1,-1}, {0,0,-1,-1}, {0,0,-1,-1}, {-1,-1,-1,0} },
                            { {0,-1,-1,-1}, {-1,0,-1,-1}, {-1,-1,0,-1}, {-1,-1,0,0} },
                            { {-1,-1,0,-1}, {-1,0,0,-1}, {-1,-1,0,-1}, {-1,-1,-1,0} },
                            { {-1,0,0,-1}, {-1,0,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,0} }, };

string findPath(int x, int y, int z) {
    string result = "";
    maze[x][y][z] = 1;

    // Check if we are at the end of the maze
    if (x == 3 && y == 3 && z == 3) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        return "FINISHED!";
    }

    // Check if up is 0
    if (x - 1 > -1 && maze[x - 1][y][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x - 1, y, z);
        result = temp == "" ? result : "U, " + temp;
    }

    // Check if left is 0
    if (y - 1 > -1 && maze[x][y - 1][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y - 1, z);
        result = temp == "" ? result : "L, " + temp;
    }

    // Check if down is 0
    if ((x + 1 < sizeof(maze) / sizeof(maze[0])) && maze[x + 1][y][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x + 1, y, z);
        result = temp == "" ? result : "D, " + temp;
    }

    // Check if right is 0
    if ((y + 1 < sizeof(maze[0]) / sizeof(maze[0][0])) && maze[x][y + 1][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y + 1, z);
        result = temp == "" ? result : "R, " + temp;
    }

    // Check if in is 0
    if ((z + 1 < sizeof(maze[0][0]) / sizeof(int)) && maze[x][y][z + 1] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y, z + 1);
        result = temp == "" ? result : "I, " + temp;
    }

    return result;
}

int main()
{
    cout << sizeof(maze) << endl;
    cout << sizeof(maze) / sizeof(maze[0]) << endl;
    cout << sizeof(maze[0]) / sizeof(int) << endl;
    cout << findPath(0, 0, 0) << endl;
}