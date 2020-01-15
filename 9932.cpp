/**********************************************************************************************
					9934번 완전 이진 트리
**********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, k_sum = 1;
	int total = 0;
	vector <int>v;
	vector <int>node_v;
	
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		total += k_sum;
		v.push_back(k_sum);
		k_sum = k_sum * 2;
	}

	for (int i = 0; i < total; i++) {
		int node;
		cin >> node;
		node_v.push_back(node);
	}

	for (int j = 0; j < k; j++) {
		int total_temp = 0;
		int temp = 0;
		int total_sum = 0;

		for (int i = 0; i < v[j]; i++) {
			if (i == 0) {
				total = total / 2;
				temp = (total + 1) * 2;
				total_sum = total;
			}
		
			cout << node_v[total_sum + total_temp]<<" ";
			total_sum += total_temp;
			total_temp = temp;
		}
		cout << "\n";
	}
	return 0;
}