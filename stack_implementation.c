/*******************This code is appended from*******************************
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/ 
**************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

// struct to represent the stack
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

// function to create the stack of the given capacity
// initializes stack size 0

struct Stack* createStack(unsigned capacity)
{
	// malloc allocates the struct size in bytes and 
	// returns a pointer to it
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// full when top is equal to last index
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// function to add item to stack. Increases top by 1
void push(struct Stack* stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed to the stack.\n", item);
}

// function to remove item from the stack
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

// function to peek at stack
int peek(struct Stack* stack)
{
	if (isEmpty(stack))
	return INT_MIN;
	return stack->array[stack->top];
}

// Driver
int main()
{
	struct Stack* stack = createStack(STACK_SIZE);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	
	return 0;
}