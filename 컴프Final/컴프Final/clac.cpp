#include<stdio.h>
#include "func.h"
void copy(int* dst, int * sr, int rsptr)
{
	for (int i = 0; i < rsptr; i++)
	{
		dst[i] = sr[i];
	}
}
void sort(int* cal, int ptr, int rsptr)
{
	for (int i = ptr; i < rsptr; i++)
	{
		cal[i - 2] = cal[i];
	}
	cal[rsptr - 1] = 0;
	cal[rsptr - 2] = 0;
}
int operate(int a, int b, int op)
{
	if (op == '+' + ernum)
	{
		return (a) + (b);
	}
	else if (op == '-' + ernum)
	{
		return (a) - (b);
	}
	else if (op == '*' + ernum)
	{
		return (a) * (b);
	}
	else if (op == '/' + ernum)
	{
		return (a) / (b);
	}
}
int pow(int a, int k)
{
	for (int i = 0; i < k; i++)
	{
		a *= 10;
	}
	return a;
}
int OPnum(char op) // 우선순위 계산
{
	if (op == '(') return 0;
	else if (op == ')') return 1;
	else if (op == '+') return 2;
	else if (op == '-') return 3;
	else if (op == '*') return 4;
	else if (op == '/') return 5;
	else return 0;
}
int process(int* result, int rsptr)
{
	int cal[1000];
	copy(cal, result, rsptr);
	for (int i = 0; i < rsptr; i++)
	{
		if (rsptr == 1) break;
		if (cal[i] == '+' + ernum || cal[i] == '-' + ernum || cal[i] == '*' + ernum || cal[i] == '/' + ernum)
		{
			int temp = operate(cal[i - 2], cal[i - 1], cal[i]);
			cal[i - 2] = temp;
			if (rsptr - 2 != 1) sort(cal, i + 1, rsptr);
			i -= 2, rsptr -= 2;
		}
	}
	printf("정답 : %d\n", cal[0]);
	return 0;
}