#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size;

int isFull() {
    return (rear + 1) % size == front;
}

int isEmpty() {
    return front == -1;
}

int INSERT(int ele) {
    if (isFull()) {
        printf("Queue is full\n");
        return 0;
    } else {
        if (front == -1) { // Queue is initially empty
            front = 0;
        }
        rear = (rear + 1) % size; // Update rear in circular manner
        queue[rear] = ele; // Insert element
        printf("Successfully inserted: %d\n", ele);
        return 0;
    }
}

int DELETE() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return 0;
    } else {
        printf("Successfully deleted: %d\n", queue[front]);
        if (front == rear) { // Queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size; // Update front in circular manner
        }
        return 0;
    }
}

void DISPLAY() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % size; // Move in circular manner
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    while (1) {
        int choice, element;
        printf("(1) Insert\n(2) Delete\n(3) Display\n(4) Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                INSERT(element);
                break;
            case 2:
                DELETE();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
