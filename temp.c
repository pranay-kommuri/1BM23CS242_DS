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
