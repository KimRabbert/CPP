#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int p[10001][10001] = { 0, };

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;
	int n;
	int i, j;
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1 , 0 };

	scanf("%d %d", &y, &x);
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &p[i][j]);

	while (1)
	{
		printf("%d %d\n", y, x);
		p[y][x] = 0;

		for (i = 0; i < 4; i++)
		{
			if (p[y + dy[i]][x + dx[i]])
			{
				y += dy[i];
				x += dx[i];
				break;
			}
		}

		if (i == 4)
			break;
	}

	return 0;
}
