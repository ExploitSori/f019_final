#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"func.h"
int ascii(char* s) {
	int cnt = 0;
	while (1) {
		if (s[cnt] == ' ') {
			break;
		}
		else cnt++;
	}
	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += s[i];
	}
	return sum;
}
int findsym(int a, symbol* table)
{
	for (int i = 0; i < 15; i++)
	{
		if (table[i].token == a)
		{
			return table[i].val;
		}
	}
	return 0;
}
char* findtxt(int a, symbol* table)
{
	for (int i = 0; i < 15; i++)
	{
		if (table[i].token == a)
		{
			return table[i].txt;
		}
	}
	return 0;
}
void txt(char* strtmp, symbol* a)
{
	char temp[10];
	int i = 0;
	while (1)
	{
		if (strtmp[i] == ' ') break;
		else
		{
			temp[i] = strtmp[i];
		}
		i++;
	}
	temp[i] = '\0';
	strcpy(a->txt,temp);
}
void getsymbol(symbol* table) {
	FILE* symbolFile = fopen("./inputSymbols.txt", "r");
	char strtmp[10] = { 0 };
	int cnt = 0;

	symbol a;
	a.token = 9999;
	if (symbolFile == NULL) {
		printf("NULLLLL");
		return;
	}
	printf("*** Symbols\n--------------------\n");
	while (fgets(strtmp, 10, symbolFile) != NULL) {
		char* tmp = strchr(strtmp, 0x20) + 1;
		a.token = ascii(strtmp);
		a.val = atoi(tmp);
		txt(strtmp, &a);
		table[cnt] = a;
		printf("   %4s   %5d\n", a.txt, a.val);
		cnt++;
	}
	printf("\n");
	printf("--------------------\n");
	fclose(symbolFile);
}