#include <stdio.h>
#include <stdlib.h>

struct data {
    double value[110];
    int i;
    double timestamp;
} message;

int main()
{
    int n = 0;
    struct data message;
    FILE * fileptr;

    if ((fileptr = fopen("/home/brendal4/Documents/misc/newfile.bin", "rb")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    while (fread(&message, sizeof(struct data), 1, fileptr)) { 
        int n_plus_5 = n;
        printf("Packet number: %d\tTimestamp: %f\n", message.i, message.timestamp);
        for (n; n<n_plus_5+5; ++n) {
            printf("Value %d: %lf\n", n, message.value[n]);
        }
    }
    fclose(fileptr); 
    
    return 0;
}