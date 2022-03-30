#include <stdio.h>
#include <string.h>

int main()
{
    char c, string[50];
    int size, frequency = 0;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    printf("Your string is: ");
    puts(string);

    printf("Enter a character to scan your string for: ");
    scanf("%c", &c);

    for (int i=0; i<100; ++i) {
        if (string[i] == c) {
            frequency += 1;
        }
        else if (string[i] == '\0') {
            break;
        }
        else {
            continue;
        }
    }
    if (frequency != 0) {
        printf("'%c' appears %d times.", c, frequency);
    }
    else {
        printf("'%c' does not appear in your expression.", c);
    }

}
