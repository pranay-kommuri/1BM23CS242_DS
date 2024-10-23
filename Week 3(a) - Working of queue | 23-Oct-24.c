#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;
int size;

int INSERT(int ele) {
    if (rear == size - 1) {
        printf("Queue is full\n");
        return 0;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = ele; // Insert element
        printf("Successfully inserted\n");
        return 0;
    }
}

int DELETE() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return 0;
    } else {
        printf("Successfully deleted: %d\n", queue[front]);
        front++;
        return 0;
    }
}

void DISPLAY() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    while (1) {
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
