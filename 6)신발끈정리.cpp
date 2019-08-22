#include <iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a[100][2], n;
	int i;
	int sum1 = 0, sum2 = 0, r;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &a[i][0], &a[i][1]);

	a[n][0] = a[0][0];
	a[n][1] = a[0][1];

	for (i = 0; i < n; i++)
	{
		sum1 += a[i][0] * a[i + 1][1];
		sum2 += a[i][1] * a[i + 1][0];
	}

	if (sum1 > sum2)
		r = sum1 - sum2;
	else
		r = sum2 - sum1;

	printf("%d", r / 2);
}