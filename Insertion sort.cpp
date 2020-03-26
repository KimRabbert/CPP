#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct A
{
	string name = "";
	int g = 0, s = 0, b = 0;
	int flag = 0;
};

string itos(int ch)
{
	string r = "";
	char number;

	if (ch < 10)
	{
		number = ch + 48;
		r += number;
		
		return r;
	}
	else if (ch >= 10 && ch < 100)
	{
		number = (ch / 10) + 48;
		r += number;
		number = (ch % 10) + 48;
		r += number;

		return r;
	}
	else
	{
		number = (ch / 100) + 48;
		r += number;
		ch = ch % 100;
		number = (ch / 10) + 48;
		r += number;
		number = (ch % 10) + 48;

		return r;
	}
}

int main()
{
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");

	A a[200];
	A x;
	int n, i, j, i2;
	string rank[200] = { "", };
	string num;

	in >> n;

	for (i = 0; i < n; i++)
	{
		a[i].flag = i + 1;
		i2 = i + 1;
		num = itos(i2);

		if (i2 % 10 == 1)
		{
			if (i2 % 100 == 11)
				rank[i] += num + "th";
			else
				rank[i] += num + "st";
		}
		else if (i2 % 10 == 2)
		{
			if (i2 % 100 == 12)
				rank[i] += num + "th";
			else
				rank[i] += num + "nd";
		}
		else if (i2 % 10 == 3)
		{
			if (i2 % 100 == 13)
				rank[i] += num + "th";
			else
				rank[i] += num + "rd";
		}
		else
			rank[i] += num + "th";
			
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
						a[j + 1].flag = a[j].flag;
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
	
	for (i = 0; i < n; i++)
	{
		if (a[i].flag == a[i + 1].flag)
		{
			rank[i + 1] = rank[i];
			out << rank[i] << " " << a[i].name << " " << a[i].g << " " << a[i].s << " " << a[i].b << "\n";
		}
		else
			out << rank[i] << " " << a[i].name << " " << a[i].g << " " << a[i].s << " " << a[i].b << "\n";
	}

	in.close();
	out.close();
	return 0;
}