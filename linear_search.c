#include <stdio.h>

int main() {
    int arr[100], n, i, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            break;
        }
    }

    if (i == n) {
        printf("Element not found\n");
    }

    return 0;
}

/*
Output:
Enter the number of elements in the array: 5
Enter the elements of the array:
10 20 30 40 50
Enter the element to search: 30
Element found at index 2
*/
