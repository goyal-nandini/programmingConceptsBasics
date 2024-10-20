// Design and implement a menu-driven program to perform essential matrix 
// operations, including addition, subtraction, multiplication, and transpose for two 
// matrices. The program should facilitate the input of matrices and selection of the 
// desired operation.

#include <stdio.h>

int i, j, r1, c1, r2, c2;
void printMatrix(int r, int c, int mat[r][c]);
void displayMatrix(int r, int c, int mat[r][c]);
void addMatrix(int r, int c, int mat[r][c], int mat1[r][c], int mat2[r][c]);
void subMatrix(int r, int c, int mat[r][c], int mat1[r][c], int mat2[r][c]);
void transposeMatrix(int r, int c, int matT[r][c], int mat[r][c]); 
void productMatrix(int r, int c, int mat[r][c], int mat1[r][c], int mat2[r][c]);

int main()
{
    int choice;
    char restart;
    printf("Welcome to menu driven program!\nYou have to enter two matrices to get started.");
    do{
        printf("\nEnter the size of the first matrix(row*column): ");
        scanf("%d%d", &r1, &c1);
        int mat1[r1][c1];
        printf("Enter the elements of the first matrix: ");
        printMatrix(r1, c1, mat1);

        printf("\nEnter the size of the second matrix(row*column): ");
        scanf("%d%d", &r2, &c2);
        int mat2[r2][c2];
        printf("Enter the elements of the second matrix: ");
        printMatrix(r2, c2, mat2); 

        printf("\nThe first matrix is:\n");
        displayMatrix(r1, c1, mat1);

        printf("The second matrix is:\n");
        displayMatrix(r2, c2, mat2);

        printf("\nInstructions:\nPress 1 for adding the matrices,\n2 for subtracting,\n3 for displaying the transpose of matrices,\n4 for multiplying two matrices and\n0 to exit the program.");
  
        do
        {
            printf("\n-----------------------------");
            printf("\nEnter choice: ");
            scanf("%d", &choice);
            int matAdd[r1][c1], matSub[r1][c1], mat1T[r1][c1], mat2T[r2][c2], matMult[r1][c2];
            switch (choice)
            {
            case 1:
                if (r1 == r2 && c1 == c2)
                {
                    printf("\nAdding the two matrix.....");
                    addMatrix(r1, c1, matAdd, mat1, mat2);
                    printf("\nBoth matrix added successfully!\n");
                    printf("Here is the new matrix:\n");
                    displayMatrix(r1, c1, matAdd);
                }
                else
                {
                    printf("Matrix dimensions must match for addition!");
                    continue;
                }
                break;
            case 2:
                if (r1 == r2 && c1 == c2)
                {
                    printf("\nSubtracting the two matrix.....");
                    subMatrix(r1, c1, matSub, mat1, mat2);
                    printf("\nBoth matrix subtracted successfully!\n");
                    printf("Here is the new matrix:\n");
                    displayMatrix(r1, c1, matSub);
                }
                else
                {
                    printf("Matrix dimensions must match for subtraction!");
                    continue;
                }
                break;
            case 3:
                printf("\nTranspose of the first matrix  is:\n");
                transposeMatrix(r1, c1, mat1T, mat1);
                displayMatrix(c1, r1, mat1T);

                printf("\nTranspose of the second matrix is:\n");
                transposeMatrix(r2, c2, mat2T, mat2);
                displayMatrix(c2, r2, mat2T);

                break;
            case 4:
                // [r1][c1] * [r2][c2]  multiplication c1 == r2, new matrix is [r1][c2]
                if (c1 == r2)
                {
                    printf("\nThe multiplication of the matrices is:\n");
                    productMatrix(r1, c2, matMult, mat1, mat2);
                    printf("Here is the new matrix:\n");
                    displayMatrix(r1, c2, matMult);
                }
                else
                {
                    printf("\nGiven matrices' size is not suitable for multiplication!");
                }
                break;
            case 0: 
                    printf("Exiting the program.\n");
                    break;
            default:
                printf("\nInvalid Number! Please try again.");
                break;
            }
        } while (choice != 0);
            printf("Do you want to restart the program? (Y/N): ");
            scanf(" %c", &restart);

    } while(restart == 'Y' || restart == 'y');
    printf("Thankyou for using the program!");
    return 0;
}

void printMatrix(int r, int c, int mat[r][c])
{

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
    }
}
void displayMatrix(int r, int c, int mat[r][c])
{

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}
void addMatrix(int r, int c, int mat[r][c], int mat1[r][c], int mat2[r][c])
{

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            mat[i][j] = mat1[i][j] + mat2[i][j];
    }
}
void subMatrix(int r, int c, int mat[r][c], int mat1[r][c], int mat2[r][c])
{

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            mat[i][j] = mat1[i][j] - mat2[i][j];
    }
}
void transposeMatrix(int r, int c, int matT[r][c], int mat[r][c])
{
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            matT[i][j] = mat[i][j];
    }
}
void productMatrix(int r1, int c2, int mat[r1][c2], int mat1[r1][c2], int mat2[r1][c2])
{
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            int sum = 0;
            for (int k = 0; k < c1; k++)
            {
                sum = sum + mat1[i][k] * mat2[k][j];
                mat[i][j] = sum;
            }
        }
    }
}