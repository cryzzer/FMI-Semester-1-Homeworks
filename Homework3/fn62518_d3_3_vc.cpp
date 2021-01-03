/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 3
* @compiler VC
*
*/
#include <iostream>

using namespace std;

const int MAX_SIZE = 103;

void EqualRows(double arr[][MAX_SIZE], int size, bool& flag) {
	double sumOfRow = 0;//finding first row and comparing him with the others
	double currentSumOfRow = 0;
	for (int row = 0; row < 1;row++) {
		for (int col = 0; col < size;col++) {
			sumOfRow += arr[row][col];
		}
	}
	
	for (int row = 1; row < size;row++) {
		for (int col = 0; col < size;col++) {
			currentSumOfRow += arr[row][col];			
		}
		if (currentSumOfRow != sumOfRow) {
			flag = false;
			return;
		}
		currentSumOfRow = 0;
	}
	flag = true;
}

void EqualCols(double arr[][MAX_SIZE], int size, bool& flag) {
	double sumOfCol = 0;//finding first col and comparing with the others
	double currentSumOfCol = 0;
	for (int col = 0; col < size;col++) {
		for (int row = 0; row < 1;row++) {
			sumOfCol += arr[col][row];
		}
	}

	for (int col = 0; col < size; col++) {
		for (int row = 0; row < size; row++) {
			currentSumOfCol += arr[row][col];
		}
		if (currentSumOfCol != sumOfCol) {
			flag = false;
			return;
		}
		currentSumOfCol = 0;
	}
	flag = true;
}

void EqualRowColDiagonals(double arr[][MAX_SIZE], int size, bool& flag) {
	double sumOfRow = 0;//again finding one row
	for (int row = 0; row < 1;row++) {
		for (int col = 0; col < size;col++) {
			sumOfRow += arr[row][col];
		}
	}

	double sumOfCol = 0;//and one col
	for (int col = 0; col < size;col++) {
		for (int row = 0; row < 1;row++) {
			sumOfCol += arr[col][row];
		}
	}

	double sumOfFirstDiagonal = 0;//main diagonal
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (row == col) {
				sumOfFirstDiagonal += arr[row][col];
			}
		}
	}

	double sumOfSecondDiagonal = 0;//second diagonal
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if ((row + col) == size-1) {
				sumOfSecondDiagonal += arr[row][col];
			}
		}
	}
	if ((sumOfRow == sumOfCol) && (sumOfRow == sumOfFirstDiagonal) && (sumOfRow == sumOfSecondDiagonal)) {
		flag = true;
	}
	else {
		flag = false;
	}
}

bool IfMagicalSquare(double arr[][MAX_SIZE], int size) {
	bool flag = false;//setting flag so if one of the conditions isn't correct, we return false and stop the program

	//first check if one row is equal to one col and the two diagonals
	EqualRowColDiagonals(arr, size, flag);
	if (flag == false) {
		return flag;
	}
	//second check if all rows are equal
	EqualRows(arr, size, flag);
	if (flag == false) {
		return flag;
	}
	//final check if all cols are equal
	EqualCols(arr, size, flag); 
	if (flag == false) {
		return flag;
	}
	//if everything is true, return true
	return flag;
}

int main() {
	double matrix[MAX_SIZE][MAX_SIZE];
	int sizeOfMatrix = 0;
	do {
	cin >> sizeOfMatrix;//check if N e (1;1000)
	} while ((sizeOfMatrix <= 1) || (sizeOfMatrix >= 1000));

	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			do {
			cin >> matrix[i][j]; //check if number e [0;100]
			} while ((matrix[i][j] < 0) || (matrix[i][j] > 100));
		}
	}

	cout << boolalpha << IfMagicalSquare(matrix, sizeOfMatrix);

	return 0;
}

/*
3
3 9 5
7 14 7
8 1 8
*/

/*
3
8 1 6
3 5 7
4 9 2
*/