/***********************************************
		1991번 트리 순회
***********************************************/
#include <iostream>
#include <vector>
using namespace std;
vector <char> v[27];

void preorder(char root) {
	cout << root;
	if (v[root - 'A'][0] != '.') {
		preorder(v[root - 'A'][0]);
	}
	if (v[root-'A'][1] != '.') {
		preorder(v[root - 'A'][1]);
	}
};

void inorder(char root) {
	if (v[root-'A'][0] != '.') {
		inorder(v[root - 'A'][0]);
	}
	cout << root;
	if (v[root-'A'][1] != '.') {
		inorder(v[root - 'A'][1]);
	}
};

void postorder(char root) {
	if (v[root-'A'][0] != '.') {
		postorder(v[root - 'A'][0]);
	}
	if (v[root-'A'][1] != '.') {
		postorder(v[root - 'A'][1]);
	}
	cout << root;
};

int main() {
	int num; 
	cin >> num;

	for (int i = 0; i < num; i++) {
		char node, left, right;
		cin >> node >> left >> right;

		v[node - 'A'].push_back(left);
		v[node - 'A'].push_back(right);		
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;

}