#include <iostream>

using namespace std;

//Checks to make sure new input adhears to the "Cross rule" in sudoku
//Requires: A 9x9 Puzzle and a integer denoting the current value of position
//Promises: Returns true if the horizontal rule in sudoku is followed
bool verifycross(int puzzle[9][9], int n) {
	int count = 0;
	for (int i = 0; i < 9; i++) { //collum
		for (int j = 0; j < 9; j++) { //row
			if (puzzle[i][j] == n) {
				count++;
			}
		}
		if (count > 1) {
			return false;
		}
		else {
			count = 0;
		}
	}
	return true;
}

//Checks to make sure new input adhears to the "Verticle line" in sudoku
//Requires: A 9x9 Puzzle and a integer denoting the current value of position
//Promises: Returns true if the verticle rule in sudoku is followed
bool verifyvertical(int puzzle[9][9], int n) {
	int count = 0;
	for (int i = 0; i < 9; i++) { //row
		for (int j = 0; j < 9; j++) { //collum
			if (puzzle[j][i] == n) {
				count++;
			}
		}
		if (count > 1) {
			return false;
		}
		else {
			count = 0;
		}
	}
	return true;
}

//Checks to make sure new input adhears to the "square rule" in sudoku
//Requires: A 9x9 Puzzle and a integer denoting the current value of position
//Promises: Returns true if the square rule in sudoku is followed
bool verifysquares(int puzzle[9][9], int n) {
	int count = 0;
	for (int b = 0; b < 9; b = b + 3) {
		for (int a = 0; a < 9; a = a + 3) {
			for (int i = b; i < b + 3; i++) { // row
				for (int j = a; j < a + 3; j++) { // collum
					if (puzzle[i][j] == n) {
						count++;
					}
				}
			}
			if (count > 1) {
				return false;
			}
			else {
				count = 0;
			}
		}
	}
	return true;
}

//Responsible for printing puzzle to the console
//Requires: A 9x9 interger array
//Promises: To print 9x9 array
void print(int puzzle[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << puzzle[i][j] << "    ";
		}
		cout << endl << endl;
	}
}

//Function responsible for solving the puzzle
//Requires: A 9x9 array
//Promises: Solves and prints array 
void solve(int puzzle[9][9]) {
	//copy puzzle
	int puzzleref[9][9] = {};
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			puzzleref[i][j] = puzzle[i][j];
		}
	}

	//solve puzzle
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (puzzleref[i][j] == 0) {
				puzzle[i][j]++;

				if (puzzle[i][j] > 9) {
					puzzle[i][j] = 0;

					j--;

					while (puzzleref[i][j] != 0) {
						if (j == 0) {
							i--;
							j = 8;
						}
						else {
							j--;
						}
					}
					j--;
				}
				else if (verifycross(puzzle, puzzle[i][j]) == false || verifysquares(puzzle, puzzle[i][j]) == false || verifyvertical(puzzle, puzzle[i][j]) == false) {
					j--;
				}
			}
		}
	}

	print(puzzle);

}

int main()
{
	int puzzle[9][9] ={{0, 0, 0, 3, 8, 7, 0, 0, 0}, //puzzle to solve
			   {0, 0, 6, 0, 0, 0, 2, 0, 0},
			   {0, 0, 7, 0, 0, 0, 9, 0, 0},
			   {0, 2, 1, 9, 6, 8, 5, 3, 0},
			   {0, 4, 0, 0, 0, 0, 0, 1, 0},
			   {0, 6, 0, 0, 7, 0, 0, 2, 0},
			   {0, 3, 0, 0, 2, 0, 0, 8, 0},
			   {0, 5, 0, 0, 0, 0, 0, 9, 0},
			   {0, 0, 2, 1, 4, 9, 3, 0, 0} };

	solve(puzzle);
}
