/**
*
* Solution to homework assignment 3
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
#include <fstream>

using namespace std;

int StringLength(char arr[]) {
    int size = 0;
    while (arr[size]) {
        size++;
    }
    return size;
}
int IfLatinLetters(char arr[]) {
    int size = StringLength(arr);
    for (int i = 0; i < size;i++) {
        if (((arr[i] < 'A') || (arr[i] > 'Z')) && ((arr[i] < 'a') || (arr[i] > 'z'))) {
            return false;
        }
    }
}

void Swap(char& a, char& b) {
    char c = a;
    a = b;
    b = c;
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

int main()
{
    const int MAX_SIZE = 180;
    const int MAX_ROWS = 1000;
    char stringArray[MAX_SIZE];

    char outputArray[MAX_ROWS] = { '\0' };//the array where you write the decrypted letters
    int counter = 0;//the index of the output stream
    int nextCharacter = 1;//changing the ASCII code of the element

    ifstream homeworkFile;
    homeworkFile.open("message.txt", ios::in);

    if (!homeworkFile) {
        cout << "-2" << endl;//if it does not open, or could not read the file
    }

    if (!homeworkFile.eof()) {
        while (homeworkFile.getline(stringArray, MAX_SIZE, '\n')) {
            int sizeOfStringArray = StringLength(stringArray);
            if (sizeOfStringArray > 151) {//if the size of the row is higher than 150/ return -1
                cout << "-1" << endl;
                return 1;
            }
            bool flag = IfLatinLetters(stringArray);
            if (flag == false) {
                cout << "-1" << endl;//if there aren't latin letters only, return -1
                return 1;
            }
            InsertionSort(stringArray);//sorting the row
            for (int i = 0; i < sizeOfStringArray; i++) {
                if (stringArray[i + 1] == '\n') {//if the first row is empty, we continue with the next one
                    break;
                }

                if (((stringArray[i] + nextCharacter) > 'Z') && ((stringArray[i] + nextCharacter) == '[')) {//use this to jump from capital Z to small a
                    nextCharacter = 7;
                }
                //in this if we check if there is no possible outcome, and if there isn't we put .
                if (stringArray[sizeOfStringArray - 1] == 'z') {
                    int index = 0;
                    for (int j = sizeOfStringArray - 1; j > 0; j--) {
                        if ((stringArray[j] == 'a') && (stringArray[j - 1] == 'Z')) {//using this to jump again
                            continue;
                        }
                        if ((stringArray[j] - 1) != stringArray[j - 1]) {
                            index = 1;//this index indicates if there is a letter which we can use to decrypt the message
                            break;
                        }
                    }
                    if (index == 0) {//if the index is still 0, we put .
                        outputArray[counter] = '.';
                        counter++;
                        break;
                    }
                    index = 0;
                }
                //in normal row, we check which letter is possible to be put in the array, as long as it doesnt exist in the current one
                if ((stringArray[i] + nextCharacter) != stringArray[i + 1]) {
                    outputArray[counter] = (stringArray[i] + nextCharacter);
                    counter++;
                    nextCharacter = 1;
                    break;
                }
                else {
                    nextCharacter = 1;
                    continue;
                }
            } 
        }
    }
    homeworkFile.close(); 

    cout << outputArray << endl;

    return 0;
}

