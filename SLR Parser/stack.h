//
//  stack.h
//  SLR-new
//
//  Created by eRrOr on 30/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef stack_h
#define stack_h

struct Stack
{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack)
{   return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack* stack)
{   return stack->top == -1;  }

void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

#endif /* stack_h */
