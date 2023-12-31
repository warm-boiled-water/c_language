#pragma once
#define H 15
#define L 15
#include<windows.h>
void initialize_show(char show[][L])
{
	int i = 0, j = 0;
for(i=0;i<15;i++)
	for (j = 0; j < 15; j++)
	{
		show[i][j] = '*';
	}
}
void show_show(char show[][L])
{
	int i = 0, j = 0;
	printf("\t\t\t\t ");
	for (i = 1; i <= 9; i++)
		printf("%d   ", i);
	for (i = 10; i <= L; i++)
		printf("%d  ", i);
	printf("\n");
	for (i = 0; i < 9; i++)
	{
		printf("\t\t\t       ");
		printf("%d ", i + 1);
		for (j = 0; j < 15; j++)
		{
			printf("%c   ", show[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	for (i = 10; i < L; i++)
	{
		printf("\t\t\t      ");
		printf("%d ", i + 1);
		for (j = 0; j < 15; j++)
		{
			printf("%c   ", show[i][j]);
		}
		printf("\n");
		printf("\n");
	}
}
int examine(char show[][L],char g)
{
	int k = 0;
	int i=0, j=0;
int m = 0, n = 0;
for(m=0;m<15;m++)
	for (n = 0; n < 15; n++)
	{
		if (show[m][n] == g)
		{
			for (i = m, j = n,k=0; i <= m + 4&&j <= n + 4&&i>=0&&j>=0&&i<H&&j<L; i++, j++)
				if (show[i][j] == g)
					k++;
			if (k == 5)
				goto final;
			for (i = m, j = n ,k = 0; i >= m-4 &&j >= n-4 && i >= 0 && j >= 0 && i < H && j < L; i--, j--)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0; j <= n + 4 && i >= 0 && j >= 0 && i < H && j < L;j++)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0;j >= n-4 && i >= 0 && j >= 0 && i < H && j < L;j--)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0; i <= m + 4 && i >= 0 && j >= 0 && i < H && j < L; i++)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0; i >= m-4 && i >= 0 && j >= 0 && i < H && j < L; i--)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0; i >= m - 4&&j <= n + 4 && i >= 0 && j >= 0 && i < H && j < L; i--, j++)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
			for (i = m, j = n, k = 0; i <= m+4&&j >= n-4 && i >= 0 && j >= 0 && i < H && j < L; i++, j--)
				if (show[i][j] == g)
					k++;
			if (k == 5)
			goto final;
        }
    }
final:
if (k == 5)
return 1;
else
return 0;
}
void begin(char show[][L])
{
	int i = 0, j = 0;	
	while (1)
	{
		printf("X方请下棋：");
		scanf("%d%d", &i, &j);
		show[i - 1][j - 1] = 'X';
		if (examine(show, 'X'))
		{
			system("cls");
			show_show(show);
			printf("\t\t\t\t\t\t     恭喜X方胜利!!!\n");			
			break;
		}
		system("cls");
		show_show(show);
		printf("0方请下棋：");
		scanf("%d%d", &i, &j);
		show[i - 1][j - 1] = '0';
		if (examine(show, '0'))
		{
			system("cls");
			show_show(show);
			printf("\t\t\t\t\t\t     恭喜0方胜利!!!\n");
			break;
		}
		system("cls");
		show_show(show);
	}
}
