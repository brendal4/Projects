#include <stdio.h>

struct american_sys {
  int feet;
  float inch;
} measurement1, measurement2, result;

int main()
{
    printf("Enter first measurement: ");
    scanf("%d %f", &measurement1.feet, &measurement1.inch);
    printf("Enter second measurement: ");
    scanf("%d %f", &measurement2.feet, &measurement2.inch);

    printf("First measurement: %d feet %f inches\n", measurement1.feet, measurement1.inch);
    printf("Second measurement: %d feet %f inches\n", measurement2.feet, measurement2.inch);

    result.feet = measurement1.feet + measurement2.feet;
    result.inch = measurement1.inch + measurement2.inch;

    while (result.inch >= 12) {
      ++result.feet;
      result.inch -= 12.0;
    }
    printf("Resulting measurement is: %d feet %f inches", result.feet, result.inch);
}