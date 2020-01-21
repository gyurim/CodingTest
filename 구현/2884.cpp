/***********************************************
			BOJ 2884
***********************************************/
#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;

	int result = (h * 60 + m) - 45; 
	int re_h;
	int re_m;

	if (result >= 0) {
		re_m = result % 60;
		re_h = (result - re_m) / 60;
		cout << re_h << " " << re_m;
	}
	else {
		cout << "23 " << result + 60;
	}
	

	return 0;
}