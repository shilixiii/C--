#define _CRT_SECURE_NO_WARNINGS//vs2022如果运行C语言scanf函数需要这段话，我是看网上教程看的
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define MAX 100
#define NUM 10//炸弹个数 
#define BOOM 99
int n = 10, m = 10;//n为高，m为宽
int a[MAX][MAX] = { 0 };//标记数字
int b[MAX][MAX] = { 0 };//标记点击
void print()//创建棋盘
{
	system("cls");
	for (int i = 0; i <= n; i++)
	{
		printf("%2d ", i);
		for (int j = 1; j <= m; j++)
		{
			if (i == 0) printf("%2d ", j);
			else if (b[i][j] == 0)
				printf(" - ");
			else
				printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}
void createboom()//创建炸弹
{
	srand((unsigned int)time(NULL));
	int x, y;
	for (int i = 0; i < NUM; i++)
	{
		x = rand() % 11 + 1;
		y = rand() % 11 + 1;
		if (a[y][x] == BOOM) i--;
		else a[y][x] = BOOM;
	}
}
void createnum()//生成数字加一
{
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (a[i][j] == BOOM)
			{
				if (a[i - 1][j - 1] != BOOM) a[i - 1][j - 1]++;
				if (a[i - 1][j] != BOOM) a[i - 1][j]++;
				if (a[i - 1][j + 1] != BOOM) a[i - 1][j + 1]++;
				if (a[i][j - 1] != BOOM) a[i][j - 1]++;
				if (a[i][j + 1] != BOOM) a[i][j + 1]++;
				if (a[i + 1][j - 1] != BOOM) a[i + 1][j - 1]++;
				if (a[i + 1][j] != BOOM) a[i + 1][j]++;
				if (a[i + 1][j + 1] != BOOM) a[i + 1][j + 1]++;
			}
		}
	}
}

int main()
{
	createboom();
	createnum();
	int x, y;
	int times = 0, flag = 0;
	while (1)
	{
		print();
		printf("输入要检查的坐标:");
		scanf("%d %d", &x, &y);
		if (a[y][x] == BOOM)
		{
			printf("你被炸死了！\n");
			break;
		}
		else
		{
			b[y][x] = 1;
			times++;
		}
		if (times == 90)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		printf("恭喜你获胜！\n");
	return 1;