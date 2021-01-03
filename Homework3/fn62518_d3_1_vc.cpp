/**
*
* Solution to homework assignment 3
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

const int MAX_SIZE = 151;

int StringLength(char strArr[]) {
	int sizeOfArray = 0;
	while (strArr[sizeOfArray]) {
		sizeOfArray++;
	}
	return sizeOfArray;
}

int RegularCharString(char arr[]) {
	int size = StringLength(arr);
	char arr2[MAX_SIZE];

	bool flag = false;
	int counter = 0;
	int timesElementExists = 1;
	int oddExistingElements = 0;//if there are 2 or more differentelements that exist in the array, and they don't exist even number of times,
	//the string is irregular

	for (int i = 0;i < size;i++) {
		timesElementExists = 1;//if an element exists 1 time in the array, he exists oddly
		flag = false;

		//after we have searched for an element, we writh him in this array, so we dont search him twice
		for (int k = 0;k < size;k++) {
			if (arr[i] == arr2[k]) {
				flag = true;
				break;
			}
		}
		if (flag == true) {
			continue;
		}

		for (int j = i+1;j < size;j++) {
			if (arr[i] == arr[j]) {
				timesElementExists++;
			}
		}
		//if element is lower than 2,greater than 2 and when deviding by 2 returns 1, he exists oddly
		if ((timesElementExists > 2) && (timesElementExists % 2 == 1) || (timesElementExists < 2)) {
			oddExistingElements++;
		}
		
		arr2[counter] = arr[i];//writing the element to the second array
		++counter;

		if (oddExistingElements > 1) {//when there are 2 or more odd existing elements we return 0 and stop the program
			return 0;
		}
	}

	return 1;
}

int main()
{
	char charArray[MAX_SIZE];

	cin >> charArray;

	cout << RegularCharString(charArray) << endl;
}