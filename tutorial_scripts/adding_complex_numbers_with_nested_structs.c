#include <stdio.h>

struct complex {
    int imag;
    int real;
};

struct number {
    struct complex comp;
    int integers;
}   num1, num2, num3;

void complex_adder(struct number z1, struct number z2)
{
    printf("z1 = %d + %di\n", z1.comp.real, z1.comp.imag);
    printf("z2 = %d + %di\n", z2.comp.real, z2.comp.imag);

    num3.comp.real = z1.comp.real + z2.comp.real;
    num3.comp.imag = z1.comp.imag + z2.comp.imag;

    printf("z3 = %d + %di", num3.comp.real, num3.comp.imag);
}

int main()
{
    printf("Enter 1st complex number:\n");
    printf("Real part: ");
    scanf("%d", &num1.comp.real);
    printf("Imaginary part: ");
    scanf("%d", &num1.comp.imag);

    printf("Enter 2nd complex number:\n");
    printf("Real part: ");
    scanf("%d", &num2.comp.real);
    printf("Imaginary part: ");
    scanf("%d", &num2.comp.imag);

    complex_adder(num1, num2);
}