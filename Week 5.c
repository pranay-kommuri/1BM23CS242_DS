#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
void createList(struct Node** head) {
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Creating the first node
    if (n > 0) {
        printf("Enter data for node 1: ");
        scanf("%d", &data);
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;

        struct Node* temp = *head;

        // Creating the remaining nodes
        for (int i = 2; i <= n; i++) {
            printf("Enter data for node %d: ", i);
            scanf("%d", &data);
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the first element in the list
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete the first element.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First element deleted.\n");
}

// Function to delete a specified element in the list
void deleteElement(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty, cannot delete the element.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the element to be deleted is the first node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("Element %d deleted.\n", value);
        return;
    }

    // Search for the element to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Element not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted.\n", value);
}

// Function to delete the last element in the list
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete the last element.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If there is only one element in the list
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Last element deleted.\n");
        return;
    }

    // Traverse to the second last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete the last node
    prev->next = NULL;
    free(temp);
    printf("Last element deleted.\n");
}

int main() {
    struct Node* head = NULL;

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Delete the first element\n");
        printf("4. Delete a specified element\n");
        printf("5. Delete the last element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                deleteFirst(&head);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &value);
                deleteElement(&head, value);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
