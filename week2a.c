#include <stdio.h>
#include <string.h>

int top = -1, pos = 0, index = 0, length;
char infix[20], postfix[20], stack[20], symbol;

void pop() {
    if (stack[top] == '(') {
        top--;
    } else {
        postfix[pos++] = stack[top--];
    }
}

void push(char element) {
    stack[++top] = element;
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
        case ')':
            return 4;
        default:
            return 0;
    }
}

void infixtopostfix() {
    length = strlen(infix);
    index = 0;
    top = -1;
    pos = 0;

    while (index < length) {
        symbol = infix[index];

        switch (symbol) {
            case '(':
                push(symbol);
                break;

            case ')':
                while (top != -1 && stack[top] != '(') {
                    pop();
                }
                pop(); // pop '('
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (top != -1 && precedence(symbol) <= precedence(stack[top])) {
                    pop();
                }
                push(symbol);
                break;

            default:
                postfix[pos++] = symbol; // operand
                break;
        }
        index++;
    }

    while (top != -1) {
        pop();
    }
    postfix[pos] = '\0'; // null terminate the postfix expression
}

int main() {
    printf("Enter the expression: ");
    scanf("%s", infix);
    infixtopostfix();
    printf("\nInfix expression: %s", infix);
    printf("\nPostfix expression: %s\n", postfix);
    return 0;
}
