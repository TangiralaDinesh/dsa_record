#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = top;
    top = new_node;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", top->data);
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
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
