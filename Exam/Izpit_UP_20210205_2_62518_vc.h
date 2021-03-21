//Danail Petrov Nenkov FN:62518

#pragma once
#ifndef FN62518
#define FN62518 1

int My_StrLen(char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}
bool checkstr(char* str) {
	int size = My_StrLen(str);
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			if (str[i] > 'z' || str[i] < 'a') {//checking if even index is between 'a' and 'z'
				return false;
			}
		}
		else if (i % 2 == 1 ) {
			if (str[i] > 'Z' || str[i] < 'A') {//checking if odd index is between 'A' and 'Z'
				return false;
			}
		}
	}
	return true;
}

char* GetWord(char str[]) {
	int size = My_StrLen(str);
	int numberOfWords = 0;
	int wordsStartingWithLetter = 0;

	bool flag = false;
	for (int i = 0; i < size; i++) {
		flag = false;
		while (str[i] != ' ' && str[i] != '\t' && i < size) {//deciding which word starts with 'a' and how many words are there
			if (str[i] != ' ' && str[i] != '\t') {
				if (flag == false) {
					numberOfWords++;
					if (str[i] == 'a') {
						wordsStartingWithLetter++;
					}
				}
				flag = true;
			}
			i++;
		}
	}
	char* result = new char[size];//creating a dynamic str
	int sizeOfNewstr = 0;

	int firstArr[5];
	int indexFirstArr = 0;
	while (wordsStartingWithLetter != 0) {//deciding how many digits the numbers have
		firstArr[indexFirstArr] = wordsStartingWithLetter % 10;
		indexFirstArr++;
		wordsStartingWithLetter /= 10;
	}

	int secondArr[5];
	int indexSecondArr = 0;
	while (numberOfWords != 0) {
		secondArr[indexSecondArr] = numberOfWords % 10;
		indexSecondArr++;
		numberOfWords /= 10;
	}

	for (int i = indexFirstArr-1; i >= 0; i--) {//adding their ASCII codes to the new str
		result[sizeOfNewstr] = firstArr[i] + '0';
		sizeOfNewstr++;
	}
	result[sizeOfNewstr] = ' ';
	sizeOfNewstr++;
	for (int i = indexSecondArr-1; i >= 0; i--) {
		result[sizeOfNewstr] = secondArr[i] + '0';
		sizeOfNewstr++;
	}
	result[sizeOfNewstr] = '\0';

	return result;
}

void My_swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void SelectionSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] <= arr[j - 1]) {
			My_swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

int AnalyzeNum(long N) {
	int size = 0;
	int arr[15];	
	
	while (N != 0) {
		arr[size] = N % 10;
		size++;
		N /= 10;

	}
	SelectionSort(arr, size);
	int* addArray = new int[15];
	int indexAddArray = 0;
	addArray[indexAddArray] = arr[0];
	indexAddArray++;

	for (int i = 1; i < size; i++) {
		bool alreadyWritten = false;
		for (int k = 0; k < indexAddArray; k++) {
			if (arr[i] == addArray[k]) {
				alreadyWritten = true;
				break;
			}
		}
		if (alreadyWritten == true) {
			continue;
		}
		addArray[indexAddArray] = arr[i];
		indexAddArray++;

		bool dublicate = false;
		for (int j = i+1; j < size; j++) {
			if (arr[i] == arr[j]) {
				dublicate = true;
				break;
			}
		}
		if (dublicate == true) {
			continue;
		}
	}

	if ((indexAddArray) % 2 == 0) {
		delete[] addArray;
		return -1;
	}
	if (addArray[(indexAddArray) / 2] == addArray[(indexAddArray - 2) / 2] || addArray[(indexAddArray) / 2] == addArray[(indexAddArray + 1) / 2]) {
		delete[] addArray;
		return -1;
	}
	int result = addArray[(indexAddArray) / 2];
	delete[] addArray;
	return result;
}
#endif // !FN62518

