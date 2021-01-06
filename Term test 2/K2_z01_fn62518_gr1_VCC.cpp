// Danail Nenkov - 62518

#include <iostream>

using namespace std;

int PositiveNumber(int& n) {
	do {
		cin >> n;
	} while (n < 0);
	return n;
}
int Difference(int& n, int& m) {
	if (n < 10 && m == 1) {
		return 0;
	}
	if (n < m * 10) {
		return -10;
	}
	int additionalNumber = 0;
	int firstNumberInDifference;
	firstNumberInDifference = n % 10;
	for (int i = 0; i < m;i++) {
		additionalNumber = n % 10;
		n = n / 10;
	}
	return firstNumberInDifference - additionalNumber;
}

int main()
{
	int M = 0;//position
	int N = 0;//actual number
	PositiveNumber(N);
	PositiveNumber(M);

	cout << Difference(N, M);
}
