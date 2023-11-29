#include <stdio.h>
#include "stack.h"

void createStack(stack *ps)
{
    ps->top = 0;
}

void push(stackEntry e, stack *ps)
{
    ps->entry[ps->top++] = e;
}

void pop(stackEntry *pe , stack *ps)
{
    *pe = ps->entry[--ps->top];
}

int stackFull(stack *ps)
{
    return ps->top >= maxStack;
}

int stackEmpty(stack *ps)
{
    return !ps->top;
}

void stackTop(stackEntry *pe , stack *ps)
{
    *pe = ps->entry[ps->top - 1];
}

void clearStack(stack *ps)
{
    ps->top = 0;
}

int stackSize(stack *ps)
{
    return ps->top;
}

void traverseStack(stack *ps, void (*pf) (stackEntry))
{
    for (int i = ps->top - 1; i >= 0 ; --i) {
        (*pf)(ps->entry[i]);
    }
}
