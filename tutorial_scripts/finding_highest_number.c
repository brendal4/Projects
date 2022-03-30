#include <stdio.h>

int main()
{
    double array[10];
    int n, highest_num = array[0];

    printf("Enter number of elements (up to 10): ");
    scanf("%d", &n);

    printf("Enter your numbers: ");
    for (int i=0; i<n; ++i) {
        scanf("%lf", &array[i]);
        if (array[i] > highest_num) {
            highest_num = array[i];
        }
    }
    printf("Highest value is: %d", highest_num);   
}
