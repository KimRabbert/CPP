#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;
	int a;
	int cnt = 0;
	int i, j;
	int flag = 0;

	scanf("%d %d", &y, &x);
	scanf("%d", &a);

	for (i = y; i > 0; i--)
	{
		for (j = 1; j <= x; j++)
		{
			cnt++;
			if (cnt == a)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	printf("%d %d", i, j);

	return 0;
}
