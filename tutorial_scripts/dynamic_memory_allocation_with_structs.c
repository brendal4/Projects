#include <stdio.h>
#include <stdlib.h>
struct student {
   int age;
   float grade;
   char name[30];
};

int main()
{
   struct student *ptr;
   int i, noOfRecords;

   printf("Enter the number of records: ");
   scanf("%d", &noOfRecords);

   // allocating memory for n numbers of struct student
   ptr = (struct student*) malloc(noOfRecords * sizeof(struct student));

   for(i = 0; i < noOfRecords; ++i)
   {
       printf("Enter first name of student: ");
       scanf("%s", (ptr+i)->name);
       printf("Enter age of student: ");
       scanf("%d", &(ptr+i)->age);
       printf("Enter grade: ");
       scanf("%f", &(ptr+i)->grade);
   }

   printf("Displaying Information:\n");
   for(i = 0; i < noOfRecords; ++i)
       printf("Name: %s\tAge: %d\tGrade: %f\n", (ptr+i)->name, (ptr+i)->age, (ptr+i)->grade);

   return 0;
}
