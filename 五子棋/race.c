#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include"race.h"
void menu()
{
	printf("\t\t\t\t\t  **********************************\n");
	printf("\t\t\t\t\t  *******开始请按1||退出请按2*******\n");
	printf("\t\t\t\t\t  **********************************\n");
}
void race()
{
	char show[H][L];
	initialize_show(show);
	show_show(show);
	begin(show);
}
int select()
{
	int n = 0;
	printf("\t\t\t\t\t\t\t请选择：");
	scanf("%d", &n);
	while (n != 1 && n != 2)
	{
		printf("\t\t\t\t\t  选择错误，请重新选择：");
		scanf("%d", &n);
	}
	return n;
}
int main()
{
	int n = 0;
	menu();
	n = select();
	system("cls");
	while (n==1)
	{
		race();
		menu();
		n = select();
		system("cls");

	}
	return 0;
}