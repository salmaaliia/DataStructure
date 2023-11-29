#include <stdio.h>
#include "stack.h"

void Display(stackEntry);
int main() {


    stack s;
    int x;

    stackEntry se[5] ={6, 7, 8, 9, 10};
    stackEntry e = 7;

    createStack(&s);

    for (int i = 0; i < 5; ++i) {
        if(!stackFull(&s)) {
            push(se[i], &s);
        }
    }
    traverseStack(&s, Display);

    printf("\n\n");
    if(!stackEmpty(&s))
    {
        pop(&e, &s);
    }
    traverseStack(&s, Display);

    if(!stackEmpty(&s))
    {
        stackTop(&e, &s);
    }
    printf("\n%d", e);

    x = stackSize(&s);
    printf("\n%d", x);

//    clearStack(&s);

    return 0;
}

void Display(stackEntry e)
{
    printf("%d\n", e);
}