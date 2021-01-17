/**
*
* Solution to homework assignment 4
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

bool IfCorrectConditions(int arr[], int maxTimesSwapped, int size) {
    int correctCounter = 0;//if a number is lower or equal to the next number on the right
    int incorrectCounter = 0;//opposite of the statement above
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            correctCounter++;
        }
        else {
            incorrectCounter++;
        }
    }
    //if the incorrect counter is greater than the correct one and the maximum allowed swaps, return false
    if (incorrectCounter > correctCounter && incorrectCounter > maxTimesSwapped) {
        return false;
    }
    int trueCounter = (correctCounter < incorrectCounter) ? correctCounter : incorrectCounter;
    if (trueCounter <= maxTimesSwapped) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{   
    int maxTimesSwapped = 0;
    do {
        cin >> maxTimesSwapped;
    } while (maxTimesSwapped <= 0);//must be a nubrer, greater than 0



    int size;

    do {
        cin >> size;
    } while (size <= 0);//must be a nubrer, greater than 0

    int* arr1 = new int[size];//creating a dinamic array


    for (int i = 0; i < size; i++) {
        do {
            cin >> arr1[i];//must be a nubrer, greater than 0
        } while (arr1[i] <= 0);
    }
    cout << IfCorrectConditions(arr1, maxTimesSwapped, size);

    delete[] arr1;//deleting dinamic array
}