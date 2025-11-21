#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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
