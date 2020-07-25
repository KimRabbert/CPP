#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w;
	char c[10];
	int f;
	int i, j, k;
	int x1, y1, x2, y2;
	int a[100][100] = { 0, };
	int clip[100][100] = { 0, };
	int clx, cly;

	scanf("%d %d", &w, &h);
	scanf("%d", &f);

	for (i = 1; i < h + 1; i++)
	{
		for (j = 1; j < w + 1; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (i = 0; i < f; i++)
	{
		scanf("%s", c);

		if (strcmp(c, "Copy") == 0)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			clx = x2 - x1;
			cly = y2 - y1;
			for (j = y1; j <= y2; j++)
			{
				for (k = x1; k <= x2; k++)
				{
					clip[j - y1 + 1][k - x1 + 1] = a[j][k];
				}
			}
		}
		else if (strcmp(c, "Cut") == 0)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			clx = x2 - x1;
			cly = y2 - y1;
			for (j = y1; j <= y2; j++)
			{
				for (k = x1; k <= x2; k++)
				{
					clip[j - y1 + 1][k - x1 + 1] = a[j][k];
					a[j][k] = 0;
				}
			}
		}
		else if (strcmp(c, "Paste") == 0)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

			for (j = y1; j <= y2; j++)
			{
				for (k = x1; k <= x2; k++)
				{
					a[j][k] = clip[j - y1 + 1][k - x1 + 1];
				}
			}

		}
		else if (strcmp(c, "Delete") == 0)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

			for (j = y1; j <= y2; j++)
			{
				for (k = x1; k <= x2; k++)
				{
					a[j][k] = 0;
				}
			}

		}
		else if (strcmp(c, "PutPixel") == 0)
		{
			scanf("%d %d", &x1, &y1);

			a[y1][x1] = 1;
		}
	}

	for (i = 1; i <= h; i++)
	{
		for (j = 1; j <= w; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}

