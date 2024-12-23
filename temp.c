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
