// Write a menu-driven program to implement both binary search and linear search 
// algorithms, allowing the user to search for a target element in a sorted or unsorted 
// array.

#include <stdio.h>

void linearSearch(int arr[], int, int);
void binarySearch(int arr[], int, int);

int main() {
    int choice, n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the target element for Linear Search: ");
                scanf("%d", &target);
                linearSearch(arr, n, target);
                break;

            case 2:
                printf("Enter the target element for Binary Search: ");
                scanf("%d", &target);
                printf("For Binary Search, the array must be sorted. Sorting the array...\n");
                // Sorting the array for Binary Search
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                binarySearch(arr, n, target);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

void linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d (Linear Search).\n", target, i);
            return;
        }
    }
    printf("Element %d not found (Linear Search).\n", target);
}
void binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            printf("Element %d found at index %d (Binary Search).\n", target, mid);
            return;
        }
        
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Element %d not found (Binary Search).\n", target);
}