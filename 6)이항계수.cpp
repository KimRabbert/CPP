#include <iostream>
using namespace std;

int fac(int);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, c;

	scanf("%d", &n);

	int i, j;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			c = fac(i) / fac(j) / fac(i - j);
			printf("%d ", c);
		}

		printf("\n");
	}
}

int fac(int k)
{
	int a[11] = { 0, };

	if (k == 0)
		return 1;
	else if (a[k] == 0)
		return a[k] = k * fac(k - 1);
	else
		return a[k];
}