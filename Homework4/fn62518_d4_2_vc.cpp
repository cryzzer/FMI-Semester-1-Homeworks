/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE_HEIGHT = 201;
const int MAX_SIZE_WIDTH = 201;

void FillChessBoard(int arr[MAX_SIZE_HEIGHT][MAX_SIZE_WIDTH], int height, int width, int row, int col, int& maxMovesAllowed, int movesCounter) {
	//checking if we are out of the matrix(border), and if we are aout of moves,if true, return to previous step
	if (row < 0 || row > height - 1 || col < 0 || col > width - 1 || movesCounter > maxMovesAllowed || (arr[row][col] != 0 && movesCounter >= arr[row][col])) {
		return;
	}
	//if the number is greater than the number that will be inserted inside, place the lowest number
	if (arr[row][col] == 0 || arr[row][col] > movesCounter) {
		arr[row][col] = movesCounter;//giving the position that we are, the number of how steps is needed to go there
		//from one position, there are 8 possible routes to go
		FillChessBoard(arr, height, width, row - 2, col + 1, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row - 1, col + 2, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row + 1, col + 2, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row + 2, col + 1, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row + 2, col - 1, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row + 1, col - 2, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row - 1, col - 2, maxMovesAllowed, movesCounter + 1);
		FillChessBoard(arr, height, width, row - 2, col - 1, maxMovesAllowed, movesCounter + 1);
	}
}
bool IfPossibleHorseMovesToCoordinates(int arr[MAX_SIZE_HEIGHT][MAX_SIZE_WIDTH], int height, int width,
	int row, int col, int& maxMovesAllowed, int movesCounter, int endPositionRow, int endPositionCol) {

	FillChessBoard(arr, height, width, row, col, maxMovesAllowed, movesCounter);//caling the recurssion
	//checking if the position that we are looking for, the number inside is equal or less than the minimum moves allowed, then print true, otherwise false
	if (arr[endPositionRow][endPositionCol] <= maxMovesAllowed && arr[endPositionRow][endPositionCol] != 0) {	
		cout << "True\n";
		return true;
	}
	else {		
		cout << "False\n";
		return false;
	}
}

int main()
{
	int chessBoard[MAX_SIZE_HEIGHT][MAX_SIZE_WIDTH] = { 0 };
	int movesCounter = 0;

	int height;
	int width;
	do {
		cin >> height;
	} while (height <= 3 || height >= 201);//(3;200]

	do {	
		cin >> width;
	} while (width <= 3 || width >= 201);//(3;200]

	int startPositionRow;
	int startPositionCol;

	do {
		cin >> startPositionRow; 
	} while ((startPositionRow <= 0 || startPositionRow >= 201) || startPositionRow >= height);//(0;200] and must be lower than height

	do {
		cin >> startPositionCol;
	} while ((startPositionCol <= 0 || startPositionCol >= 201) || startPositionCol >= width);//(0;200] and must be lower than width
	

	int endPositionRow;
	int endPositionCol;

	do {
		cin >> endPositionRow;
	} while (endPositionRow <= 0 || width >= 201);//(0;200]

	do {
		cin >> endPositionCol;
	} while (endPositionCol <= 0 || endPositionCol >= 201);//(0;200]
	

	int maxMovesAllowed;// [0;30]

	do {
		cin >> maxMovesAllowed;
	} while (maxMovesAllowed <= 0 || maxMovesAllowed >= 31);//(0;30]
	
	IfPossibleHorseMovesToCoordinates(chessBoard, height, width, startPositionRow, startPositionCol,maxMovesAllowed, movesCounter, endPositionRow, endPositionCol);

	return 0;
}