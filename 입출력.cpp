#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream in;
	in.open("input.txt");

	ofstream out;
	out.open("output.txt");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	in.close();
	out.close();
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");

	fclose(in);
	fclose(out);
}