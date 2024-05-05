#pragma once

#include "task.h"

typedef TASK LIST;

// LIST
void addToCompletedList(LIST** list, TASK* newTask) {
    printf("Adding Task to Completed List\n\n");

    if(!newTask)
    {
        return;
    }

    newTask->next = *list;
    *list = newTask;
}

TASK* removeFromCompletedListByItsId(LIST** list, int id) {
    printf("Removing Task from Completed List\n\n");

    if(!(*list))
    {
        return NULL;
    }

    TASK* prev = *list;

    while(prev->next != NULL)
    {
        if(prev->next->id == id)
        {
            break;
        }

        prev = prev->next;
    }

    TASK* aux = NULL;

    if(prev->next)
    {
        aux = prev->next;

        if(prev->next->next)
        {
            prev->next = prev->next->next;
        }
        else
        {
            prev->next = NULL;
        }
    }
    else if((*list)->id == id)
    {
        aux = *list;
        *list = (*list)->next;
    }

    if(aux)
    {
        aux->next = NULL;
    }

    return aux;
}

void seeAllCompletedList(LIST* list) {
    printf("Printing All Completed List\n\n");

    printTasks(list);
}