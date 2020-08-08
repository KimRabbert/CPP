#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//¹ö¹Â´Ù

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int di[3] = { 0, 1, -1 };
	int dj[3] = { 1, -1, 0 };
	int n, i, j, d, k, a;
	int b[101][101] = { 0, };
	d = 0;
	a = 0;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		a += i;

	for (i = 0; i <= n + 2; i++)
	{
		b[0][i] = -1;
		b[i][0] = -1;
		b[i][n - i + 2] = -1;
	}

	i = 1; j = 1;
	for (k = 1; k <= a; k++)
	{
		b[i][j] = k;

		if (b[i + di[d]][j + dj[d]] != 0)
			d = (d + 1) % 3;

		i = i + di[d];
		j = j + dj[d];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i + 1; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}

	return 0;
}
