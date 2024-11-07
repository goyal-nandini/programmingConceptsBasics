// Develop a menu-driven program to implement fundamental array operations, 
// including element insertion, deletion, search, and reversal. The program should 
// allow the user to select and perform each operation interactively

#include <stdio.h>
#include <stdlib.h>

void getArray(int arr[], int size);
void traverseArray(int arr[], int size);
void insertElement(int arr[], int *size, int pos, int item);
void deleteElement(int arr[],int *size, int pos);
void searchElement(int arr[], int size, int ele);
void reverseArray(int arr[], int size);
void clearInputBuffer(); // Function to clear the input buffer

int main(){
    int choice, N, *arr;
    char restart;
    do{
        printf("Welcome to the menu-driven program.\nYou have to enter an array to get started.");
        printf("\nEnter the Size of the array: ");
        // scanf("%d", &N);

        // Check if input is valid
        while (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input! Please enter a positive integer for the size of the array: ");
        clearInputBuffer();  // Clear the input buffer for invalid inputs
        }

        // Allocate memory for the array
        arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit if memory allocation fails
        }

        getArray(arr, N);
        printf("\nInstruction:\nEnter 1 for traversing the array,\n2 for inserting an element at desired position,\n3 for deleting an element,\n4 to search any element,\n5 for reversing the given array and\n0 to exit the program");

        do {
            printf("\n-----------------------------");
            printf("\nEnter choice: ");

            // Validate that user input is a valid integer choice
            while (scanf("%d", &choice) != 1) {
                printf("Invalid input! Please enter a valid choice (0-5): ");
                clearInputBuffer();  // Clear buffer for invalid inputs
                // scanf("%d", &choice);
            }    

            switch (choice) {
                case 1:
                    traverseArray(arr, N);
                    break;
                case 2: {
                    int pos, item;
                    printf("Enter the element where you want to insert: ");
                    // Validate element input
                    while (scanf("%d", &item) != 1) {
                        printf("Invalid input! Please enter an integer value for the array: ");
                        clearInputBuffer();
                    }
                    // scanf("%d", &item);

                    printf("Enter the position to insert the element: ");
                    // Validate position input
                    while (scanf("%d", &pos) != 1 || pos < 1 || pos > N+1) {
                        printf("Invalid position! Please enter a position between 1 and %d: ", N+1);
                        clearInputBuffer();
                    }
                    // scanf("%d", &pos);
                    insertElement(arr, &N, pos, item);
                    break;
                }   
                case 3: {
                    int pos;
                    printf("Enter the position from where you want to delete the element: ");
                    // scanf("%d", &pos);
                    // Validate position input
                    while (scanf("%d", &pos) != 1 || pos < 1 || pos > N) {
                        printf("Invalid position! Please enter a valid position between 1 and %d: ", N);
                        clearInputBuffer();
                    }
                    deleteElement(arr, &N, pos);
                    break;
                }
                case 4: {
                    int ele;
                    printf("Enter the element you want to search: ");
                    // scanf("%d", &ele);
                    // Validate element input
                    while (scanf("%d", &ele) != 1) {
                        printf("Invalid input! Please enter an integer value for the array: ");
                        clearInputBuffer();
                    }
                    searchElement(arr, N, ele);
                    break;
                }
                case 5: 
                    printf("Reversing the array...\n");
                    reverseArray(arr, N);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    break;
                default:
                    printf("Invalid choice! Please try again.\n");
                    break;
            }
        } while (choice != 0);
        // Free the allocated memory
        free(arr);
        // Ask if the user wants to restart
        printf("Do you want to restart the program? (y/n): ");
        scanf(" %c", &restart);
        clearInputBuffer(); // Clear buffer to prevent leftover characters

    } while (restart == 'y' || restart == 'Y');
    printf("Thank you for using the program.\n");
    return 0;
}

void getArray(int arr[], int size) {
    printf("Enter the elements of the array:");
    for (int i = 0; i < size; i++) {
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input! Please enter an integer for element %d: ", i + 1);
            clearInputBuffer();  // Clear invalid input
        }
        // scanf("%d", &arr[i]);
    }
    
}

void traverseArray(int arr[], int size) {
    printf("The elements of the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int pos, int item){
    if(pos < 1 || pos > *size+1){
        printf("\nInvalid Position!\n");
    } else {
        for(int i = *size-1; i >= pos-1; i--){
            arr[i+1]=arr[i];
        }
        arr[pos-1] = item;
        (*size)++;
        printf("Element inserted successfully.\n");
        traverseArray(arr, *size);
    }
}

void deleteElement(int arr[],int *size, int pos){
    if(pos < 1 || pos > *size){
        printf("\nInvalid Position!\n");
    } else {
        for(int i = pos-1; i < *size-1; i++){
            arr[i] = arr[i+1];
        }
        (*size)--;
        traverseArray(arr, *size);
    }
}

void searchElement(int arr[], int size, int ele) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == ele) {
            printf("The element %d found at position %d\n", ele, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("The element %d not found!\n", ele);
    }
}

// void searchElement(int arr[], int size, int ele){
//     int first = 0;
//     int last = size-1;
//     int middle = (first+last)/2;
//     while(first <= last){
//         if(arr[middle] < ele){
//             first = middle+1;
//         } else if(arr[middle] == ele){
//             printf("The element %d found at %d\n", ele, middle+1);
//             break;
//         } else {
//             last = middle-1;
//         }
//         middle = (first + last)/2;
//         if(first > last){
//             printf("The element %d not found!\n", ele);
//         }
//     }
// }

void reverseArray(int arr[], int size){
    // for(int i=0; i<size/2; i++){
    //     int first = arr[i];
    //     int second = arr[size-i-1];
    //     arr[i] = second; 
    //     arr[size-i-1] = first;
    // }
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("The array after reversing is: ");
    traverseArray(arr, size);
}

// Clear the input buffer to handle invalid inputs
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Discard any leftover input
}
