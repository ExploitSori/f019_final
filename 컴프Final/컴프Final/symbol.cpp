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
	while (fgets(strtmp, 10, symbolFile) != NULL) {
		char* tmp = strchr(strtmp, 0x20) + 1;
		a.token = ascii(strtmp);
		a.val = atoi(tmp);
		table[cnt] = a;
		cnt++;
	}
	fclose(symbolFile);
}