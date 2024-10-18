// Develop a menu-driven program to implement fundamental array operations, 
// including element insertion, deletion, search, and reversal. The program should 
// allow the user to select and perform each operation interactively

// getArray
// traverseArray
// insertElement
// deleteElement
// searchElement
// reverseArray
#include <stdio.h>

void getArray(int arr[], int size);
void traverseArray(int arr[], int size);
void insertArray(int arr[], int size, int pos, int item);

int main(){
    int choice, N, arr[N];
    printf("Welcome to the menu driven program,\nYou have to enter array to get started\n");
    printf("\nEnter the Size of array: ");
    scanf("%d", &N);
    
    getArray(arr, N);

    do{
        int pos, item;
        printf("Enter 1 for traversing the array, 2 for Insertion\nEnter 0 to exit the program\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 :
            traverseArray(arr, N);
            break;
        case 2 :

            printf("\nEnter the position where you want insert element: ");
            scanf("%d %d", &pos, &item);
            insertArray(arr, N, pos, item);
            break;
        case 0 : 
            printf("Thank you for using the program."); 
            break;    

        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}

void getArray(int arr[], int size){
    printf("\nEnter the elements of an array: ");
    for(int i=0; i<size; i++){
       scanf("%d", &arr[i]);
    }
}

void traverseArray(int arr[], int size){
    printf("\nThe elements of the array: ");
    for(int i=0; i<size; i++){
       printf("%d\t", arr[i]);
    }
}
void insertArray(int arr[], int size, int pos, int item){
    
    
     
}