#pragma once

#ifndef Variant1
#define variant1 1

#include <iostream>
using namespace std;

//taking the size of the string
int MyStrlen(char* str) {
	int size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}

//swaping 2 characters
void MySwap(char& a, char& b) {
	char c = a;
	a = b;
	b = c;
}

char* revandreplace(char* str) {
	int sizeOfStr = MyStrlen(str);
	int j = sizeOfStr - 1;//the integer starts from the end of the string
	for (int i = 0; i < sizeOfStr / 2; i++) {
		MySwap(str[i], str[j]);//swapping the 1st and the last char, then the second and the char before the last and so on
		j--;//reducing the index of the last char to be swaped
	}

	for (int i = 0; i < sizeOfStr; i++) {
		if (str[i] == 'e') {//checking if char is equal to 'e' and swapping him with '!'
			str[i] = '!';
		}
		else if (str[i] == 'y') {//same logic here, but different symbols
			str[i] = '*';
		}
	}
	return str;
}
//===========================================================================================

bool CheckDate(char str[]) {     //YYYY g.
	int size = MyStrlen(str);
	//checking if there are less symbols or more symbols than needed
	if (size != 7) {
		return 0;
	}

	//checking if every symbols is either a number where it has to be ot empty space + 'g' + '.'
	bool trueDate = false;	
	if (str[0] >= '0' && str[0] <= '9') {
		if (str[1] >= '0' && str[1] <= '9') {
			if (str[2] >= '0' && str[2] <= '9') {
				if (str[3] >= '0' && str[3] <= '9') {
					if (str[4] == ' ') {
						if (str[5] == 'g') {
							if (str[6] == '.') {
								trueDate = true;
							}
						}
					}
				}
			}
		}
	}

	if (!trueDate) {//if not valid date, return false
		return false;
	}

	int date = 0;
	int digit = 0;
	while (str[digit] == '0' || str[digit] == ' ') {
		digit++;
	}
	if (digit > 4) {//if all digits are zeros, the date is 0000 which is not a leap year
		return 0;
	}
	bool fistTime = true;//not multiplying with 10 for first entered number
	for (int i = digit - 1; i < 4; i++) {
		if (i < 0) {//if i is a negative number(-1), add 1 to it to become 0
			++i;
		}
		//then basically converting a number in string into an integer number by multiplying by 10 and converting the digit
		int multiplier = 10;
		if (fistTime) {
			fistTime = false;
		}
		else {
			date *= multiplier;
		}

		date += str[i] - '0';
	}	
	if (date % 4 == 0 || date % 100 == 0 || date % 400 == 0) {//last checking if number is a leap year
		return 1;
	}

	return 0;
}
//====================================================================================================
int* countletters(int firstArr[], int secondArr[], int N) {
	int* sumArr = new int[N];
	int* result = new int[2]{ 0, 0 };
	for (int i = 0; i < N; i++) {
		sumArr[i] = firstArr[i] + secondArr[i];
		if (sumArr[i] >= 65 && sumArr[i] <= 90) {
			result[0]++;
		}
		else if (sumArr[i] >= 97 && sumArr[i] <= 122) {
			result[1]++;
		}
	}
	delete[] sumArr;
	return result;
}

#endif // !Variant1
