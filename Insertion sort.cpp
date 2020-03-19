#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct A
{
	string name;
	int g, s, b;
	int flag = 0;
};

int main()
{
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");

	A a[200];
	A x;
	int n, i, j;
	string rank[200] = {"1st", "2nd", "3rd", "4th", };
	stringstream s;

	in >> n;

	for (i = 3; i < n; i++)
	{

		rank[i] = (i + 1) + "st";
	}
	for (i = 0; i < n; i++)
		in >> a[i].name >> a[i].g >> a[i].s >> a[i].b;

	for (i = 1; i < n; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j].g < a[j + 1].g)
			{
				x = a[j]; a[j] = a[j + 1]; a[j + 1] = x;
			}
			else if (a[j].g == a[j + 1].g)
			{
				if (a[j].s < a[j + 1].s)
				{
					x = a[j]; a[j] = a[j + 1]; a[j + 1] = x;
				}
				else if (a[j].s == a[j + 1].s)
				{
					if (a[j].b < a[j + 1].b)
					{
						x = a[j]; a[j] = a[j + 1]; a[j + 1] = x;
					}
					else if (a[j].b == a[j + 1].b)
					{
						if (a[j].name > a[j + 1].name)
						{
							x = a[j]; a[j] = a[j + 1]; a[j + 1] = x;
						}
						a[j].flag = 1, a[j + 1].flag = 1;
					}
					else
						break;
				}
				else
					break;
			}
			else
				break;
		}
	}
	


	in.close();
	out.close();
	return 0;
}