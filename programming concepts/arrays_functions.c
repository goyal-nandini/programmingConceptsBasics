// C Program to pass an array to a function
#include <stdio.h>

void printArray(int arr[])
{
    printf("Size of Array in Functions: %d\n", sizeof(arr));
    printf("Array Elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ",arr[i]);
    }
}
// driver code
int main()
{
    int arr[5];
    int *ptr = &arr[0];
    printf("Enter the elements of array:\n");
    for(int i=0; i<5; i++){
        scanf("%d",ptr+i);
    }
    printf("Size of Array in main(): %d\n", sizeof(arr));
    printArray(arr); // we have to write name of the array while calling function and passing array
    return 0;
}
// important learning:
//The size of arrays in a function and the main function can differ because of how they are passed and 
//stored in memory.
//sizeof(arr) in main() will return the total memory allocated for the array. So, it will be 5 * 4 = 20 bytes 
//(assuming int is 4 bytes on your system).
//sizeof(arr) in the printArray() function will return the size of the pointer, not the size of the array. 
//On most systems, the size of a pointer is 8 bytes (for 64-bit systems) or 4 bytes (for 32-bit systems).

