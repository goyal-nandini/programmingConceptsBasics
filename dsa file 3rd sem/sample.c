#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void heapSort(int *arr, int n);
void quickSort(int *arr, int low, int high);
void mergeSort(int *arr, int lb, int ub);
int partition(int *arr, int low, int high);
void merge(int *arr, int lb, int mid, int ub);
void maxheapify(int *arr, int n, int i);

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, choice, i;
    int *p = arr; //pointer to the beginning of the array

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if (n > MAX_SIZE) {
        printf("Array size exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", p+i);
    }

    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Heap Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Merge Sort\n");
    printf("7. Exit\n");

    do {
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bubbleSort(p, n);
                printf("Sorted array using Bubble Sort:\n");
                printArray(p, n);
                break;
            case 2:
                selectionSort(p, n);
                printf("Sorted array using Selection Sort:\n");
                printArray(p, n);
                break;
            case 3:
                insertionSort(p, n);
                printf("Sorted array using Insertion Sort:\n");
                printArray(p, n);
                break;
            case 4:
                heapSort(p, n);
                printf("Sorted array using Heap Sort:\n");
                printArray(p, n);
                break;
            case 5:
                quickSort(p, 0, n - 1);
                printf("Sorted array using Quick Sort:\n");
                printArray(p, n);
                break;
            case 6:
                mergeSort(p, 0, n - 1);
                printf("Sorted array using Merge Sort:\n");
                printArray(p, n);
                break;
            case 7:
                printf("\nExiting the program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

void bubbleSort(int *arr, int n){
    int temp;
    for(int i = 0; i < n - 1; i++) {
        int flag = 0;
        for(int j = 0; j < n - 1 - i; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

void selectionSort(int *arr, int n) {
    int temp, minIndex;
    for(int i = 0; i < n - 1; i++) {
        minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(*(arr + j) < *(arr + minIndex)) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            temp = *(arr + i);
            *(arr + i) = *(arr + minIndex);
            *(arr + minIndex) = temp;
        }
    }
}

void insertionSort(int *arr, int n) {
    int temp, j;
    for(int i = 1; i < n; i++) {
        temp = *(arr + i);
        j = i - 1;
        while(j >= 0 && *(arr + j) > temp) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = temp;
    }
}

void heapSort(int *arr, int n) {
    int temp;
    for(int i = n / 2 - 1; i >= 0; i--) {
        maxheapify(arr, n, i);
    }
    for(int i = n - 1; i >= 1; i--) {
        temp = *(arr);
        *(arr) = *(arr + i);
        *(arr + i) = temp;
        maxheapify(arr, i, 0);
    }
}

void maxheapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    
    if(left < n && *(arr + left) > *(arr + largest))
        largest = left;
    if(right < n && *(arr + right) > *(arr + largest))
        largest = right;
    
    if(largest != i) {
        temp = *(arr + i);
        *(arr + i) = *(arr + largest);
        *(arr + largest) = temp;
        maxheapify(arr, n, largest);
    }
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc - 1);
        quickSort(arr, loc + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = *(arr + low);
    int start = low;
    int end = high;
    int temp;
    
    while(start < end) {
        while(*(arr + start) <= pivot)
            start++;
        while(*(arr + end) > pivot)
            end--;
        if(start < end) {
            temp = *(arr + start);
            *(arr + start) = *(arr + end);
            *(arr + end) = temp;
        }
    }
    
    temp = *(arr + low);
    *(arr + low) = *(arr + end);
    *(arr + end) = temp;
    return end;
}

void mergeSort(int *arr, int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int *arr, int lb, int mid, int ub) {
    int *b = (int *)malloc((ub - lb + 1) * sizeof(int)); // Dynamically allocate space for the temporary array
    int i = lb, j = mid + 1, k = 0;
    
    while(i <= mid && j <= ub) {
        if(*(arr + i) <= *(arr + j)) {
            *(b + k) = *(arr + i);
            i++;
        } else {
            *(b + k) = *(arr + j);
        }
    }        
           
}