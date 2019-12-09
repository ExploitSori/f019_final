#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"func.h"

int snum; // ��ū ��ȯ�� ���ڿ� � ���� �˷���
int rsptr = 0; // ��������� ������ int������ �̷��� ���� int�迭�� ����� ������ ������ ������ Ȯ�ο�
int symtoi(char* a, int i)
{
	int k = 0;
	int temp = 0;
	while ((a[i + k] >= 'A' && a[i + k] <= 'Z'))
	{
		temp += a[i + k];
		k++;
	}
	snum = k;
	return temp;
}
int itoi(char* a, int i)
{
	int k = 0;
	int temp = 0;
	while ((a[i + k] >= '0' && a[i + k] <= '9'))
	{
		k++;
	}
	for (int j = 0; j < k; j++)
	{
		temp += pow((a[i + j] - '0'), k - j - 1);
	}
	snum = k;
	return temp;
}
void calc()
{
	FILE* infix = fopen("./inputInfix.txt", "r");
	while (1)
	{
		rsptr = 0;
		char a[1000];
		if (fgets(a, 100, infix) == NULL) break;
		int result[100] = { 0, };
		Stack_Data str;
		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] >= 'A' && a[i] <= 'Z')
			{
				int temp = symtoi(a, i);
				temp = findsym(temp, &table);
				result[rsptr] = temp;
				rsptr++;
				i = i + snum - 1;
			}
			else if (a[i] >= '0' && a[i] <= '9')
			{
				int temp = itoi(a, i);
				result[rsptr] = temp;
				rsptr++;
				i = i + snum - 1;
			}
			else if (a[i] == '(') push(&str, a[i]);
			else if (a[i] == ')')
			{
				{
					while (top(&str) != '(') {
						result[rsptr] += top(&str);
						rsptr++;
						pop(&str);
					}
					pop(&str);
				}
			}
			else if (a[i] == '+' || a[i] == '-')
			{
				while (!is_empty(&str) && top(&str) != '(') {
					result[rsptr] += top(&str);
					rsptr++;
					pop(&str);
				}
				push(&str, a[i] + ernum);
			}
			else if (a[i] == '*' || a[i] == '/')
			{
				while (!is_empty(&str) && (top(&str) == '*' || top(&str) == '/')) {

					result[rsptr] += top(&str);
					rsptr++;
					pop(&str);
				}
				push(&str, a[i] + ernum);
			}
			else continue;
		}
		while (!is_empty(&str))
		{
			result[rsptr] = top(&str);
			pop(&str);
			rsptr++;
		}
		for (int i = 0; i < rsptr; i++)
		{
			printf("%d ", result[i]);
		}
		printf("\n");
	}
	fclose(infix);
	int process(result, rsptr);
}