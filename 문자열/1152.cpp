#include <iostream>
#include <string.h>   
using namespace std;

int main() {
	char cmd[1000000];
	cin.getline(cmd, 1000000, '\n'); //엔터입력할때까지 입력받음

	int count = 1;

	if (cmd[0] == ' ')
		count = 0;

	for (int i = 0; i<=strlen(cmd); i++) {
		if (cmd[i] == ' ') {
			count++;
		}
	}
	
	if (cmd[strlen(cmd) - 1] == ' ')
		count--;
	/*
	cmd[strlen(cmd) -1]에서 -1해주는 이유는
	strlen(cmd)가 크기를 나타내고 cmd배열은 0부터 시작하니까
	배열의 마지막 값은 "크기-1"에 해당하는 index에 저장되어있음
	*/
	cout << count;
	return 0;
}