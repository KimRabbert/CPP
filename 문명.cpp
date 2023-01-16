#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int c[2002][2002][2];
int list[100001];
int queue[4000001][2];
int qf = 0, qb = 0, qb2 = 0;

void dich(int q[], int *k);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k, x, y;
	int cnt = 0;
	
	scanf("%d %d", &n, &k);

	int t = k;

	int i, j;

	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
		{
			c[i][0][0] = -1;
			c[0][i][0] = -1;
			c[i][n + 1][0] = -1;
			c[n + 1][i][0] = -1;
		}
	}

	for (i = 1; i <= k; i++)
	{
		scanf("%d %d", &x, &y);
		c[y][x][0] = i;
		list[i] = i;
		queue[i - 1][0] = x;
		queue[i - 1][1] = y;
		qb2++;
		c[y][x][1] = 1;
	}

	qb = qb2;

	for (i = 0; i < k; i++)
		dich(queue[i], &t);
	qf = qb;
	qb = qb2;

	int tx, ty;

	while (t > 1)
	{
		for (i = qf; i < qb; i++)
		{
			tx = queue[i][0];
			ty = queue[i][1];

			c[ty][tx][1] = 1;
			dich(queue[i], &t);
		}
		qf = qb;
		qb = qb2;
		cnt++;
	}

	printf("%d", cnt);

	return 0;
}

void dich(int q[], int *k)
{
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int x = q[0];
	int y = q[1];
	int tx, ty;

	for (int i = 0; i < 4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];

		if (c[ty][tx][0] != 0 && c[ty][tx][0] != -1 && list[c[ty][tx][0]] != list[c[y][x][0]] && c[ty][tx][1] == 1)
		{
			list[c[ty][tx][0]] = list[c[y][x][0]];
			*k = *k - 1;
		}
		else if (c[ty][tx][0] == 0)
		{
			c[ty][tx][0] = c[y][x][0];
			queue[qb2][0] = tx;
			queue[qb2][1] = ty;
			qb2++;
		}
	}
}
