/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 1
* @compiler VC
*
*/


#include <iostream>

using namespace std;

const int MAX_SIZE = 102;

int main()
{
	int inputNumber;
	do {
		cin >> inputNumber;
	} while ((inputNumber < 3) || (inputNumber > 100));


	//entering numbers in array
	int array[MAX_SIZE];
	for (int i = 0; i < inputNumber; i++) {
		cin >> array[i];
	}

	//some useful integers
	int num = 0;
	int a = 0, b = 0;

	bool ifTrue = false;//flag to show if it is true

	for (int i = inputNumber - 1;i > inputNumber / 2; i--) { //rolling the loop from N - 1 to N / 2

		a = array[num] - array[num + 1];//doing abs for a
		if (a < 0) {
			a = -a;
		}

		b = (array[i] - array[i - 1]);//doing abs for b
		if (b < 0) {
			b = -b;
		}

		if (a == b) {//if a == b, we set the flag to be true, to have an output in the console "1"
			ifTrue = true;
		}
		else if (a != b) {//otherwise 
			ifTrue = false;
			break;
		}
		num++;
	}

	if (ifTrue == true) {
		cout << "1" << endl;
	}
	else if (ifTrue == false) {
		cout << "0" << endl;
	}



}
