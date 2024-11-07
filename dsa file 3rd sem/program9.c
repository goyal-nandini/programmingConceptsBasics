// Create a menu-driven program that implements and demonstrates key sorting 
// algorithms: bubble sort , selection sort, insertion sort, heap sort, quick and merge 
// sort. Users should be able to choose the sorting method and input an array to be 
// sorted.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void heapSort(int *arr, int n);
void quickSort(int *arr, int low, int high);
void mergeSort(int *arr, int lb, int ub);
int partition(int*, int, int);
void merge(int*, int , int , int);
void heapify(int*, int, int);

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
    
    do
    {
        printf("Enter your choice (1-7): ");
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
                printf("\nExiting the program.");
                break;    
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 7);
    // if (choice >= 1 && choice <= 6) {
    //         printArray(p, n);
    // }
    return 0;
}

void bubbleSort(int *arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int flag = 0;
        for(int j=0; j<n-1-i; j++){
            if(*(arr+j) > *(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+1+j);
                *(arr+j+1) = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}
void selectionSort(int *arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            temp = *(arr+i);
            *(arr+i) = *(arr+min);
            *(arr+min) = temp;
        }
    }
}
void insertionSort(int *arr, int n){
    int temp, j;
    for(int i=1; i<n; i++){
        temp = *(arr+i);
        j = i-1;
        while(j>=0 && *(arr+j)>temp){
            *(arr+j+1) = *(arr+j);
            j--; 
        }
        *(arr+j+1) = temp;
    }
}
void heapSort(int *arr, int n){
    int temp;
    for(int i=(n/2)-1; i>=0; i--){ //changed from nb
        heapify(arr, n, i);
    }
    for(int i = n-1; i > 0; i--){ // changed
        temp = *(arr);
        *(arr) = *(arr+i);
        *(arr+i) = temp;
        heapify(arr, i, 0); //changed
    }
}
void heapify(int *arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    int temp;
    if(left < n && *(arr+left) > *(arr+largest)){ //changed here nd below 
        largest = left;
    }
    if(right < n && *(arr+right) > *(arr+largest)){
        largest = right;
    }
    if(largest != i){
        temp = *(arr+largest);
        *(arr+largest) = *(arr+i);
        *(arr+i) = temp;
        heapify(arr, n, largest);
    }
}
void quickSort(int *arr, int low, int high){
    if(low < high){
        int loc = partition(arr, low, high);
        quickSort(arr, low, loc-1);
        quickSort(arr, loc+1, high);
    }
}
int partition(int *arr, int low, int high){
    int pivot = *(arr + low); // changed from nb
    int start = low;
    int end = high;
    int temp;
    while(start < end){
        while(*(arr + start) <= pivot){
            start++;
        }
        while(*(arr + end) > pivot){
            end--;
        }
        if(start < end){
            temp = *(arr + start);
            *(arr+start) = *(arr+end);
            *(arr+end) = temp;
        }
    }
        temp = *(arr + low);
        *(arr+low) = *(arr+end);
        *(arr+end) = temp;
        return end;
}
void mergeSort(int *arr, int lb, int ub){
    if(lb < ub){
        int mid = (lb + ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}
void merge(int *arr, int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k = 0; // changed from nb
    int *b = (int *)malloc((ub-lb+1)*sizeof(int)); // changed from nb
    while(i <= mid && j <= ub){ //changed
        if(*(arr+i) <= *(arr+j)){
            *(b+k) = *(arr+i);
            i++;
            k++;
        } else{
            *(b+k) = *(arr+j);
            j++;
            k++;
        }
        // if(i <= mid){
        //     while(j <= ub){ //changed
        //         *(b+k) = *(arr+j);
        //         j++;
        //         k++;
        //     } 
        // } else{
        //     while(i <= mid){
        //         *(b+k) = *(arr+i);
        //         i++;
        //         k++;
        //     }
        // }
    while(i <= mid) {
        *(b + k) = *(arr + i);
        i++;
        k++;
    }
    
    while(j <= ub) {
        *(b + k) = *(arr + j);
        j++;
        k++;
    }
    for(k = 0; k < (ub-lb+1); k++) // changed from nb
        *(arr+k+lb) = *(b+k);    // changed
    }
    free(b); //changed from nb
}