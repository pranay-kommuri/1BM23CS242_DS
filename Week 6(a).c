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

    if (n > 0) {
        printf("Enter data for node 1: ");
        scanf("%d", &data);
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;

        struct Node* temp = *head;
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

// Function to sort the linked list using bubble sort
void sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot sort.\n");
        return;
    }

    struct Node* i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap the data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev and current one step forward
        current = next;
    }

    *head = prev;  // Update head to the new first element
    printf("List reversed.\n");
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;  // If the first list is empty, set it to the second list
        printf("Concatenated list: ");
        displayList(*head1);
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    printf("Concatenated list: ");
    displayList(*head1);
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create the first linked list\n");
        printf("2. Create the second linked list\n");
        printf("3. Display the first linked list\n");
        printf("4. Display the second linked list\n");
        printf("5. Sort the first linked list\n");
        printf("6. Reverse the first linked list\n");
        printf("7. Concatenate both linked lists\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head1);
                break;
            case 2:
                createList(&head2);
                break;
            case 3:
                displayList(head1);
                break;
            case 4:
                displayList(head2);
                break;
            case 5:
                sortList(head1);
                break;
            case 6:
                reverseList(&head1);
                break;
            case 7:
                concatenateLists(&head1, head2);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
