#pragma once

#include "task.h"

typedef struct
{
    TASK* head;
    TASK* tail;
}QUEUE;

// QUEUE
void putToPendingQueue(QUEUE** queue, TASK* newTask) {
    printf("Putting Task to Pending Queue\n\n");

    if(!newTask)
    {
        return;
    }

    if(queue && *queue)
    {
        if((*queue)->head)
        {
            TASK* aux = (*queue)->tail;
            (*queue)->tail = newTask;
            aux->next = (*queue)->tail;
        }
        else
        {
            (*queue)->head = newTask;
            (*queue)->tail = newTask;
        }       
    }
    else
    {
        QUEUE* newQueue = (QUEUE*) malloc(sizeof(QUEUE));

        if(newQueue)
        {
            newQueue->head = newTask;
            newQueue->tail = newTask;
        }

        *queue = newQueue;
    }
}

TASK* getFromPendingQueue(QUEUE** queue) {
    printf("Getting Task from Pending Queue\n\n");

    if(queue && *queue)
    {
        if((*queue)->head)
        {
            TASK* aux = (*queue)->head;
            (*queue)->head = aux->next;
            aux->next = NULL;

            return aux;
        }
        else
        {
            (*queue)->tail = NULL;
        }
    }

    return NULL;
}

void seeAllPendingQueue(QUEUE* queue) {
    printf("Printing All Pending Queue\n\n");

    if(!queue)
    {
        return;
    }

    printTasks(queue->head);
}