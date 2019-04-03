#include <fstream>
#include <iostream>
#include <string>
using namespace std;

char al[26] = { 0, };
char a, maxc;
string t;
int i, l, j;
int n, as, max = 0;

int main()
{
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");

	in >> n;
	in.ignore();

	for (i = 1; i <= n; i++)
	{
		getline(in, t);
		l = t.length();

		for (j = 0; j < l; j++)
		{
			a = t[j];
			if (a != ' ' && a != '.')
			{
				if (a > 90) a = a - 32;
				as = a;

				al[as - 65] ++;
			}
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (al[i] > max)
		{
			max = al[i];
			maxc = i + 65;
		}
	}

	out << maxc << ' ' << max;

	in.close();
	out.close();

	return 0;
}