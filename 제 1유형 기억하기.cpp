#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w;
	char a[100][150];

	scanf("%d %d", &h, &w);

	int x = h + w - 1;

	int i, j;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < x; j++)
			a[i][j] = '-';
	}

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			a[i][i + j] = '@';
			a[i][x - i - j - 1] = '@';
		}
	}
	
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < x; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
