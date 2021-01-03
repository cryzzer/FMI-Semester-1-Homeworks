/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 5
* @compiler VC
*
*/


#include <iostream>

using namespace std;

int main()
{
	int divideNumber = 0;
	double finalNumber = 0;
	int testNumber = 0;
	int counter = 0;//this int will count how many digits are after the comma

	do {
		cin >> divideNumber;
	} while ((1 >= divideNumber) || (divideNumber >= 1000000001));

	testNumber = divideNumber;


	while ((testNumber % 2 == 0) || (testNumber % 5 == 0)) {//we use this loop to see if the entered number has endless
		if (testNumber % 2 == 0) {                          //period or not, by deviding by 2 and 5, we can see that
			testNumber = testNumber / 2;
		}
		else if (testNumber % 5 == 0) {
			testNumber = testNumber / 5;
		}
	}
	if (testNumber != 1) {
		cout << "NO" << endl;
	}
	else {
		finalNumber = 1 / (double)divideNumber;

		while (finalNumber != (int)finalNumber) {//here we use another loop to see how many digits are after
			finalNumber = finalNumber * 10;      //the  decimal point
			counter++;
		}
		if (finalNumber == (int)finalNumber)
		{
			cout << counter << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return 0;
	}

}

