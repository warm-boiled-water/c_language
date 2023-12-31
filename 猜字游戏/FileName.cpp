#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	while (1)
	{
		int n;
		void game();
		void menu();
		menu();
		printf("                                             请选择1或2:");
		scanf_s("%d", &n);
		if (n == 1) break;
		if (n == 2) game();
	}
	printf("\n");
	printf("                                                         游戏结束");
	return 0;
}
void menu()
{
	printf("                                             *******************************\n");
	printf("                                             *退出游戏请按1|||开始游戏请按2*\n");
	printf("                                             *******************************\n");
	printf("\n");
}
void game()
{
	int rn, m,a=10;
	
	srand((unsigned int)time(NULL));
	rn = rand()%(100-1+1)+1;
	while (a)
	{
		printf("请输入你要猜的数(1-100):");
	    scanf_s("%d", &m);
		if (m > rn)
		{
			a--; printf("猜大啦(还有%d机会)\n",a); printf("\n"); ;
		}
		if (m < rn)
		{
			a--; printf("猜小啦(还有%d机会)\n", a); printf("\n"); ;
		}
		if (m == rn)
		{
			printf("恭喜你,猜对啦,答案是%d\n", rn);
			break;
		}
		if (a == 0) printf("很遗憾,机会已用完,答案是%d\n",rn);
	}
}


