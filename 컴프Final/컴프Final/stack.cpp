#include "stack.h"
bool is_empty(Stack_Data* stack)
{
	if (stack->size == 0) return true;
	else return false;
}
void push(Stack_Data* stack, int a)
{
	stack->Stack[stack->size] = a;
	stack->size++;
}
void pop(Stack_Data* stack)
{
	stack->Stack[(stack->size) - 1] = -1;
	stack->size--;
}
int top(Stack_Data* stack)
{
	return stack->Stack[stack->size - 1];
}
int size(Stack_Data* stack)
{
	return stack->size;
}