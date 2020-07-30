#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char plate[150][150] = { 0, };
	int px, py;
	int ml, mw, mx, my;
	int n, i, j, k;
	char t;

	scanf("%d %d", &py, &px);
	scanf("%d", &n);

	for (i = 0; i < py; i++)
	{
		for (j = 0; j < px; j++)
		{
			plate[i][j] = ' ';
		}
	}

	for (k = 0; k < n; k++)
	{
		scanf("%d %d %d %d", &ml, &mw, &my, &mx);
		for (i = 0; i < ml; i++)
		{
			for (j = 0; j < mw; j++)
			{
				scanf("%c", &t);
				scanf("%c", &plate[my + i - 1][mx + j - 1]);
			}
		}

	}

	for (i = 0; i < py; i++)
	{
		for (j = 0; j < px; j++)
		{
			printf("%c ", plate[i][j]);
		}
		printf("\n");
	}

	return 0;
}