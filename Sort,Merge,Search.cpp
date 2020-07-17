#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

char filename[10000][50];
void Command(char cmd[], char file[], int *size);
void Make(char file[], int *size);
void Delete(char file[], int *size);
void Search(char file[], int size);
void Sort(int size);

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	
	int fn = 0, cn = 0;
	int i;
	char command[10];
	char file[50];

	scanf("%d", &fn);
	scanf("%d", &cn);


	for (i = 0; i < fn; i++)
		scanf("%s", filename[i]);
	
	for (i = 0; i < cn; i++)
	{
		scanf("%s %s", command, file);
		Command(command, file, &fn);
	}


	return 0;
}

void Command(char cmd[], char file[], int *size)
{
	if (strcmp(cmd, "Make") == 0)
		Make(file, size);
	else if (strcmp(cmd, "Delete") == 0)
		Delete(file, size);
	else if (strcmp(cmd, "Search") == 0)
		Search(file, *size);
}

void Make(char file[], int *size)
{
	strcpy(filename[*size], file);
	*size = *size + 1;
	Sort(*size);
	printf("OK\n");
}

void Delete(char file[], int *size)
{
	int i;
	for (i = 0; i < *size; i++)
	{
		if (strcmp(filename[i], file) == 0)
			break;
	}

	if (i < *size)
	{
		for (int j = i + 1; j < *size; j++)
			strcpy(filename[j - 1] ,filename[j]);
		*size = *size - 1;
		printf("OK\n");
	}
	else
	{
		printf("Not found\n");
	}

	Sort(*size);
}

void Search(char file[], int size)
{
	printf("Search %s\n", file);

	int i, j;

	int length = strlen(file);
	char srh[50];
	int sn = 0;
	int flag = 0;
	int fnl;
	int flag2 = 0;
	int r = 0;
	

	Sort(size);

	if (file[0] == '*')
	{
		flag = 1;
		for (i = 1; i < length; i++)
			srh[i - 1] = file[i];
	}
	else
		strcpy(srh, file);

	if (flag == 1)
	{
		int t = 0;
		for (i = 0; i < size; i++)
		{
			fnl = strlen(filename[i]);
			for (j = 0; j < fnl; j++)
			{
				if (flag2 == 0)
				{
					if (filename[i][j] == srh[t])
					{
						t++;
						flag2 = 1;

					}
				}
				else if (flag2 == 1)
				{
					if (filename[i][j] == srh[t])
						t++;
					else
					{
						flag2 = 0;
						break;
					}
				}
			}
			if (flag2 == 1)
			{
				printf("%s\n", filename[i]);
				r = 1;
			}

			flag2 = 0;
			t = 0;
		}

		if (r == 0)
			printf("Not found\n");
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			fnl = strlen(filename[i]);
			if (length == fnl)
			{
				for (j = 0; j < length; j++)
				{
					if (filename[i][j] != file[j] && file[j] != '?')
						break;
				}

				if (j == length)
					printf("%s", filename[i]);
				else
					printf("Not found\n");
			}
		}
	}
}

void Sort(int size)
{
	int i, j;
	char temp[50];

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(filename[i], filename[j]) == 1)
			{
				strcpy(temp, filename[i]);
				strcpy(filename[i], filename[j]);
				strcpy(filename[j], temp);
			}
		}
	}
}
