#include<stdio.h>
int stack[100];
int top=-1;
int size;

//PUSH FUNCTION
void PUSH(int ele){
    if(top==(size-1)){
        printf("<error:stack is full>\n");
    }else{
        top++;
        stack[top]=ele;
        printf("Successfully pushed\n");
    }
} 
//POP FUNCTION
void POP(){
    if(top==-1){
        printf("<error:stack is empty>\n");
    }else{
        top--;size--;
        printf("Successfully popped\n");
    }
} 
//DISPLAY FUNCTION
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }else{
        printf("Stack: ");
        for(int i=0;i<size;i++){
            printf("%d ",i);
        }printf("\n")
    }
} 
//MAIN FUNCTION
int main(){
    int choice,element;
    int x=1;
    printf("Enter the number of variables in stack: ");
    scanf("%d",&size);
    while(x>0){
        printf("Enter choice-\n");
        printf("(1) PUSH\n(2) POP\n(3) Display\n(4) Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter an element: ");
                    scanf("%d",&element);
                    PUSH(element);
                    break;
            case 2: POP();
                    break;
            case 3: display();
                    break;
            case 4: printf("Bye");
                    x=0;
                    break;
        }
    }
}

