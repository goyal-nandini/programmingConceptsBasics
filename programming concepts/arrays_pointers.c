#include<stdio.h>
#define N 6
int main(){
    // int arr[5] = {12, 20, 30, 40, 50};
    int arr[N];
    int *ptr = &arr[0];
    printf("Enter the elements of an array:\n");
    for(int i=0; i<N; i++){
       scanf("%d", ptr+i);
    }

    printf("address stored in arr %p(address stored in array name)\naddress stored in ptr %p(address stored in first index of the array)", arr, ptr);
    // above is very important line as "arr=&arr[0]"

    // printing array elements using pointers
    printf("\nPrinting elements of arrays using pointer:\n");
    for(int i=0; i<N; i++){
        printf("%d ", *(ptr+i));
    }
    printf("\nAnother way of writing for Printing elements of arrays using pointer:\n");
    for(int i=0; i<N; i++){
        printf("%d ", *ptr++);
    }
    return 0;
}