#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for cart item
struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Item* next;
};

struct Item* head = NULL;

// Add item to cart
void addItem() {
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));

    printf("Enter Item ID: ");
    scanf("%d", &newItem->id);

    printf("Enter Item Name: ");
    scanf(" %[^\n]", newItem->name);

    printf("Enter Price: ");
    scanf("%f", &newItem->price);

    printf("Enter Quantity: ");
    scanf("%d", &newItem->quantity);

    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        struct Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }

    printf("Item added to cart!\n");
}

// Remove item by ID
void removeItem() {
    int id;
    printf("Enter Item ID to remove: ");
    scanf("%d", &id);

    struct Item *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Item removed!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Item removed!\n");
}

// Display cart items and total
void displayCart() {
    struct Item* temp = head;
    float total = 0;

    if (temp == NULL) {
        printf("Cart is empty!\n");
        return;
    }

    printf("\n--- Shopping Cart ---\n");

    while (temp != NULL) {
        float itemTotal = temp->price * temp->quantity;

        printf("ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Price: %.2f\n", temp->price);
        printf("Quantity: %d\n", temp->quantity);
        printf("Item Total: %.2f\n\n", itemTotal);

        total += itemTotal;
        temp = temp->next;
    }

    printf("Total Price: %.2f\n", total);
}

// Free memory
void freeCart() {
    struct Item* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Shopping Cart Menu ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Cart\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayCart();
                break;
            case 4:
                freeCart();
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}