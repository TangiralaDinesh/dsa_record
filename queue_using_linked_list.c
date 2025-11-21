#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued element: %d\n", front->data);
        struct node *temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = front;
        printf("Queue elements: ");
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
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 10

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to enqueue: 20

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10 20 

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued element: 10

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 20 

1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
*/
