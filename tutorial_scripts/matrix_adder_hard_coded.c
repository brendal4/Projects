#include <stdio.h>

int main()
{
    int array1[2][2] = {{1,2},{3,4}}, array2[2][2] = {{5,6},{7,8}};
    int new_array[2][2];

    for(int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            new_array[i][j] = array1[i][j] + array2[i][j];
            printf("Element %d%d is: %d\n", i, j, new_array[i][j]);
        }
    }
}
