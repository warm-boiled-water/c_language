

#include<stdio.h>
#include"game.h"
void menu()
{
	printf("                                          ************************************\n");
	printf("                                          ****��ʼ��Ϸ�밴1||�˳���Ϸ�밴0****\n");
	printf("                                          ************************************\n");
}
void level()
{
	
	char show[H2][L2];
	int mine[H2][L2] = { 0 };
	set_mine1(mine);
	set_show1(show);
	begin1(show,mine);
}
//void leve2()
//{
//
//	char show[H4][L4];
//	int mine[H4][L4] = { 0 };
//	set_mine2(mine);
//	set_show2(show);
//	begin2(show, mine);
//}
//void leve3()
//{
//
//	char show[H6][L6];
//	int mine[H6][L6] = { 0 };
//	set_mine3(mine);
//	set_show3(show);
//	begin3(show, mine);
//}

int main()
{
	menu();
	/*int a = 0;*/
	int n = 0;
	printf("                                                         ��ѡ��");
	scanf_s("%d", &n);
	system("cls");
	/*printf("��ѡ���Ѷȣ�");
	scanf_s("%d", &a);*/
	/*if(a==1)*/
	while (n)
	{

		level();
		menu();
		printf("                                                     ��ѡ��");
		scanf_s("%d", &n);
		system("cls");
	}
	return 0;
}
	/*if(a==2)
		while (n)
		{

			leve2();
			menu();
			printf("                                                     ��ѡ��");
			scanf_s("%d", &n);
			system("cls");
		}
	if(a==3)
		while (n)
		{

			level();
			menu();
			printf("                                                     ��ѡ��");
			scanf_s("%d", &n);
			system("cls");
		}
	return 0;
}*/







































