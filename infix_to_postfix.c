#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char c) {
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main() {
    char exp[MAX];
    char *e, x;
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    e = exp;
    printf("Postfix expression: ");
    while (*e != '\0') {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            push(*e);
        else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());
            push(*e);
        }
        e++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}

/*
Output:
Enter the infix expression: a+b*c
Postfix expression: abc*+
*/
