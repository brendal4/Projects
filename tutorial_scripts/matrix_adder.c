#include <stdio.h>

/*
NOTE: For this, you HAVE to tell the i and j to be 0 in each for loop in order to reset it to 0 for future looping.
Otherwise, it'll store whatever value it made it to for the remainder of the program.
*/


int main()
{
    int array1[10][10], array2[10][10], new_array[10][10], i, j, n;

    //User building array1:
    printf("Enter size, n, of the matrices (nxn) up to 10: ");
    scanf("%d", &n);
    printf("Okay, n = %d\n", n);
    printf("Enter elements of matrix 1\n");
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            printf("Element %d%d is: ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }
    printf("Done with matrix 1\n");

    //User building array2:
    printf("Enter elements of matrix 2: \n");
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            printf("Element %d%d is: ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }
    printf("Done with matrix 2\n");
    
    //The elements of the summed matrix:
    printf("Elements of summed matrix are: \n");
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            new_array[i][j] = array1[i][j] + array2[i][j];
            printf("Element %d%d is: %d\n", i, j, new_array[i][j]);
        }
    }
}
