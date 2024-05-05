#pragma once

#include "task.h"

typedef TASK STACK;

// STACK
void pushToDraftStack(STACK** stack, TASK* newTask) {
    printf("Pushing Task to Draft Stack\n\n");

    if(!newTask)
    {
        return;
    }

    newTask->next = *stack;
    *stack = newTask;
}

TASK* popFromDraftStack(STACK** stack) {
    printf("Popping Task to Draft Stack\n\n");

    if(stack && *stack)
    {
        TASK* aux = *stack;
        *stack = aux->next;
        aux->next = NULL;

        return aux;
    }

    return NULL;
}

void seeAllDraftStack(STACK* stack) {
    printf("Printing All Draft Stack\n\n");

    printTasks(stack);
}
