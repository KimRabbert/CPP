#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sa[1000][1000];
int omr[1000][1000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j, k, s, sq, ox, oy;
	int count = 0;

	scanf("%d", &s);
	scanf("%d", &sq);

	for (i = 0; i < s; i++)
		for (j = 0; j < sq; j++)
			scanf("%d", &sa[i][j]);

	scanf("%d %d", &oy, &ox);


	for (i = 0; i < oy; i++)
		for (j = 0; j < ox * s; j++)
			scanf("%d", &omr[i][j]);

	for (i = 0; i < s; i++)
	{
		for (j = 0; j < ox; j++)
		{
			for (k = 0; k < oy; k++)
			{
				if (omr[k][j + (i * ox)] == sa[i][j * oy + k])
					count++;
			}
		}
		printf("%d ", count);
		count = 0;
	}

	return 0;
}
