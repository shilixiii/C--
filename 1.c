#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	int a;
//	scanf_s("%d", &a);
//	printf("输出的数字为%d\n", a);
//	return 0;
//}

//int main()
//{
//	int a, b, c;
//	scanf("%d %d", &a, &b);
//	//printf("%d,%d\n", a, b);
//	/*if (a >= b)
//		c = a;
//	else
//		c = b;*/
//	c = a >= b ? a : b;
//	printf("最大值=%d\n", c);
//	return 0;
//}

int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}


int main()
{
	int Max(int x, int y);
	int a, b;
	scanf("%d %d", &a, &b);
	int c = Max(a, b);
	printf("%d\n", c);
	return 0;
}