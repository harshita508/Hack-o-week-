#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book library[MAX];
int count = 0;

// Function to add a book
void addBook() {
    if (count >= MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author: ");
    scanf(" %[^\n]", library[count].author);

    count++;
    printf("Book added successfully!\n");
}

// Function to display books
void displayBooks() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("\nLibrary Catalogue:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", library[i].id);
        printf("Title: %s\n", library[i].title);
        printf("Author: %s\n\n", library[i].author);
    }
}

// Function to remove a book
void removeBook() {
    int id, found = 0;

    printf("Enter Book ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;

            // Shift books left
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }

            count--;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Remove Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}