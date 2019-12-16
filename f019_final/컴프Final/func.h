#define ernum 2000000000 //연산자 구분용
typedef struct symbol {
	char txt[10] = { 0 };
	int val;
	int token;
}symbol;
int pow(int a, int k);
int OPnum(char op);
int process(int* result, int rsptr);
void calc(symbol* table);
void getsymbol(symbol* table);
int findsym(int a, symbol* table);
char* findtxt(int a, symbol* table);
void prpostfix(int* result, int rsptr);
void txt(char* strtmp, symbol* a);