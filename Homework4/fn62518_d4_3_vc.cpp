/**
*
* Solution to homework assignment 4
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

const int MAX_SIZE = 10;

void Reduction(int& variableTop, int& variableBottom) {//reducting numerator and denomenator
	bool isNegative = false;
	if (variableTop < 0) {//cheking if the numerator is negative
		isNegative = true;
		variableTop = -(variableTop);//making it positive
	}
	int maxReduction = (variableTop < variableBottom) ? variableTop : variableBottom;//picking the lowest number

	if (maxReduction == 1) {
		return;
	}
	for (int i = 2; i <= maxReduction; i++) {
		if ((variableTop % i == 0) && (variableBottom % i == 0)) {//starting deviding both if they devide by i and have % i == 0
			variableTop = variableTop / i;
			variableBottom = variableBottom / i;
			maxReduction = maxReduction / i;
			i--;
		}
	}
	if (isNegative) {
		variableTop = -(variableTop);//making the formar negative number back to negative
	}
}
void Swap(int& a, int& b) {//swapping 2 numbers
	int c = a;
	a = b;
	b = c;
}
void ifNumeratorEqualsZero(int& variableTop, int& variableBottom) {//last function, if the numeratior is zero, the denomerator becomes 1
	if (variableTop == 0) {
		variableBottom = 1;
	}
}
//multiplying the two denomerators, multiplying each numerator and adding them one another, than performing a reduction
void Addition(int firstNumerator1, int firstDenominator, int secondNumenator1, int secondDenomenator, int arr[]) {
	int variableBottom = firstDenominator * secondDenomenator;
	int variableTop = (firstNumerator1 * secondDenomenator) + (secondNumenator1 * firstDenominator);
	Reduction(variableTop, variableBottom);
	ifNumeratorEqualsZero(variableTop, variableBottom);
	arr[0] = variableTop;
	arr[1] = variableBottom;
}//multiplying the two denomerators, multiplying each numerator and subtracting them one another, than performing a reduction
void Subtraction(int firstNumerator1, int firstDenominator, int secondNumenator1, int secondDenomenator, int arr[]) {
	int variableBottom = firstDenominator * secondDenomenator;
	int variableTop = (firstNumerator1 * secondDenomenator) - (secondNumenator1 * firstDenominator);
	Reduction(variableTop, variableBottom);
	ifNumeratorEqualsZero(variableTop, variableBottom);
	arr[0] = variableTop;
	arr[1] = variableBottom;
}
//multiplying the two denomerators, multiplying the two numerators, than performing a reduction
void Multiplication(int firstNumerator1, int firstDenominator, int secondNumenator1, int secondDenomenator, int arr[]){
	int variableTop = firstNumerator1 * secondNumenator1;
	int variableBottom = firstDenominator * secondDenomenator;
	Reduction(variableTop, variableBottom);
	ifNumeratorEqualsZero(variableTop, variableBottom);
	arr[0] = variableTop;
	arr[1] = variableBottom;
}
//switching place betweeen second numerator and second denomenator and multiplying the two denomerators, multiplying the two numerators, than performing a reduction
void Devision(int firstNumerator1, int firstDenominator, int secondNumenator1, int secondDenomenator, int arr[]) {
	if (secondNumenator1 < 0) {//if numerator is a negative number, make it a positive and the denomerator negative
		secondNumenator1 = -(secondNumenator1);
		secondDenomenator = -(secondDenomenator);
	}
	Swap(secondNumenator1, secondDenomenator);
	Multiplication(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, arr);
}

int* ActionSelection(int firstNumerator1, int firstDenominator, int secondNumenator1, int secondDenomenator, char sign) {//selecting action
	int* arr = new int[MAX_SIZE];//creating dinamic array
	if (sign == '+') {
		Addition(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, arr);
	}
	else if (sign == '-') {
		Subtraction(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, arr);
	}
	else if (sign == '*') {
		Multiplication(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, arr);
	}
	else {
		Devision(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, arr);
	}
	return arr;//returning array
}

int main()
{
	int firstNumerator1;
	int firstDenominator;
	int secondNumenator1;
	int secondDenomenator;
	char sign;

	do {
		cin >> firstNumerator1;
	} while (firstNumerator1 < -100000000 || firstNumerator1 > 100000000); //[-10 ^ 8; 10^8]

	do {
		cin >> firstDenominator;
	} while (firstDenominator < -100000000 || firstDenominator > 100000000);//[-10 ^ 8; 10^8]
	
	if (firstDenominator == 0) {//if denomerator is 0, return -1
		cout << "-1\n";
		return 1;
	}

	do {
		cin >> sign;
	} while ((sign != '+') && (sign != '-') && (sign != '*') && (sign != '/'));//sign must be between these 4 options

	do {
		cin >> secondNumenator1;
	} while (secondNumenator1 < -100000000 || secondNumenator1 > 100000000);//[-10 ^ 8; 10^8]

	do {
		cin >> secondDenomenator;
	} while (secondDenomenator < -100000000 || secondDenomenator > 100000000);//[-10 ^ 8; 10^8]

	if (secondDenomenator == 0) {//if denomerator is 0, return -1
		cout << "-1\n";
		return 1;
	}
	
	int* result = ActionSelection(firstNumerator1, firstDenominator, secondNumenator1, secondDenomenator, sign);

	for (int i = 0; i < 2;i++) {
		cout << result[i] << ' ';//couting result
	}
	delete []result;//deliting dinamic array
}
