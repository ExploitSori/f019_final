#define MAX_SIZE 100
typedef struct Stack_Data {
	int size = 0;
	int Stack[MAX_SIZE];
}Stack_Data;
bool is_empty(Stack_Data* stack);
void push(Stack_Data* stack, int a);
void pop(Stack_Data* stack);
int top(Stack_Data* stack);
int size(Stack_Data* stack);