#include<stdio.h>
#include "func.h"
#include <string.h>

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
	else if (op == ';') return 7;
	else return -1;
}

void prpostfix(int* result, int rsptr)
{
	printf("-----------------------------\n* Postfix expression:\n");
	for (int i = 0; i < rsptr; i++)
	{
		if (result[i] > ernum) printf("[%c] ", result[i] - ernum);
		else printf("[%d] ", result[i]);
	}
	printf("\n");
}

int process(int* result, int rsptr){


	prpostfix(result, rsptr);
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
	printf("* Evaluated => %d\n----------------------------------------\n", cal[0]);
	return 0;
}