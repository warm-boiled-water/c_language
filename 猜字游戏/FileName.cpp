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
		printf("                                             ��ѡ��1��2:");
		scanf_s("%d", &n);
		if (n == 1) break;
		if (n == 2) game();
	}
	printf("\n");
	printf("                                                         ��Ϸ����");
	return 0;
}
void menu()
{
	printf("                                             *******************************\n");
	printf("                                             *�˳���Ϸ�밴1|||��ʼ��Ϸ�밴2*\n");
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
		printf("��������Ҫ�µ���(1-100):");
	    scanf_s("%d", &m);
		if (m > rn)
		{
			a--; printf("�´���(����%d����)\n",a); printf("\n"); ;
		}
		if (m < rn)
		{
			a--; printf("��С��(����%d����)\n", a); printf("\n"); ;
		}
		if (m == rn)
		{
			printf("��ϲ��,�¶���,����%d\n", rn);
			break;
		}
		if (a == 0) printf("���ź�,����������,����%d\n",rn);
	}
}


