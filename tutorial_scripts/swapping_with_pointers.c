#include <stdio.h>

void swapper(int* p1, int* p2, int* p3)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = *p3;
    *p3 = temp;
}

int main()
{
    int a, b, c;

    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    swapper(&a, &b, &c);

    printf("a = %d, b = %d, c = %d", a, b, c);
}