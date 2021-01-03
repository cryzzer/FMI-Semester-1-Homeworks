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

int main()
{
    //setting some variables, so we can track the second highest number
    int imput_number = 0;
    int second_highest_number = 0;
    int first_highest_number = 0;
    int variable = 0;
   
    //setting a counter, so if the user validates 1 or less positive numbers, it gives an error -1
    int counter = 0;

	cin >> imput_number;
    first_highest_number = imput_number;
    second_highest_number = imput_number;
    
    //creating a loop, when the mput number is 0 or less, the loop ends
    while (imput_number > 0) {
        //in this "if" if the number the user enteres is bigger number than the highest number, the second highest
        // takes the first highest value and the first highest takes the imput's value
        if (imput_number > first_highest_number) {
            second_highest_number = first_highest_number;
            first_highest_number = imput_number;
        }

        //otherwise we remember what was the vaue of the inputed number
        else {
            variable = imput_number;
        }

        //to finish the loop, we check if there hase been a second highest number entered, and if true, 
        //second_highest_number takes its value
        if ((first_highest_number > second_highest_number) && (second_highest_number < variable)) {
            second_highest_number = variable;
        }

		cin >> imput_number;//and we repeat the loop

        counter++;//here we add 1 to the counter to check if there has been entered 1 or less positive numbers
                  //we check it with the last "if" if there are 2 or more positive numbers entered, otherwise we give 
                  //second_highest_number a value of -1
    }
    if (counter < 2) {
        second_highest_number = -1;
    }
    if (first_highest_number == second_highest_number) { //printing -1, because the first and the second highest number
        second_highest_number = -1;                      //are equal, and there isn't second highest nubmer
    }

    cout << second_highest_number;
    return 0;
}
