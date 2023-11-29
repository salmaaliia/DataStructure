#ifndef STACK_H_
#define STACK_H_

#define stackEntry int

typedef struct StackNode{
    stackEntry entry;
    struct StackNode *next;
}stackNode;

typedef struct Stack{
    stackNode *top;
    int size;
}stack;

void createStack(stack *);

int push(stackEntry , stack *);

void pop(stackEntry *, stack *);

int stackEmpty(stack *);

int stackFull(stack *);

void clearStack(stack *);

void traverseStack(stack *ps, void (*pf) (stackEntry));

int stackSize(stack *ps);

void stackTop(stackEntry * , stack *);

#endif