#include <stdio.h>

int main()
{
    int numbers[5];
    double average, sum = 0;
    
    printf("Enter 5 numbers to be averaged: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
        printf("Element %d is: %d\n", i, numbers[i]);
        sum += numbers[i];
    }
    average = sum/5;

    printf("Sum = %d\n", sum);
    printf("Average = %lf", average);
}

// To make this program better, use a function which the user can specify the amount of numbers they want to average
// i.e. the size of the array.
