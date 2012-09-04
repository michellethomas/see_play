#define _GNU_SOURCE
#include <stdlib.h>
#include <list.h>
#include <stdio.h>

void file_to_read(char* file_name, List list){
  char line[20];
  int i = 0;
  FILE *file_to_read = fopen(file_name,"r");
  if (file_to_read == NULL){
    printf("You tried to open %s, which doesn't exist", file_name);
    exit(1);
  } 
  while(fgets(line, 20, file_to_read) != NULL){
    for(i=0; i<=sizeof(line); i++){
      printf("%c", line[i]);
    }
  }
  //fscanf(file_to_read, "%s %d", operation, value);
}

int main(int argc, char **argv){
  List list;
  if (argv[1] == NULL){
    printf("You need to give the name of your file");
  }
  else{
    file_to_read(argv[1], list);
  }
  list = new_list();
  push(1, list); 
  push(2, list);
  enqueue(3, list);
  dequeue(list);
  traverse_list(list);
}

