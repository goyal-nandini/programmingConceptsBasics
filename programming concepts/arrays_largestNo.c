// to find the largest number in an array
#include<stdio.h>
int findLargest(int *arr){
    int max = arr[0];
     for(int i=0; i<5; i++){
        if(max < arr[i])
        max = arr[i];
     }
     return max;
}
int main(){
     int arr[5];
     int *ptr = &arr[0];
     printf("Enter the elements: ");
     for(int i=0; i<5; i++){
        scanf("%d",ptr+i);
     }
     printf("The elements of array is: ");
     for(int i=0; i<5; i++){
        printf("%d ",*ptr++);
     }
     printf("\nThe largest number is: ");
     printf("%d", findLargest(arr));
}