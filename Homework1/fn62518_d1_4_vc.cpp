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

int main()
{
	int imputNumber = 0;
	int minSum = 0;
	int a = 0, b = 0, c = 0;

	do {
		cin >> imputNumber;
	} while ((0 >= imputNumber) || (imputNumber >= 1000000001));

	minSum = imputNumber + 3;//1 * 1 * imputNumber + 1

	for (int i = 1; i <= imputNumber; i++) {
		
		for (int j = 1; j <= imputNumber / i ; j++) {// adding / i to improve the program so when i*j*k is bigger then the imput number, the loop ends

			for (int k = 1; k <= imputNumber / ( i * j ); k++) {//same here

				if ((i * j * k) == imputNumber) {

					int currentSum = i + j + k;

					if (minSum > currentSum) {

						minSum = currentSum;
						a = i;
						b = j;
						c = k;
					}
				}
			}
		}
	}

	cout << a << " "<< b << " "<< c << endl;

	return 0;
}
