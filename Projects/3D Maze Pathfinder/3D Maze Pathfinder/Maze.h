#pragma once
using namespace std;

class Maze
{
public:
	// CTORS AND DTORS
	Maze();
	Maze(int***);
	~Maze() { delete m_pMaze; };

	// GETTERS
	inline int getRoom(int x, int y, int z) { return m_pMaze[x][y][z]; }
	string getPath(int, int, int, int, int, int);

	// SETTERS

private:
	// PRIVATE OPERATING METHODS
	string findPath(int, int, int, int, int, int);

	// MEMBER VARIABLES
	int*** m_pMaze;
	static int m_ixMax;
	static int m_iyMax;
	static int m_izMax;
};

