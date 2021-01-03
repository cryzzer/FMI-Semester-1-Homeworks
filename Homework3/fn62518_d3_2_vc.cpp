/**
*
* Solution to homework assignment 3
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

using namespace std;

const int MAX_SIZE = 151;

int StringLength(char strArr[]) {
	int sizeOfArray = 0;
	while (strArr[sizeOfArray]) {
		sizeOfArray++;
	}
	return sizeOfArray;
}

void Swap(char& a, char& b) {
	char c = a;
	a = b;
	b = c;
}

int IfLatinSmallLetters(char arr[]) {
	int size = StringLength(arr);
	for (int i = 0;i < size;i++) {
		if (arr[i] < 'a' || arr[i]>'z') {
			return -1;
		}
	}
}

void InsertionSort(char arr[]) {
	int size = StringLength(arr);
	for (int i = 0; i < size;i++) {
		int j = i;
		while (j > 0 && arr[j] <= arr[j - 1]) {
			Swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

int IfEqual(char arr[], char arr3[], int size) {
	for (int i = 0;i < size; ++i) {
		if (arr[i] != arr3[i]) {
			return 0;
		}
	}
}

int Concatenation(char arr1[], char arr2[], char arr3[]) {
	int size1 = StringLength(arr1);
	int size2 = StringLength(arr2);
	int size3 = StringLength(arr3);

	int flag1 = IfLatinSmallLetters(arr1);
	if (flag1 == -1) {
		return -1;
	}
	int flag2 = IfLatinSmallLetters(arr2);
	if (flag2 == -1) {
		return -1;
	}
	int flag3 = IfLatinSmallLetters(arr3);
	if (flag3 == -1) {
		return -1;
	}

	if ((size1 + size2) != size3) {//if the size of the firstr and the second array is different from the size of the third array, return 0
		return 0;
	}
	bool ChosenArrayFlag = false;//deciding which array is shorter, so we do less loops

	//adding the elements of the second array to the first
	if (size1 >= size2) {                                              
		int counter = 0;

		for (int i = size1; i < (size1 + size2);i++) {
			if (counter > size2) {
				break;
			}

			arr1[i] = arr2[counter];
			counter++;
			//first array
		}
	}
	// from first to second
	else if (size1 < size2){
		int counter = 0;

		for (int i = size2; i < (size1 + size2);i++) {
			if (counter > size1) {
				break;
			}
			arr2[i] = arr1[counter];
			counter++;
		}
		ChosenArrayFlag = true;//second array
	}	
	InsertionSort(arr3);//sorting the third array, so we compare each element of the first/second array and if 
	//an element is different: arr(1/2)[i] != arr3[i], we return 0
	if (ChosenArrayFlag) {
		InsertionSort(arr2);
		IfEqual(arr2, arr3, size3);
	}
	else {
		InsertionSort(arr1);
		IfEqual(arr1, arr3, size3);
	}
	return 1;
}
	

int main()
{
	char strArr1[MAX_SIZE] = { '\0' };
    char strArr2[MAX_SIZE] = { '\0' };
    char strArr3[MAX_SIZE] = { '\0' };
    cin >> strArr1 >> strArr2 >> strArr3;

	cout << Concatenation(strArr1, strArr2, strArr3) << endl;

}