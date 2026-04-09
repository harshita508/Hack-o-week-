#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][100];  // Stack to store URLs
int top = -1;

// Push URL (visit new page)
void visitURL() {
    if (top == MAX - 1) {
        printf("History is full!\n");
        return;
    }

    char url[100];
    printf("Enter URL: ");
    scanf(" %[^\n]", url);

    top++;
    strcpy(stack[top], url);

    printf("Visited: %s\n", url);
}

// Pop URL (go back)
void goBack() {
    if (top <= 0) {
        printf("No previous page!\n");
        return;
    }

    top--;
    printf("Went back to: %s\n", stack[top]);
}

// Peek current page
void currentPage() {
    if (top == -1) {
        printf("No pages visited!\n");
        return;
    }

    printf("Current Page: %s\n", stack[top]);
}

// Display full history
void displayHistory() {
    if (top == -1) {
        printf("No browsing history!\n");
        return;
    }

    printf("\n--- Browsing History ---\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Browser Menu ---\n");
        printf("1. Visit URL\n");
        printf("2. Back\n");
        printf("3. Current Page\n");
        printf("4. Show History\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitURL();
                break;
            case 2:
                goBack();
                break;
            case 3:
                currentPage();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}