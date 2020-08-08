#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//짝수 사각진

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int c[3][3];
	int x = 1, y = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &c[y][x]);

			if (j < 2)
			{
				x++;
				y--;

				if (x > 2)
					x = 0;
				if (y < 0)
					y = 2;
			}
			else
				y++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
