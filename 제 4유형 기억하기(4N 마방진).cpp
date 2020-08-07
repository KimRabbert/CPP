#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m[1000][1000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);


	int i, j;

	for (i = 1; i <= n / 2; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i % 2 == 1)
			{
				if (j % 2 == 1)
				{
					m[j][i * 2 - 1] = (i - 1) * n + j;
					m[j][i * 2] = n * n - ((i - 1) * n + j) + 1;
				}
				else
				{
					m[j][i * 2 - 1] = n * n - ((i - 1) * n + j) + 1;
					m[j][i * 2] = (i - 1) * n + j;
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					m[n - j + 1][i * 2 - 1] = (i - 1) * n + j;
					m[n - j + 1][i * 2] = n * n - ((i - 1) * n + j) + 1;
				}
				else
				{
					m[n - j + 1][i * 2 - 1] = n * n - ((i - 1) * n + j) + 1;
					m[n - j + 1][i * 2] = (i - 1) * n + j;
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
	return 0;
}
