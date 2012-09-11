#define _GNU_SOURCE
#include <stdlib.h>
#include <list.h>
#include <stdio.h>
#include <string.h>

void file_to_read(char* file_name, List list){
  char buffer[256];
  int i = 0;
  char* buffer_str;
  int num = 0;
  FILE *file_to_read = fopen(file_name,"r");
  if (file_to_read == NULL){
    printf("You tried to open %s, which doesn't exist", file_name);
    exit(1);
  } 
  while(fgets(buffer, 256, file_to_read) != NULL){
    buffer_str = strtok(buffer, " ");
    if(strcmp(buffer_str, "push")==0){
      buffer_str = strtok(NULL, " ");
      num = atol(buffer_str);
      push(num, list);
    }
    else if(strcmp(buffer_str, "enqueue")==0){
      buffer_str = strtok(NULL, " ");
      num = atol(buffer_str);
      enqueue(num, list);
    }
    else if(strcmp(buffer_str, "pop")==0){
      pop(list);
    }
    else if(strcmp(buffer_str, "dequeue")==0){
      dequeue(list);
    }
  }
}

int main(int argc, char **argv){
  List list = new_list();
  if (argv[1] == NULL){
    printf("You need to give the name of your file");
  }
  else{
    file_to_read(argv[1], list);
  }
  push(1, list); 
  push(2, list);
  enqueue(3, list);
  dequeue(list);
  traverse_list(list);
}

