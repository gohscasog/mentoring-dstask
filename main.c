#pragma once

#define MAX_INPUT_SIZE 2

#include "queue.h"
#include "list.h"
#include "stack.h"
#include "mathz.h"
#include "utilz.h"

// MENU
void displayMenu();

int main() {
    TASK* task = NULL;
    QUEUE* pending = NULL;
    LIST* completed = NULL;
    STACK* drafts = NULL;

    int choice;
    printf("(c) LixoWarez Ltda.\nTAZKMGR v1.0\n\n");
    printf("################ TASK MANAGER SYSTEM ################\n\n");

    do {
        displayMenu();
        printf("> ");
        choice = getUserInput();
        printf("\n");

        switch (choice) {
            case 1:
                // CREATE A TASK, THEN ADD TO PENDING QUEUE
                task = createTaskByScanf();
                putToPendingQueue(&pending, task);
                break;

            case 2:
                // SEE ALL TASKS FROM PENDING QUEUE
                seeAllPendingQueue(pending);
                break;

            case 3:
                // COMPLETE FIRST PENDING TASK
                task = getFromPendingQueue(&pending);
                addToCompletedList(&completed, task);
                break;

            case 4:
                // SEE ALL TASKS FROM COMPLETED LIST
                seeAllCompletedList(completed);
                break;

            case 5:
                // SET COMPLETED TASK TO DRAFT
                printf("Enter Task ID (number): ");
                task = removeFromCompletedListByItsId(&completed, getUserInput());
                pushToDraftStack(&drafts, task);
                break;

            case 6:
                // SEE ALL TASKS FROM DRAFT STACK
                seeAllDraftStack(drafts);
                break;

            case 7:
                // SET LAST DRAFT AS PENDING TASK
                task = popFromDraftStack(&drafts);
                putToPendingQueue(&pending, task);
                break;

            case 0:
                printf("Exiting program\n\n");
                break;

            default:
                printf("Invalid choice\n\n");
                break;
        }
    } while (choice != 0);

    printf("################# SYSTEM SHUT DOWN #################");
    printf("\n\n");
}

// MENU
void displayMenu() {
    printf("Select an option:\n");
    printf("(1) Create New Pending Task\n");
    printf("(2) See All Pending Tasks\n");
    printf("(3) Complete First Pending Task\n");
    printf("(4) See All Completed Tasks\n");
    printf("(5) Set Completed Task as Draft by its ID\n");
    printf("(6) See All Draft Tasks\n");
    printf("(7) Set Last Draft Task as Pending Task\n");
    printf("(0) Exit\n");
}