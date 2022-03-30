#include <stdio.h>

void phrase_flipper()
{
    char c;
    scanf("%c", &c);
    if(c != '\n') {
        phrase_flipper();
        printf("%c", c);
    }
}

int main()
{
    printf("Enter a phrase: ");
    phrase_flipper();
}