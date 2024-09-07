// from here a series of mine, dsa topics from scratch for semester 
//in C programming language
// C Program to illustrate strings
#include <stdio.h>

int main()
{

    // creating array of character
    char arr[6] = { 'G', 'e', 'e', 'k', 's', '\0' };

    // printing string
    int i = 0;
    while (arr[i]) {
        printf("%c", arr[i++]);
    }
    printf("\n By The new way is: ");
    // for(int j=0; j!='\0'; j++){
    //     printf("%c", arr[j]);
    // }
    // The condition j != '\0' is incorrect for traversing a character array.
    // The variable j is an integer and will never be equal to the null character '\0'.
    // Instead, you should check the value of the array element at index j to see if it is the null character.
    for(int j=0; arr[j] != '\0'; j++){
         printf("%c", arr[j]);
    }
    return 0;
}
