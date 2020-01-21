/***********************************************
			BOJ 2798
***********************************************/
#include <iostream>
using namespace std;
int main() {
	int n, m;
	int arr[100];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	int arr_sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (m >= arr[i] + arr[j] + arr[k]) {
				
					if (m - arr_sum > (m - (arr[i] + arr[j] + arr[k]))) {
						arr_sum = arr[i] + arr[j] + arr[k];
					}
				}
			}
		}
	}
	cout << arr_sum;

	return 0;
}