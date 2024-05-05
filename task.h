#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_SIZE 100

typedef struct Task {
    int id;
    char description[MAX_DESCRIPTION_SIZE];
    struct Task* next;
} TASK;

// CONSTRUCTOR
TASK* createTask(int id, char* description) {
    TASK* newTask = (TASK*) malloc(sizeof(TASK));

    if(newTask)
    {
        newTask->id = id;
        strcpy(newTask->description, description);
        newTask->next = NULL;
    }

    return newTask;
}

TASK* createTaskByScanf() {
    int id;
    char description[MAX_DESCRIPTION_SIZE];

    printf("Enter Task ID (number): ");
    scanf("%d", &id);

    getchar();
    printf("Enter Task Description (string): ");

    fgets(description, MAX_DESCRIPTION_SIZE, stdin);
    description[strcspn(description, "\n")] = '\0';
    printf("\n");

    return createTask(id, description);
}

void printTasks(TASK* ptr) {
    printf("ID\tDESCRIPTION\n");
    
    while(ptr != NULL)
    {
        printf("%d\t%s\n", ptr->id, ptr->description);
        ptr = ptr->next;
    }

    printf("\n");
}