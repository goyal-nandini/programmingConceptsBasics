// n(size of array[no of elements] = sizeof(arr_name)/sizeof(dataType_of_array))

// C Program to the average to two numbers
#include <stdio.h>

// function to calculate average of the function
float getAverage(float* arr, int size)
// here, float *arr and float arr[] are used interchangebly
{

    int sum = 0;
    // calculating cumulative sum of all the array elements
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // returning average
    return sum / size;
}

// driver code
int main()
{

    // declaring and initializing array
    float arr[5] = { 10, 20, 30, 40, 50 };
    // size of array using sizeof operator
    int n = sizeof(arr) / sizeof(float);

    // printing array elements
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%.0f ", arr[i]);
    }

    // calling getAverage function and printing average
    printf("\nAverage: %.0f", getAverage(arr, n));
    // here, arr and &arr[0] are used interchangebly
    return 0;
}
//"%.0f" means you are formatting the floating-point number to have zero digits after the decimal point. 
//Essentially, this will round the number to the nearest integer and display it without any fractional part.
