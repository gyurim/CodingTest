#include <iostream>
#include <string.h>   
using namespace std;

int main() {
	char cmd[1000000];
	cin.getline(cmd, 1000000, '\n'); //�����Է��Ҷ����� �Է¹���

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
	cmd[strlen(cmd) -1]���� -1���ִ� ������
	strlen(cmd)�� ũ�⸦ ��Ÿ���� cmd�迭�� 0���� �����ϴϱ�
	�迭�� ������ ���� "ũ��-1"�� �ش��ϴ� index�� ����Ǿ�����
	*/
	cout << count;
	return 0;
}