// The purpose of this program is to navigate a maze using the "turn right method"
// This program is able to solve the maze that was given to us in the procedure without error

#include <iostream>
using namespace std;

void printMaze(char maze[12][12]) //function to display maze
{
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}

void mazeTraverse(char m[12][12], int r, int c) //function to solve the maze that uses a method of direction by updating the direction we are facing after every move
{
	char dir = 'e'; //variable will be used to tell which direction we are facing, and we are known to begin facing east
	while (c != 11) {
		cout << "\nPress Enter to continue:\n";
		cin.ignore();
		m[r][c] = 'X';
		printMaze(m);
		char n = m[r - 1][c];//for checking above
		char e = m[r][c + 1];//for checking right
		char w = m[r][c - 1];//check left
		char s = m[r + 1][c];//check below
		switch (dir)
		{
		case 'e': //facing east
		{
			if (s != '#') //move south
			{
				r += 1;
				dir = 's';
			}
			else if (e != '#') //move east
			{
				c += 1;
				dir = 'e';
			}
			else if (n != '#') //move north
			{
				r -= 1;
				dir = 'n';
			}
			else if (w != '#') // move west
			{
				c -= 1;
				dir = 'w';
			}
		}break;
		case 's':
		{
			if (w != '#') // move west
			{
				c -= 1;
				dir = 'w';
			}
			else if (s != '#') //move south
			{
				r += 1;
				dir = 's';
			}
			else if (e != '#') //move east
			{
				c += 1;
				dir = 'e';
			}
			else if (n != '#') //move north
			{
				r -= 1;
				dir = 'n';
			}
		}break;
		case 'n':
		{
			if (e != '#') //move east
			{
				c += 1;
				dir = 'e';
			}
			else if (n != '#') //move north
			{
				r -= 1;
				dir = 'n';
			}
			else if (w != '#') // move west
			{
				c -= 1;
				dir = 'w';
			}
			else if (s != '#') //move south
			{
				r += 1;
				dir = 's';
			}
		}break;
		case 'w': {
			if (n != '#') //move north
			{
				r -= 1;
				dir = 'n';
			}
			else if (w != '#') // move west
			{
				c -= 1;
				dir = 'w';
			}
			else if (s != '#') //move south
			{
				r += 1;
				dir = 's';
			}
			else if (e != '#') //move east
			{
				c += 1;
				dir = 'e';
			}
		}break;
		default:
			break;
		}
	}
	cout << "\nPress Enter to continue:\n";
	cin.ignore();
	m[r][c] = 'X';//updates the maze and prints upon completion of maze
	printMaze(m);
}

int main()
{
	int row;
	char maze[12][12] = { //maze given in procedure
	{'#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','.','.','.','.','.','.','#','.','.','.','#'},
	{'#','#','#','#','#','#','.','#','#','#','.','#'},
	{'#','.','.','.','.','.','.','.','.','#','.','#'},
	{'#','#','.','#','.','#','.','#','.','#','.','.'},
	{'#','.','.','#','.','#','.','#','.','#','.','#'},
	{'#','#','#','#','.','#','.','#','.','#','.','#'},
	{'#','.','.','.','.','#','#','#','.','#','.','#'},
	{'#','#','#','.','#','.','.','.','.','#','.','#'},
	{'.','.','#','.','#','.','#','#','#','#','.','#'},
	{'#','.','.','.','#','.','.','.','.','.','.','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#'}
	};

	for (int i = 0; i < 12; i++) //used to find starting point on left wall
	{
		if (maze[i][0] == '.')
		{
			row = i;
			break;
		}
	}
	int col = 0; //we are assuming that this program will accept mazes that only start on the left side, although the function may work differently
	cout << "The following maze is to be solved using an algorithm, with X marking where we are:\n\n";
	printMaze(maze);
	cout << "\nPress enter everytime you would like to advance in the maze.\n";
	mazeTraverse(maze, row, col); //the function needs a maze, and coordinates to begin navigating from
	cout << "\nThe maze has been completed!\nPress enter to exit...\n";
	cin.ignore();
	return 0;
}