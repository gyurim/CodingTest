#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char cmd[100];
	int count[27];

	cin >> cmd;

	for (int i = 0; i < 26; i++) {
		count[i] = -1;
	}

	for (int i = 0; i < strlen(cmd); i++) {
		if (count[cmd[i]-'a'] == -1) {
			count[cmd[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << count[i] << " ";
	}

	return 0;
}