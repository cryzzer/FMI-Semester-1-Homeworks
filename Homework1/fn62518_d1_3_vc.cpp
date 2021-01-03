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

int main()
{
	int firstNumber = 0,
		secondNumber = 0,
		thirdNumber = 0;
	do {
		cin >> firstNumber;
	} while ((firstNumber <= -1) || (firstNumber >= 10));

	do {
		cin >> secondNumber;
	} while ((secondNumber <= -1) || (secondNumber >= 10));

	do {
		cin >> thirdNumber;
	} while ((thirdNumber <= -1) || (thirdNumber >= 10)); //in the comments F- first number ; S-second number; T- third nuber

	if ((firstNumber == secondNumber) && (firstNumber == thirdNumber) && (firstNumber == 0)) {
		cout << firstNumber << endl;                                                             //F=S=T=0
	}


	else if (((firstNumber == secondNumber) && (secondNumber == 0)) && (thirdNumber > firstNumber)) { 
		cout << thirdNumber << firstNumber << secondNumber << thirdNumber << endl;               // F=S=0 & F<T
	}
	else if (((firstNumber == thirdNumber) && (thirdNumber == 0)) && (secondNumber > firstNumber)) {
		cout << secondNumber << firstNumber << thirdNumber << secondNumber << endl;              // F=T=0 & F<S
	}
	else if(((secondNumber == thirdNumber) && (secondNumber == 0)) && (firstNumber > thirdNumber)) {
		cout << firstNumber << secondNumber << thirdNumber << firstNumber << endl;
	}


	else if ((firstNumber == 0) && (secondNumber > thirdNumber)) {
		cout << thirdNumber << firstNumber << secondNumber << firstNumber << thirdNumber << endl; // F=0 & S>T
	}
	else if ((firstNumber == 0) && (thirdNumber > secondNumber)) {
		cout << secondNumber << firstNumber << thirdNumber << firstNumber << secondNumber << endl; // F=0 & T>S
	}
	else if ((firstNumber == 0) && (secondNumber == thirdNumber)) { 
		cout << secondNumber << firstNumber << thirdNumber << endl;// F=0 & S=T
	}
	else if ((secondNumber == 0) && (firstNumber > thirdNumber)) {
		cout << thirdNumber << secondNumber << firstNumber << secondNumber << thirdNumber << endl;// S=0 & F>T
	}
	else if ((secondNumber == 0) && (thirdNumber > firstNumber)) {
		cout << firstNumber << secondNumber << thirdNumber << secondNumber << firstNumber << endl;// S=0 & T>F
	}
	else if ((secondNumber == 0) && (firstNumber == thirdNumber)) {
		cout << firstNumber << secondNumber << thirdNumber << endl;								  // S=0 & F=T
	}
	else if ((thirdNumber == 0) && (firstNumber > secondNumber)) {
		cout << secondNumber << thirdNumber << firstNumber << thirdNumber << secondNumber << endl;// T=0 & F>S
	}
	else if ((thirdNumber == 0) && (secondNumber > firstNumber)) {
		cout << firstNumber << thirdNumber << secondNumber << thirdNumber << firstNumber << endl; // T=0 & S>F
	}
	else if ((thirdNumber == 0) && (firstNumber == secondNumber)) {
		cout << firstNumber << thirdNumber << secondNumber << endl;								  // T=0 & S=F
	}


	else if ((firstNumber > secondNumber) && (secondNumber > thirdNumber)) {
		cout << thirdNumber << secondNumber << firstNumber << secondNumber << thirdNumber << endl;//F>S>T
	}
	else if ((firstNumber > thirdNumber) && (thirdNumber > secondNumber)) {
		cout << secondNumber << thirdNumber << firstNumber << thirdNumber << secondNumber << endl;//F>T>S
	}
	else if ((secondNumber > thirdNumber) && (thirdNumber > firstNumber)) {
		cout << firstNumber << thirdNumber << secondNumber << thirdNumber << firstNumber << endl;//S>T>F
	}
	else if ((secondNumber > firstNumber) && (firstNumber > thirdNumber)) {
		cout << thirdNumber << firstNumber << secondNumber << firstNumber << thirdNumber << endl;//S>F>T
	}
	else if ((thirdNumber > firstNumber) && (firstNumber > secondNumber)) {
		cout << secondNumber << firstNumber << thirdNumber << firstNumber << secondNumber << endl;//T>F>S
	}
	else if ((thirdNumber > secondNumber) && (secondNumber > firstNumber)) {
		cout << firstNumber << secondNumber << thirdNumber << secondNumber << firstNumber << endl;//T>S>F
	}



	else if (((firstNumber == secondNumber) && (firstNumber > thirdNumber)) || //F=S>T or F=S<T
		((firstNumber == secondNumber) && (firstNumber < thirdNumber)) ) {
		cout << firstNumber << thirdNumber << secondNumber << endl;
	}
	else if (((firstNumber == thirdNumber) && (firstNumber > secondNumber)) || // F=T>S or F=T<S
		( (firstNumber == thirdNumber) && (firstNumber < secondNumber) ) ) {
		cout << firstNumber << secondNumber << thirdNumber << endl;
	}
	else if (((secondNumber == thirdNumber) && (secondNumber > firstNumber)) || // S=T>F OR S=T<F
		((secondNumber == thirdNumber) && (secondNumber < firstNumber))) {
		cout << thirdNumber << firstNumber << secondNumber << endl;
	}
	else if ((firstNumber == secondNumber) && (firstNumber == thirdNumber)) { // F=S=T
		cout << firstNumber << secondNumber << thirdNumber << endl;
	}
	

}
