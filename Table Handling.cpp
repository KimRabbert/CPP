#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n[101][101] = { 0, };
	int i, j;
	int w, f;
	int a, b;
	int sum = 0;

	scanf("%d", &w);

	for (i = 0; i < w; i++)
		scanf("%d", &n[i + 1][0]);

	for (i = 0; i < w; i++)
		scanf("%d", &n[0][i + 1]);

	for (i = 0; i < w; i++)
	{
		for (j = 0; j < w; j++)
		{
			n[i + 1][j + 1] = n[i + 1][0] + n[0][j + 1];
		}
	}

	scanf("%d", &f);

	for (i = 0; i < f; i++)
	{
		scanf("%d %d", &a, &b);

		for (j = 1; j <= w; j++)
		{
			sum += n[a][j];
			n[a][j] = 0;
		}

		for (j = 1; j <= w; j++)
		{
			sum += n[j][b];
			n[j][b] = 0;
		}
	}

	printf("%d", sum);

	return 0;
}
