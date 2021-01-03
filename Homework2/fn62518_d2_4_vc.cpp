/**
*
* Solution to homework assignment 1
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

const int MAX_SIZE = 102;

int main()
{
	int inputNumber = 0;
	long long arr1[MAX_SIZE];
	int array2[MAX_SIZE];//adding another array 
	int counter = 0;

	do {
		cin >> inputNumber;
	} while ((inputNumber < 3) || (inputNumber > 100));

	for (int i = 0; i < inputNumber; i++) {
		do {
			cin >> arr1[i];//inserting number
		} while ((INT_MIN > arr1[i]) || (arr1[i] > INT_MAX));
		for (int j = 0; j < inputNumber; j++) {
			if (arr1[i] == array2[j]) {//if that number already exists, enter again (below) until it doesn't match with the already entered numbers
				do {
					do {
						cin >> arr1[i];//here enter again
					} while ((INT_MIN > arr1[i]) || (arr1[i] > INT_MAX));
				} while (arr1[i] == array2[j]);
				j = -1;//setting j to be -1, because at the end of the loop it becomes j = j+1 (j++) and starts checking the second array again if
					   //the new entered number matches with the already existing numbers 
			}
		}
		array2[i] = arr1[i];
	}

	for (int i = 0; i < inputNumber; i++) {
		for (int j = i+1; j < inputNumber;j++) {//doing this so the combinations doesnt match
			for (int k = j+1; k < inputNumber; k++) {// --- || ----
				if ((i != j) && (j != k)) {
					if ((array2[i] + array2[j] + array2[k]) == 0) {
						counter++;//if a + b + c = 0; counter adds 1 to its sum
					}
				}
			}
		}
	}

	cout << counter << endl;

}

