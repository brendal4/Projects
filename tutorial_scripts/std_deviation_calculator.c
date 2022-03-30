#include <stdio.h>
#include <math.h>

float std_dev(float array[])
{
    float average, sum = 0.0, deviations_sum = 0.0, variance = 0.0, deviation = 0.0, ith_deviation = 0.0;
    
    //Finding average:
    for (int i = 0; i < 8; ++i) {
        printf("Element %d is: %f\n", i, array[i]);
        sum += array[i];
    }
    average = sum/8;

    printf("Sum = %f\n", sum);
    printf("Average = %f", average);

    //Calculating deviations:
    for (int i=0; i<8; ++i) {
        ith_deviation = (array[i] - average) * (array[i] - average);
        //printf("\nDeviation for element %d is: %f", i, deviations[i]);
        deviations_sum += ith_deviation;
    }
    variance = deviations_sum/8;
    deviation = sqrt(variance);
    return deviation;
}

int main() 
{
    float result, values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    result = std_dev(values);
    printf("\nStandard deviation is: %f", result);
}