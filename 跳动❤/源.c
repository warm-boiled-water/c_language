#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<math.h>
void print1()
{
	double x = 0, y = 0, a = 0;
	for (y = 1.5; y >= -1; y -= 0.1)
	{
		for (x = -3; x <= 1.5; x += 0.05)
		{
			a = pow(x, 2) + pow(y, 2) - 1;
			printf(pow(a, 3) - pow(x, 2) * pow(y, 3) <= 0 ? "*" : " ");
		}
		printf("\n");

	}
	system("color 04");
}
void print2()
{
	double x = 0, y = 0, a = 0;
	for (y = 1.5; y >= -1; y -= 0.125)
	{
		for (x = -3.7; x <= 1.5; x += 0.0625)
		{
			a = pow(x, 2) + pow(y, 2) - 1;
			printf(pow(a, 3) - pow(x, 2) * pow(y, 3) <= 0 ? "*" : " ");
		}
		printf("\n");

	}
	system("color 04");
}
void print3()
{
	double x = 0, y = 0, a = 0;
	for (y = 1.5; y >= -1; y -= 0.15)
	{
		for (x = -4.5; x <= 1.5; x += 0.075)
		{
			a = pow(x, 2) + pow(y, 2) - 1;
			printf(pow(a, 3) - pow(x, 2) * pow(y, 3) <= 0 ? "*" : " ");
		}
		printf("\n");

	}
	system("color 04");
}
int main()
{
	while (1)
	{
		print1();
		Sleep(150);
		system("cls");
		print2();
		system("cls");
		Sleep(150);
		print3();
		system("cls");
		Sleep(150);
	}
	return 0;
}
