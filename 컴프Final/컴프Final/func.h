#define ernum 1000000 //연산자 구분용
typedef struct symbol {
	//      char token[3];
	int val;
	int token;
}symbol;
int pow(int a, int k);
int OPnum(char op);
int process(int* result, int rsptr);
void calc(symbol* table);
void getsymbol(symbol* table);
int findsym(int a, symbol* table);