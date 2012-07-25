#include <stdio.h>
#include <wctype.h>

FILE *file_to_read = NULL;
file_to_read = fopen("test.txt","r");
int size = sizeof(file_to_read)/sizeof(char);
char c[255];
int count = 0;

for (i = 0; i<=size; i++){
  c = fgetc(file_to_read);
  count++;
  printf(c,count);
}
