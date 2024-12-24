#include <stdio.h>
#include <stdlib.h>

struct items{
    int top, element, index, n;
    char infix[20], postfix[20], stack[20];
}
void PUSH(struct items p, chat ele){
     p->stack[p->top++] = ele;
}
int POP(struct items p){
    p->postfix[p->n++] = p->stack[p->top--];
    return p->postfix[p->n];
}
int PRECEDENCE(symbol){
    switch(symbol){
        case('+'||'-'): return 1;
        case('*'||'/'): return 2;
        case('^'): return 3;
        case('('||')'): return 4;
    }
}
void INFIXTOPOSTFIX(struct items s){
    
}

/*

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top, size;
    int stack[100];
};

void PUSH(struct stack* s, int ele) {
    if (s->top == s->size-1){
        printf("\n<error: stack overflow>");
    }else{
        s->top+=1;
        s->stack[s->top]=ele;
    }
}

int POP(struct stack* s) {
    if (s->top == -1){
        printf("\n<error: stack underflow>\n");
        return 0;
    }else{
        int ele=s->stack[s->top];
        s->top-=1;
        return ele;
    }
}

void DISPLAY(struct stack* s) {
    if (s->top == -1){
        printf("\n<error: stack underflow>");
    }else{
        printf("\nStack items:\n");
        for(int i=(s->top);i>=0;i--){
            printf("%d [%4d]\n",i,s->stack[i]);
        }
    }
}

int main() {
    int pushele, choice, poppedele;
    struct stack s;
    s.top=-1;
    
    printf("\nEnter the stack size: ");
    scanf("%d",&s.size);
    
    while(1){
        printf("\nEnter choice:");
        printf("\n(1)PUSH (2)POP (3)DISPLAY (4)EXIT: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to push:");
                    scanf("%d",&pushele);
                    PUSH(&s,pushele);
                    break;
            case 2: poppedele = POP(&s);
                    break;
            case 3: DISPLAY(&s);
                    break;
            case 4: exit(0);
        }
    }
}


*/
/*
#include <stdio.h>
#include <stdlib.h>

struct cqueue{
    int front, rear, size;
    int cqueue[100];
};
void ENQUEUE(struct cqueue* cq, int ele){
    if((cq->rear + 1) % cq->size == cq->front){
         printf("\n<error: circular queue overflow>\n");
    }else if(cq->rear==-1){
        cq->front=0;
        cq->rear=0;
        cq->cqueue[cq->rear] = ele;
    } else {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->cqueue[cq->rear] = ele;
    }
}
int DEQUEUE(struct cqueue* cq){
    if(cq->rear==-1){
        printf("\n<error: circular queue underflow>");
    }else if(cq->front==cq->rear){
        int ele = cq->cqueue[cq->front];
        cq->front = -1;
        cq->rear = -1;
        return ele;
    }else{
        int ele = cq->cqueue[cq->front];
        cq->front = (cq->front + 1)%(cq->size);
        return ele;
    }
}
void DISPLAY(struct cqueue* cq){
    if(cq->rear==-1){
        printf("\n<error: circular queue underflow>");
    }else{
        printf("\nCircular queue items: \n");
        for (int i=cq->front; i!=cq->rear; (i++)%cq->size){
            printf("[%3d]", cq->cqueue[i]);
        }printf("[%3d] \n", cq->cqueue[cq->rear]);

        for (int i=cq->front; i!=cq->rear; (i++)%cq->size){
            printf("%3d  ", i);
        }printf("%3d  \n", cq->rear);
    }
}
int main(){
    int enqele, choice, deqele;
    struct cqueue cq;
    cq.front=-1;
    cq.rear=-1;
    printf("\nEnter the circular queue size: ");
    scanf("%d", &cq.size);
    while(1){
        printf("\nEnter choice:");
        printf("\n(1)ENQUEUE (2)DEQUEUE (3)DISPLAY (4)EXIT : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to enqueue: ");
                    scanf("%d",&enqele);
                    ENQUEUE(&cq,enqele);
                    break;
            case 2: deqele = DEQUEUE(&cq);
                    break;
            case 3: DISPLAY(&cq);
                    break;
            case 4: exit(0);
                    
        }
    }return 0;
}


*/
/*
#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a linked list
void create_linked_list() {
    int data;
    printf("Enter elements to add to the linked list (-1 to stop):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
}

// Insert at the beginning
void insert_at_first(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Insert at a specific position
void insert_at_position(int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (position == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Insert at the end
void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Delete the first node
void delete_first() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete at a specific position
void delete_at_position(int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

// Delete the last node
void delete_last() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;

    printf("Create the linked list:\n");
    create_linked_list();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display list\n");
        printf("2. Insert at first\n");
        printf("3. Insert at position\n");
        printf("4. Insert at end\n");
        printf("5. Delete first\n");
        printf("6. Delete at position\n");
        printf("7. Delete last\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;

            case 2:
                printf("Enter data to insert at first: ");
                scanf("%d", &data);
                insert_at_first(data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_position(data, position);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;

            case 5:
                delete_first();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;

            case 7:
                delete_last();
                break;

            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

*/

/*
void sortList(struct Node** head) {
    struct Node* current = *head;
    struct Node* index = NULL;
    int temp;

    if (head == NULL) return;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

*/
/*

// Stack Operations
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Queue Operations
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL; // If queue becomes empty
    }
    free(temp);
    return data;
}
*/
