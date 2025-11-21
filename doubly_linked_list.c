#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

void insert_end(int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head;
        printf("List elements: ");
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
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Delete from beginning\n4. Delete from end\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                delete_begin();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}

/*
Output:

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 1
Enter the value to insert: 10

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 2
Enter the value to insert: 20

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 5
List elements: 10 20

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 3

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 5
List elements: 20

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 4

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 5
List is empty

1. Insert at beginning
2. Insert at end
3. Delete from beginning
4. Delete from end
5. Display
6. Exit
Enter your choice: 6
*/
