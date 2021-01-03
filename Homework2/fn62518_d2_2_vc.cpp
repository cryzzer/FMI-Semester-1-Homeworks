/**
*
* Solution to homework assignment 1
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

const int MAX_SIZE = 367;

int main()
{
    int inputNumber;
    double arr[MAX_SIZE];

    double profit = 0;
    double localMin;
    double localMax;
    int endLoop = 0;
    cin >> inputNumber;
    while ((inputNumber < 3) || (inputNumber > 365)) {
        cin >> inputNumber;
    }

    for (int i = 0; i < inputNumber; i++) {
        do {
            cin >> arr[i];
        } while ((arr[i] < 0.1) || (arr[i] > 100));
    }
    //The main logic here is that you start from position 0, and search for a maximum, after you find one, if the next number is lower than the maximum the loop breaks,
    //when we search for the maximum we also search for the minimum between postion 0 and the maximum, after that we calculate the profit and continue to search the array,
    //for other maximums and minimums, but now the start of the search is the number after the first maximum and searches 'till the end.
    for (int i = 0;i < inputNumber - 1;i++) {
        int gap = 0;
        int temp = inputNumber - 1;
        localMin = arr[i];
        localMax = arr[i];

        for (int j = i + 1;j < inputNumber;j++) {
            gap++;
            if (localMax > arr[j]) {
                endLoop = j - 1;
                break;
            }
            if (localMin > arr[j]) {
                localMin = arr[j];
            }
            if (localMax < arr[j]) {
                localMax = arr[j];
            }
        }
        profit += localMax - localMin;
        if (i == temp - gap)break;
        i = endLoop;
    }
    cout << profit;
    return 0;
}