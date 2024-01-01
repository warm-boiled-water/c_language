#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define H1 9
#define L1 9
#define H2 2+H1
#define L2 2+L1
//#define H3 12
//#define L3 12
//#define H4 2+H3
//#define L4 2+L3
//#define H5 36
//#define L5 36
//#define H6 2+H5
//#define L6 2+L5
  
                                                                 //等级一
void set_mine1(int mine[][L2])
{
	srand((unsigned int)time(NULL));
	int i;
	for (i = 1; i <=10;)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (mine[x][y]!=1 )
		{
			mine[x][y] = 1;
			i++;
        }
	}
	
}
void conclude(int mine[][L2], char show[][L2], int a, int b)
{
	int n = 0, m = 0;
	int k = 0;

	for (n = a - 1; n <= a + 1; n++)
		for (m = b - 1; m <= b + 1; m++)
		{
			if (mine[n][m] == 1) k++;
		}
	if (k != 0)
	{
		mine[a][b] = 9;
		show[a][b] = 48 + k%9;
	}
	if (k == 0)
		show[a][b] = ' ';
}
void show_more(int mine[][L2], char show[][L2], int x, int y)
{
	int i = 0, j = 0;
	int n = 0, m = 0;
	int k = 0;
	mine[x][y] = 9;
	for (n = x - 1; n <= x + 1; n++)
		for (m = y - 1; m <= y + 1; m++)
		{
			show[n][m] = ' ';
		}
	for (n = x - 1; n <= x + 1; n++)
		for (m = y - 1; m <= y + 1; m++)
		{
			if ((n == 0 || n == 10 || m == 0 || m == 10) || n == x && m == y)
				continue;
			k = mine[n][m - 1] + mine[n][m + 1] + mine[n - 1][m - 1] + mine[n - 1][m] + mine[n - 1][m + 1] +
				mine[n + 1][m - 1] + mine[n + 1][m] + mine[n + 1][m + 1];
			if (k % 9 == 0 && mine[n][m] != 9)
				show_more(mine, show, n, m);
			else
				conclude(mine, show, n, m);

		}
}	
void again_show(char show[][L2])
{
	int i = 0, j = 0;
	printf("\t\t\t\t\t\t  ");
	printf("0 ");
	for (i = 1; i <= L1; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= H1; i++)
	{
		printf("\t\t\t\t\t\t  ");
		printf("%d ", i);
		for (j = 1; j <= L1; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}
void set_show1(char show[][L2])
{
	int i, j;
	printf("\t\t\t\t\t\t  ");
	printf("0 ");
	for (i = 1; i <= L1; i++)
	{		
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= H1; i++)
	{
		printf("\t\t\t\t\t\t  ");
		printf("%d ", i);		
		for (j = 1; j <= L1; j++)
		{
			show[i][j] = '*';
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}
void print_mine1(int mine[][L2])
{
	int i, j;
	for (i = 1; i <= H1; i++)
	{
		printf("\t\t\t\t\t\t  ");
		for (j = 1; j <= L1; j++)
		{
			printf("%d ", mine[i][j]);
		}
		printf("\n");
	}
}
void begin1(char show[][L2],int mine[][L2])
{
	int x=0, y=0;
	int n=0,m,i=0,j=0;
	int k = 0;
	while (1)
	{
		printf("请输入你要排查的坐标：");
		scanf_s("%d%d", &x, &y);
		m = mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
			mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
		if (mine[x][y] != 1 && m%9 == 0)
		{
			show[x][y] = ' ';
			show_more(mine, show, x, y);
			system("cls");
			again_show(show);
		}
		n = 0, k = 0;
		for (i = 1; i <= H1; i++)
			for (j = 1; j <= L1; j++)
			{
				if (show[i][j] == '*')
					n++;
				if (show[i][j] == '!' && mine[i][j] == 1)
					k++;
			}
		if (n == 10&&k==0 || k == 10 || n + k == 10)
		{
			system("cls");
			printf("\t\t\t\t\t\t  ");
			printf("恭喜你，排雷成功\n");
			printf("\t\t\t\t\t\t  ");
			printf("雷区分布如下(1是雷，9是你排查过的坐标)：\n");
			print_mine1(mine);
			break;
		}
		if (mine[x][y] == 1)
		{
			int k = 0;
			system("cls");
			printf("\t\t\t\t\t\t  ");
			printf("很遗憾，你被炸死了\n");
			Sleep(3000);
			system("cls");
			printf("\t\t\t\t\t\t  ");
			printf("是否查看雷区分布？(是请按1，否请按2)\n");
			printf("\t\t\t\t\t\t  ");
			printf("请选择：");
			scanf_s("%d", &k);
			system("cls");
			if (k == 1)
			{
				printf("\t\t\t\t\t\t  ");
				printf("雷区分布如下(1是雷，9是你排查过的坐标)：\n");
				print_mine1(mine);
			}
			break;
		}
		if (mine[x][y] != 1 && m%9 != 0)
		{
			show[x][y] = m%9 + 48;
			system("cls");
			again_show(show);
		}
		int b;
		int a = 0;
		printf("\t\t\t\t\t\t  ");
		printf("是否需要标记地雷？(需要请按1，不需要请按2)\n");
		printf("\t\t\t\t\t\t  ");
		printf("请选择：");
		scanf_s("%d", &b);
		while (b != 1&&b!=2)
		{
			printf("\t\t\t\t\t\t  ");
			printf("输入错误，请重新选择：");
			scanf_s("%d", &b);
		}
		
		system("cls");
		if (b == 1)
		{
			int x = 0, y = 0;
			again_show(show);
			printf("\t\t\t\t\t\t  ");
			printf("请输入需要标记的坐标：");
			scanf_s("%d%d", &x, &y);
			show[x][y] = '!';
			system("cls");
			again_show(show);
			n = 0; k = 0;
			for (i = 1; i <= H1; i++)
				for (j = 1; j <= L1; j++)
				{
					if (show[i][j] == '*')
						n++;
					if (show[i][j] == '!' && mine[i][j] == 1)
						k++;
				}
			if (n == 10&&k==0 || k == 10 || n + k == 10)
			{
				system("cls");
				printf("\t\t\t\t\t\t  ");
				printf("恭喜你，排雷成功\n");
				printf("\t\t\t\t\t\t  ");
				printf("雷区分布如下(1是雷，9是你排查过的坐标)：\n");
				print_mine1(mine);
				break;
			}
			while (1)
			{
				printf("\t\t\t\t\t\t  ");
				printf("是否需要再次标记地雷？(需要请按1，不需要请按2)\n");
				printf("\t\t\t\t\t\t  ");
				printf("请选择：");
				scanf_s("%d", &b);
				while (b != 1 && b != 2)
				{
					printf("\t\t\t\t\t\t  ");
					printf("输入错误，请重新选择：");
					scanf_s("%d", &b);
				}
				system("cls");
				if (b == 1)
				{
					again_show(show);
					printf("\t\t\t\t\t\t  ");
					printf("请输入需要标记的坐标：");
					scanf_s("%d%d", &x, &y);
					show[x][y] = '!';
					system("cls");
					again_show(show);
				}
				else
				{
					again_show(show);
					break;
				}
			}
		}
		else
		{
			again_show(show);
		}
		n = 0; k = 0;
               for(i=1;i<=H1;i++)
               for (j = 1; j <= L1; j++)
               {
	           if (show[i][j] == '*')
		        n++;
			   if (show[i][j] == '!' && mine[i][j] == 1)
				   k++;
               }
		if (n==10&&k==0||k==10||n+k==10)
		{
			system("cls");
			printf("\t\t\t\t\t\t  ");		
			printf("恭喜你，排雷成功\n");
			printf("\t\t\t\t\t\t  ");
			printf("雷区分布如下(1是雷，9是你排查过的坐标)：\n");
			print_mine1(mine);
				break;
		}			
	}
}







                                                       //等级二
//void set_mine2(int mine[][L4])
//{
//	srand((unsigned int)time(NULL));
//	int i;
//	for (i = 1; i <= 40; i++)
//	{
//		int x = rand() % (( L4 -1 )-1+1) + 1;
//		int y = rand() % ((H4 - 1) - 1 + 1) + 1;
//		if (mine[x][y] != 1)
//		{
//			mine[x][y] = 1;
//		}
//	}
//
//}
//void set_show2(char show[][L4])
//{
//	int i, j;
//	printf("\t\t\t  ");
//	printf("0   ");
//	for (i = 1; i <= 9; i++)
//	{
//		printf("%d   ", i);
//	}
//	for (i = 10; i <= L3; i++)
//	{
//		printf("%d  ", i);
//	}
//	printf("\n");
//	printf("\n");
//
//	for (i = 1; i <= 9; i++)
//	{
//		printf("\t\t\t  ");
//		printf("%d   ", i);
//		for (j = 1; j <= L3; j++)
//		{
//			show[i][j] = '*';
//			printf("%c   ", show[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//	}
//	for (i = 10; i <= H3; i++)
//	{
//		printf("\t\t\t  ");
//		printf("%d  ", i);
//		for (j = 1; j <= L3; j++)
//		{
//			show[i][j] = '*';
//			printf("%c   ", show[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//	}
//
//}
//void print_mine2(int mine[][L4])
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		printf("\t\t\t  ");
//		for (j = 1; j <= L3; j++)
//		{
//			printf("%d   ", mine[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//	}
//	for (i = 10; i <= H3; i++)
//	{
//		printf("\t\t\t  ");
//		for (j = 1; j <= L3; j++)
//		{
//			printf("%d   ", mine[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//	}
//}
//void begin2(char show[][L4], int mine[][L4])
//{   int x, y;
//printf("请输入你要排查的坐标：");
//		scanf_s("%d%d", &x, &y);
//	int n = 0, m, i, j;
//	
//	m = mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y - 1] + mine[x - 1][y] + mine[x + 1][y + 1] +
//		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1];
//	while (1)
//	{
//		
//		if (mine[x][y] != 1 && m== 0)
//		{
//			show[x][y] = ' ';
//			n++;
//			system("cls");
//			printf("\t\t\t  ");
//			printf("0   ");
//			for (i = 1; i <= 9; i++)
//			{
//				printf("%d   ", i);
//			}
//			for (i = 10; i <= L3; i++)
//			{
//				printf("%d  ", i);
//			}
//			printf("\n");
//			printf("\n");
//
//			for (i = 1; i <= 9; i++)
//			{
//				printf("\t\t\t  ");
//				printf("%d   ", i);
//				for (j = 1; j <= L3; j++)
//				{
//					printf("%c   ", show[i][j]);
//				}
//				printf("\n");
//				printf("\n");
//			}
//			for (i = 10; i <= H3; i++)
//			{
//				printf("\t\t\t  ");
//				printf("%d  ", i);
//				for (j = 1; j <= L3; j++)
//				{					
//					printf("%c   ", show[i][j]);
//				}
//				printf("\n");
//				printf("\n");
//			}			
//		}
//
//		else if (mine[x][y] == 1)
//		{
//			system("cls");
//			printf("\t\t\t  ");
//			printf("很遗憾，你被炸死了\n");
//			printf("\t\t\t  ");
//			printf("雷区分布如下：\n");
//			print_mine2(mine);
//			/*Sleep(5000);*/
//			/*system("cls");*/
//			break;
//		}
//		else
//		{
//			show[x][y] = m + 48;
//			n++;
//			system("cls");
//			printf("\t\t\t  ");
//			printf("0   ");
//			for (i = 1; i <= 9; i++)
//			{
//				printf("%d   ", i);
//			}
//			for (i = 10; i <= L3; i++)
//			{
//				printf("%d  ", i);
//			}
//			printf("\n");
//			printf("\n");
//
//			for (i = 1; i <= 9; i++)
//			{
//				printf("\t\t\t  ");
//				printf("%d   ", i);
//				for (j = 1; j <= L3; j++)
//				{					
//					printf("%c   ", show[i][j]);
//				}
//				printf("\n");
//				printf("\n");
//			}
//			for (i = 10; i <= H3; i++)
//			{
//				printf("\t\t\t  ");
//				printf("%d  ", i);
//				for (j = 1; j <= L3; j++)
//				{
//					printf("%c   ", show[i][j]);
//				}
//				printf("\n");
//				printf("\n");
//			}
//
//		}
//		if (n == H3 * L3) break;
//	}
//	if (n == H3 * L3)
//	{
//		system("cls");
//		printf("\t\t\t  ");
//		printf("恭喜你，排雷成功\n");
//		printf("\t\t\t  ");
//		print_mine2(mine);
//		Sleep(5000);
//	}
//}





                                                     //等级三