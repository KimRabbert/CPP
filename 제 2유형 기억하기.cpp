#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int c, w;

	int a[100][100] = { 0, };
	int cnt = 0;
	int i, j;

	scanf("%d", &w);
	scanf("%d", &c);
	
	if (c == 1)
	{
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				a[j][i - j] = ++cnt;
			}
		}
	}
	else if (c == 2)
	{
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				a[w - j - 1][i - j] = ++cnt;
			}
		}
	}
	else if (c == 3)
	{
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				a[i - j][w - j - 1] = ++cnt;
			}
		}
	}
	else if (c == 4)
	{
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < i + 1; j++)
			{
				a[w - j - 1][w - i + j - 1] = ++cnt;
			}
		}
	}

	for (i = 0; i < w; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
