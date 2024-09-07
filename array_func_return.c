// C Program to return array from a function
#include <stdio.h>

// function
int* func()
{
    static int arr[5] = { 1, 2, 3, 4, 5 };
    //Using static in the function ensures that the array persists after the function returns. 
    //Without static, the array would be a local variable, and its memory would be deallocated once the 
    //function exits, leading to undefined behavior when accessed later.
    return arr;
}

// driver code
int main()
{

    int* ptr = func();

    printf("Array Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr++);
    }
    printf("\nThe address of Array Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%u ", ptr++);
    }
    return 0;
}

// Why static is Required ??
// In your code, the function func returns a pointer to an array. However, local variables inside functions 
// have automatic storage duration, meaning they only exist while the function is executing. If you return a 
// pointer to a local array, that array will be destroyed once the function exits, leaving the pointer to an 
// invalid memory location.

// Using static storage duration ensures that the array retains its value even after the function exits. 
// This way, the pointer returned by func will still point to a valid memory location when accessed in main.
