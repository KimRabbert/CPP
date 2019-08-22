#include <iostream>

void task(int, int);

int parent[10];
int rank[10];

int main()
{
	int i;

	for (i = 1; i <= 9; i++)
	{
		parent[i] = i;

		rank[i] = 0;
	}

	task(2, 5);
	task(6, 9);
	task(5, 6);
	task(5, 2);

	return 0;
}

int FIND(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = FIND(parent[x]);
}

void UNION(int x, int y)
{
	int u, v;
	u = FIND(x);
	v = FIND(y);

	if (rank[u] > rank[v])
		parent[v] = u;
	else
	{
		parent[u] = v;
		if (rank[u] == rank[v])
			rank[v] ++;
	}
}

void task(int p, int q)
{
	int pset, qset;
	pset = FIND(p);
	qset = FIND(q);
	if (pset != qset)
		UNION(pset, qset);
	printf("%d", parent[2]);
}