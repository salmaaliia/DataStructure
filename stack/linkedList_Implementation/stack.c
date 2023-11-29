#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createStack(stack *ps)
{
    ps->top = NULL;
    ps->size =0;
}

int push(stackEntry e, stack *ps)
{
    stackNode *pn = (stackNode*) malloc(sizeof(stackNode));
    if(!pn)
        return 0;
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
    return 1;
}

void pop(stackEntry *pe, stack *ps)
{
    *pe = ps->top->entry;
    stackNode *pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}

int stackEmpty(stack *ps)
{
    return ps->top == NULL;
}

int stackFull(stack *ps)
{
    return 0;
}

void clearStack(stack *ps)
{
    stackNode *pn = ps->top;
    while (pn) {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->size =0;
}

void traverseStack(stack *ps, void (*pf) (stackEntry))
{
    stackNode *pn = ps->top;
    while (pn)
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}

void stackTop(stackEntry *pe , stack *ps)
{
    *pe = ps->top->entry;
}
int stackSize(stack *ps)
{
    return ps->size;
//    int x;
//    stackNode *pn = ps->top;
//    while (pn)
//    {
//        pn = pn->next;
//        x++;
//    }
//
//    return x;
}
