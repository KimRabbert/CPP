#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int alphabet[26] = { 0, };
	char s[1000001];
	int max = 0;
	int maxc;
	int maxcount = 0;

	scanf("%s", s);

	// �ܾ�� ���ĺ� ��ҹ��� ������� ī��Ʈ
	for (int i = 0; s[i] != NULL; i++) {
		if (s[i] > 96)
			alphabet[s[i] - 97]++;
		else
			alphabet[s[i] - 65]++;
	}

	// �ܾ�� ���� ���� ���� ���ĺ� ã��
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > max) {
			max = alphabet[i];
			maxc = i;
			maxcount = 1;
		}
		else if (alphabet[i] == max)
			maxcount++;
	}

	// �ܾ�� ���� ���� ���� ���ĺ��� ���� ���� ��� '?' ���
	if (maxcount > 1)
		printf("\?");
	else // �� ���� ��� �빮�ڷ� ���
		printf("%c", maxc + 65);
}