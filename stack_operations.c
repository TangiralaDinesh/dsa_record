#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}

/*
Output:

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 10

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the value to push: 20

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 20 10 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popped element: 20

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
*/
