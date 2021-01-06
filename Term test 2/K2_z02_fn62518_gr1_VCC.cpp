// Danail Nenkov - 62518

#include <iostream>

using namespace std;

int Between0and20(int& n) {
	do {
		cin >> n;
	} while (n < -1 && n>21);
	return n;
}

void InsertArray(int arr[], int& n) {
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
}

int SearchIndex(int arr[], int& n, int& counter, int& maxSum, int& index) {//counter should stop at n-1
	int currentSum = (arr[counter - 1] + arr[counter + 1]) / 2;
	if (n < 3) {
		return -1;
	}
	if (n == 3) {
		index = 1;
	}
	if (counter == (n - 1)) {
		return index;
	}
	if (maxSum < currentSum) {
	maxSum = currentSum;
	index = counter;
	}
	return SearchIndex(arr, n, ++counter, maxSum, index);
	
}


int main(){
	int n;
	const int MAX_SIZE = 21;
	int counter = 1;
	int index = 0;

	int arr[MAX_SIZE];

	Between0and20(n);
	InsertArray(arr, n);

	int maxSum = (arr[0] + arr[2]) / 2;

	cout << SearchIndex(arr,n,counter,maxSum, index);

}




