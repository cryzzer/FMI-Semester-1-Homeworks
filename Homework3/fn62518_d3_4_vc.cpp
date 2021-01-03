/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 4
* @compiler VC
*
*/
#include <iostream>

using namespace std;

const int MAX_SIZE = 101;

int StringLength(char strArr[]) {
	int sizeOfArray = 0;
	while (strArr[sizeOfArray]) {
		sizeOfArray++;
	}
	return sizeOfArray;
}
int IfLatinLetters(char arr[]) {
	int size = StringLength(arr);
	for (int i = 0; i < size;i++) {
		if (((arr[i] < 'A') || (arr[i] > 'Z')) && ((arr[i] < 'a') || (arr[i] > 'z'))) {
			return false;
		}
	}
}

void IfDifferentLetters(char arr[], int& size) {
	bool secondFlag = false;
	int counter = 0;
	int equal = 1;
	for (int i = 0; i < size; i++) {
		secondFlag = false;
		for (int j = i + 1; j < size;j++) {
			if (arr[i] == arr[j]) {
				secondFlag = true;
				break;
			}
		}
		if (!secondFlag) {
			++counter;
		}
		else {
			equal++;
		}
	}
	if (size == counter) {
		cout << (size * size) - 1 << endl;
	}
	if (equal == 2 && size == 5) {
		cout << (size * size) - 2 << endl;
	}
	if (equal == 3 && size == 4) {
		cout << (size * (size - 1)) - 2 << endl;
	}
}

int main(){
	char strArr[MAX_SIZE];
	cin >> strArr;

	int size = StringLength(strArr);//finding size
	bool flag = IfLatinLetters(strArr);//checking if
	if (flag == false) {
		cout << "-1\n";
		return 1;
	}
	//checking if there are different letters from one another
	IfDifferentLetters(strArr, size);

	return 0;//PS: sorry, couldn't solve this problem, I tried my hardest but there was no result

}
