#include <stdio.h>

int main() {
    int arr[100], n, i, key, first, last, middle;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last) {
        if (arr[middle] < key) {
            first = middle + 1;
        } else if (arr[middle] == key) {
            printf("Element found at index %d\n", middle);
            break;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }

    if (first > last) {
        printf("Element not found\n");
    }

    return 0;
}

/*
Output:
Enter the number of elements in the array: 5
Enter the elements of the array in sorted order:
10 20 30 40 50
Enter the element to search: 30
Element found at index 2
*/
