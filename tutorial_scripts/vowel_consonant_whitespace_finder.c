#include <stdio.h>
#include <string.h>

int main()
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char consonants[] = "bcdfghjklmnpqrstvwxyz";
    char your_string[100];
    int num_vowels = 0, num_consonants = 0, num_digits = 0, num_whitespace = 0;

    printf("Enter a string: ");
    fgets(your_string, sizeof(your_string), stdin);
    
    //convert string to lowercase
    strlwr(your_string);

    for (int i=0; i<100; ++i) {
        for (int j=0; j<5; ++j) {
            if (your_string[i] == vowels[j]) {
                printf("Vowel found: %c\n", vowels[j]);
                num_vowels += 1;
            }
        }
        for (int k=0; k<21; ++k) {
            if (your_string[i] == consonants[k]) {
                printf("Consonant found: %c\n", consonants[k]);
                num_consonants += 1;
            }
        }
        if (your_string[i] == ' ') {
            num_whitespace += 1;
        }
        if (your_string[i] == '\0') {
            break;
        }
    }
    printf("Number of vowels found: %d\n", num_vowels);
    printf("Number of consonants found: %d\n", num_consonants);
    printf("Number of whitespaces: %d\n", num_whitespace);
    //printf("Number of digits found: %d", num_digits);
}
