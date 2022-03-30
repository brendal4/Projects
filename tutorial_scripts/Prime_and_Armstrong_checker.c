#include <stdio.h>

void check_prime(int integer)
{
    int i, flag = 0;

    // 0 and 1 are not prime numbers    
    if (integer == 0 || integer == 1)
        flag = 1;

    for(i = 2; i <= integer/2; ++i) {
        if(integer%i == 0) {
        flag = 1;
        break;
    }
  }

    if (flag == 1)
        printf("%d is not a prime number.", integer);
    else
        printf("%d is a prime number.", integer);
}

void Armstrong_checker(int integer)
{
    
}

int main()
{
    int integer;
    printf("Enter an integer: ");
    scanf("%d", &integer);
    check_prime(integer);
}
