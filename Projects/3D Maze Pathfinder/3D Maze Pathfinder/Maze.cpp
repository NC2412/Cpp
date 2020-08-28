#include "Maze.h"
#include <iostream>

Maze::Maze() {
	m_pMaze = NULL;
	m_ixMax = 0;
	m_iyMax = 0;
	m_izMax = 0;
}

Maze::Maze(int*** maze) {
	m_pMaze = maze;
	m_ixMax = sizeof(***maze) / sizeof(**maze[0]);
	m_iyMax = sizeof(**maze[0]) / sizeof(*maze[0][0]);
	m_izMax = sizeof(*maze[0][0]) / sizeof(int);
}

string Maze::getPath(int sx = 0, int sy = 0, int sz = 0, int ex = m_ixMax, int ey = m_iyMax, int ez = m_izMax) {
	string path;

	if (NULL == m_pMaze)
		return "No maze given.";

	path = findPath(sx, sy, sz, ex, ey, ez);

	return path;
}

//-----------------------------------------------------------------------------------------------------------------
//
//		PRIVATE METHODS
//
//-----------------------------------------------------------------------------------------------------------------


string Maze::findPath(int x, int y, int z, int ex, int ey, int ez) {
    string result = "";
    m_pMaze[x][y][z] = 1;

    // Check if we are at the end of the maze
    if (x == ex && y == ey && z == ez) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        return "FINISHED!";
    }

    // Check if up is 0
    if (x - 1 > -1 && m_pMaze[x - 1][y][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x - 1, y, z, ex, ey, ez);
        result = temp == "" ? result : "U, " + temp;
    }

    // Check if left is 0
    if (y - 1 > -1 && m_pMaze[x][y - 1][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y - 1, z, ex, ey, ez);
        result = temp == "" ? result : "L, " + temp;
    }

    // Check if down is 0
    if (x + 1 < ex + 1 && m_pMaze[x + 1][y][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x + 1, y, z, ex, ey, ez);
        result = temp == "" ? result : "D, " + temp;
    }

    // Check if right is 0
    if (y + 1 < ey + 1 && m_pMaze[x][y + 1][z] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y + 1, z, ex, ey, ez);
        result = temp == "" ? result : "R, " + temp;
    }

    // Check if in is 0
    if (z + 1 < ez + 1 && m_pMaze[x][y][z + 1] == 0) {
        cout << "X: " << x << ", Y: " << y << ", Z: " << z << endl;
        string temp = findPath(x, y, z + 1, ex, ey, ez);
        result = temp == "" ? result : "I, " + temp;
    }

    return result;
}