#include <stdio.h.>
#include <math.h>

int main()
{
    int  a, b, c;
    float equation, x_pos_root, x_neg_root, square_rt, root;
    float x_root_real, x_root_imag;
    // equation = a*x*x + b*x + c;
    printf("Quadratic equations have the form: ax^2 + bx + c = 0\n");
    printf("...where a, b, and c are constants.\n");
    printf("Enter constants a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    root = b*b - 4*a*c;

    // CURRENT BUG: If imaginary root, it can't get the real part right

    if(root<0) {
        printf("We're in the if...\n");
        root = root*-1;
        square_rt = sqrt(root);
        x_root_real = -b / (2 * a);
        x_root_imag = square_rt/(2*a);
        printf("Positive root is: %f + %fi", x_root_real, x_root_imag);
        printf("\nNegative root is: %f - %fi", x_root_real, x_root_imag);

    }
    else {
        printf("We're in the else...\n");
        printf("a = %i\n", a);
        printf("b = %i\n", b);
        printf("c = %i\n", c);
        square_rt = sqrt(root);
        x_pos_root = (-b + square_rt)/(2*a);
        x_neg_root = (-b - square_rt)/(2*a);
        printf("Postive root is: %f", x_pos_root);
        printf("\nNegative root is: %f", x_neg_root);
    }
}
