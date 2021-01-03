/**
*
* Solution to homework assignment 1
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

int main()
{
	int N_numberOfBirthday = 0, M_costOfToy = 0, X_priceOfLaptop = 0;
	// Inserting N , M , X
	do {
		cin >> N_numberOfBirthday;
	} while (N_numberOfBirthday <= 0);

	do {
		cin >> X_priceOfLaptop;
	} while (X_priceOfLaptop < 0);
	do {
		cin >> M_costOfToy;
	} while (M_costOfToy <= -1);

			//some helpful unsigned integers
	unsigned int evenBirthdays = 0, oddBirthdays = 0;
	unsigned int moneyFromEvenBirthdays = 0;
	unsigned int money_From_Odd_Birthdays = 0;
	int extra_or_lack_of_money = 0,
		allAvailableMoney = 0;

	//Deciding if the birthday is even or odd                                     
	if (N_numberOfBirthday % 2 == 0) {
		evenBirthdays = N_numberOfBirthday / 2;
		oddBirthdays = N_numberOfBirthday / 2;
	}
	else if (N_numberOfBirthday % 2 == 1) {
		evenBirthdays = N_numberOfBirthday / 2;
		oddBirthdays = (N_numberOfBirthday / 2) + 1;
	}
	//calculating how much money he got from his even birthdays
	for (int i = 1; i <= evenBirthdays; i++) {
		moneyFromEvenBirthdays = moneyFromEvenBirthdays + (30 * i);
	}
	moneyFromEvenBirthdays = moneyFromEvenBirthdays - evenBirthdays * 5;//calculating the money when he gives away 5 leva
																		//each birthday when he gets money for his friends
	
	money_From_Odd_Birthdays = oddBirthdays * M_costOfToy;//money from all odd birthdays when he sells his toys

	allAvailableMoney = moneyFromEvenBirthdays + money_From_Odd_Birthdays;
	if (allAvailableMoney < X_priceOfLaptop) {
		extra_or_lack_of_money = X_priceOfLaptop - allAvailableMoney;
		cout << "no" << endl << extra_or_lack_of_money << endl;
	}
	else {
		extra_or_lack_of_money = allAvailableMoney - X_priceOfLaptop;
		cout << "yes" << endl << extra_or_lack_of_money << endl;
	}
	return 0;

}
