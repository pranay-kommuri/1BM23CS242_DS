#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list (initialize with an empty list)
void createList(struct Node** head) {
    *head = NULL;  // Initialize the list as empty
    printf("Doubly Linked List created.\n");
}

// Function to insert a new node to the left of a specific node
void insertLeft(struct Node** head, int target, int newData) {
    struct Node* current = *head;
    struct Node* newNode = createNode(newData);
    
    // Traverse the list to find the target node
    while (current != NULL) {
        if (current->data == target) {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head = newNode; // If target node is at the beginning, update head
            }
            current->prev = newNode;
            printf("Inserted %d to the left of %d\n", newData, target);
            return;
        }
        current = current->next;
    }

    // If target not found
    printf("Node with value %d not found.\n", target);
}

// Function to delete a node based on a specific value
void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;

    // Traverse the list to find the node to delete
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next; // If the node to delete is the head
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            printf("Node with value %d deleted.\n", value);
            return;
        }
        current = current->next;
    }

    // If node not found
    printf("Node with value %d not found.\n", value);
}

// Function to display the contents of the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head;
    int choice, data, target;

    createList(&head); // Create an empty doubly linked list

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Left of a Node\n");
        printf("2. Delete a Node by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target value: ");
                scanf("%d", &target);
                printf("Enter the new node value: ");
                scanf("%d", &data);
                insertLeft(&head, target, data);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
