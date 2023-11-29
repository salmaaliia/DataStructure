#ifndef STACK_H
#define STACK_H

#define stackEntry int
#define maxStack 100

typedef struct Stack{
    int top;
    stackEntry entry[maxStack]
}stack;

void createStack(stack *);

/*
 * pre: The stack is initialized and not full
 * post: The element e has been stored at the top of the stack, and e does not change
 * The user has to check before calling push
 */
void push(stackEntry , stack *);

/*
 * pre: The stack is initialized and not empty.
 * post: The last element entered is returned.
 * */
void pop(stackEntry * , stack *);

int stackFull(stack *);

int stackEmpty(stack *);

void stackTop(stackEntry * , stack *);

/*
 * pre : The stack is initialized.
 * post: destroy all elements, the stack looks initialized.
 * */
void clearStack(stack *);

/*
 * pre: The stack is initialized.
 * post: returns how many elements exist.
 * */
int stackSize(stack *);

void traverseStack(stack *, void (*) (stackEntry));
#endif