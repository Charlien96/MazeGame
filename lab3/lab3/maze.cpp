// Charles Newman
// C00229034

#include <iostream>
#include <time.h>
using namespace std;

void drawMaze(char mz[10][10], int numRows, int numCols)
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			cout << mz[row][col];
		}
		cout << endl;
	}
	cout << mz[numRows][numCols];
}

void drawPlants(int numPlants, char mz[10][10], int numRows, int numCols) {
	while (numPlants != 0) {
		int pos1 = rand() % 10;
		int pos2 = rand() % 10;
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				if (mz[pos1][pos2] == '0') {
					mz[pos1][pos2] = 'y';
					numPlants--;
					break;
				}
				else if (mz[pos1][pos2] != '0') {
					break;
				}
			}
			break;
		}
	}
	cout << mz[numRows][numCols];
}

void drawWalkers(int numWalkers, char mz[10][10], int numRows, int numCols) {
	while (numWalkers != 0) {
		int pos1 = rand() % 10;
		int pos2 = rand() % 10;
		for (int row = 0; row < numRows; row++) {
			for (int col = 0; col < numCols; col++) {
				if (mz[pos1][pos2] == '0') {
					mz[pos1][pos2] = '2';
					numWalkers--;
					break;
				}
				else if (mz[pos1][pos2] != '0') {
					break;
				}
			}
			break;
		}
	}
	cout << mz[numRows][numCols];
}

void walk(char mz[10][10], int& pCount, int numRows, int numCols) {
	char placeholder = 'X';
	int check = 0;

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			if (mz[row][col] == '2') {
				int pos = rand() % 8;
				switch (pos) {
				case 0:
					for (int col2 = col - 1; col2 <= col + 1; col2++) {
						for (int row2 = row - 1; row2 <= row + 1; row2++) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 1:
					for (int row2 = row - 1; row2 <= row + 1; row2++) {
						for (int col2 = col - 1; col2 <= col + 1; col2++) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 2:
					for (int col2 = col + 1; col2 >= col - 1; col2--) {
						for (int row2 = row - 1; row2 <= row + 1; row2++) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 3:
					for (int row2 = row - 1; row2 >= row + 1; row2++) {
						for (int col2 = col + 1; col2 >= col - 1; col2--) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 4:
					for (int col2 = col - 1; col2 <= col + 1; col2++) {
						for (int row2 = row + 1; row2 >= row - 1; row2--) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 5:
					for (int row2 = row + 1; row2 >= row - 1; row2--) {
						for (int col2 = col - 1; col2 <= col + 1; col2++) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 6:
					for (int col2 = col + 1; col2 >= col - 1; col2--) {
						for (int row2 = row + 1; row2 >= row - 1; row2--) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				case 7:
					for (int row2 = row + 1; row2 >= row - 1; row2--) {
						for (int col2 = col + 1; col2 >= col - 1; col2--) {
							if (mz[row2][col2] == '0') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								check = 1;
								break;
							}
							else if (mz[row2][col2] >= 'a' && mz[row2][col2] <= 'y') {
								mz[row2][col2] = placeholder;
								mz[row][col] = '0';
								pCount--;
								check = 1;
								break;
							}
						}
						if (check == 1) {
							check = 0;
							break;
						}
					}
					break;
				}
			}
		}
	}
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			if (mz[row][col] == placeholder) {
				mz[row][col] = '2';
			}
		}
	}
}

void plantCheck(char mz[10][10], int numCols, int numRows) {
	int walkerFound = 0;

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			if (mz[row][col] >= 'a' && mz[row][col] <= 'z') {
				for (int col2 = col; col2 < numCols; col2++) {
					if (mz[row][col2] == '2') {
						walkerFound = 1;
						break;
					}
					else if (mz[row][col2] == '1') {
						break;
					}
				}
				for (int col2 = col; col2 > 0; col2--) {
					if (mz[row][col2] == '2') {
						walkerFound = 1;
						break;
					}
					else if (mz[row][col2] == '1') {
						break;
					}
				}
				for (int row2 = row; row2 < numRows; row2++) {
					if (mz[row2][col] == '2') {
						walkerFound = 1;
						break;
					}
					else if (mz[row2][col] == '1') {
						break;
					}
				}
				for (int row2 = row; row2 > 0; row2--) {
					if (mz[row2][col] == '2') {
						walkerFound = 1;
						break;
					}
					else if (mz[row2][col] == '1') {
						break;
					}
				}
				if (walkerFound == 0) {
					if (mz[row][col] == 'a') {
						mz[row][col] = 'y';
					}
					else {
						mz[row][col]--;
					}
				}
				else if (walkerFound == 1) {
					walkerFound = 0;
				}
			}
		}
	}
}

int main()
{
	srand(time(0));
	int plant = 0;
	int pCount = 10;
	int walkers = 0;
	int wCount = 5;
	const int numRows = 10;
	const int numCols = 10;
	char  maze[numRows][numCols] = {
			{'1','1','1','1','1','1','1','1','1','1'},
			{'1','0','1','0','0','0','1','0','0','1'},
			{'1','0','1','1','1','0','0','0','1','1'},
			{'1','0','0','0','0','0','1','0','1','1'},
			{'1','0','1','1','1','0','1','0','0','1'},
			{'1','1','0','1','0','0','1','0','1','1'},
			{'1','0','0','0','0','1','1','0','1','1'},
			{'1','1','0','1','0','0','1','0','0','1'},
			{'1','0','0','1','1','0','0','0','1','1'},
			{'1','1','1','1','1','1','1','1','1','1'} };
	char c = 'a';
	while (c != 'x')
	{
		if (pCount == 0) {
			cout << "Life simulation has ended!";
			break;
		}
		drawMaze(maze, numRows, numCols);
		cin >> c;
		if (plant == 0) {
			drawPlants(pCount, maze, numRows, numCols);
			plant = 1;
		}
		if (walkers == 0) {
			drawWalkers(wCount, maze, numRows, numCols);
			walkers = 1;
		}
		plantCheck(maze, numCols, numRows);
		walk(maze, pCount, numRows, numCols);
	}

}