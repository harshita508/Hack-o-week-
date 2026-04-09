#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for print job
struct Job {
    int id;
    char name[50];
    int pages;
    struct Job* next;
};

struct Job* front = NULL;
struct Job* rear = NULL;

// Add job (enqueue)
void addJob() {
    struct Job* newJob = (struct Job*)malloc(sizeof(struct Job));

    printf("Enter Job ID: ");
    scanf("%d", &newJob->id);

    printf("Enter Document Name: ");
    scanf(" %[^\n]", newJob->name);

    printf("Enter Number of Pages: ");
    scanf("%d", &newJob->pages);

    newJob->next = NULL;

    if (rear == NULL) {
        front = rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }

    printf("Print job added to queue!\n");
}

// Process job (dequeue)
void processJob() {
    if (front == NULL) {
        printf("No print jobs in queue!\n");
        return;
    }

    struct Job* temp = front;

    printf("\nProcessing Job...\n");
    printf("ID: %d\n", temp->id);
    printf("Document: %s\n", temp->name);
    printf("Pages: %d\n", temp->pages);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    printf("Job completed and removed from queue.\n");
}

// Display queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Job* temp = front;

    printf("\n--- Print Queue (FIFO Order) ---\n");
    while (temp != NULL) {
        printf("ID: %d | Document: %s | Pages: %d\n",
               temp->id, temp->name, temp->pages);
        temp = temp->next;
    }
}

// Free memory
void freeQueue() {
    struct Job* temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Print Queue Menu ---\n");
        printf("1. Add Print Job\n");
        printf("2. Process Print Job\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                processJob();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                freeQueue();
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}