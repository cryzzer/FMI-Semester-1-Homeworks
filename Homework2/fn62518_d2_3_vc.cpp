/**
*
* Solution to homework assignment 1
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

const int MAX_SIZE = 1002;

int main()
{

	int inputNumber;
	int arr[MAX_SIZE];
	int counter = 0;//setting counter of how many combinations are available
	int previousOrNextDigit = 1;//the digit before and after our main one (j)

	do {
		cin >> inputNumber;
	} while ((inputNumber < 3) || (inputNumber > 1000));
	

	for (int i = 0; i < inputNumber; i++) {//inserting elements

		do {
			cin >> arr[i];
		} while ((arr[i] < 0) || (arr[i] > 9));
	}

	for (int j = 1; j < inputNumber - 1; j++) {
		previousOrNextDigit = 1;
		if (arr[j] == arr[j + 1]) {//example: 1 2 2 1; we check if 2=2, then the polindrome is even, otherwise its odd
			//check if the next digits are equal: 1=1, after the last digit is compared the while loop ends
			while ((arr[j - previousOrNextDigit] == arr[j + 1 + previousOrNextDigit]) && ((j + 1 + previousOrNextDigit) < inputNumber))
				previousOrNextDigit++; //adding +1 to the var., so the next digit is ready to me compared
			counter++; //adding +1 to counter
		}


		else if (arr[j - 1] == arr[j + 1]) {//example: 5 0 6 0 5
			while (arr[j - previousOrNextDigit] == arr[j + previousOrNextDigit] && ((j + previousOrNextDigit) < inputNumber)) {//same logic goes here
				previousOrNextDigit++;
				counter++;
			}
		}
	}

	if (counter != 0) {
		cout << counter << endl;

	}
	else {
		cout << "-1" << endl;//-1 s for error
	}
}

