#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");

	return 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}