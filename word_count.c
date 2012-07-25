#include <stdlib.h>
#include <stdio.h>
#include <wctype.h>

void read_file(char file_name[256], char options[255]){
  int character_count = 0;
  int whitespace_count = 1;
  int linebreak_count = 0;
  FILE *file_to_read = fopen(file_name,"r");
  if (file_to_read == NULL){
    printf("You tried to open %s, which doesn't exist", file_name);
    exit(1);
  }
  //int size = sizeof()/sizeof(char);
  int i;
  char c;
  //for (i = 0; i<=size; i++){
  while(c !=EOF){
    c = fgetc(file_to_read);
    if (c == ' ' || c == '-') {
        whitespace_count = whitespace_count +1;
    }
    else if(c == '\n'){
        linebreak_count++;
    }
    else if(isalpha(c)){
        character_count++;
    }
    else if(c == EOF){
      break;
    }
  }
  int size = sizeof(options)/sizeof(char);
  for (i = 0; i<=size; i++){
    if(options[i] == NULL){
      break;
    }
    else if(options[i] == 'w'){
      printf("%s => %d \n", file_name, whitespace_count);
    }
    else if(options[i] == 'l'){
      printf("%s => %d \n", file_name, linebreak_count);
    }
  }
  if(options[0] == 'n'){
      printf("%s => %d\t %d\t %d \n", file_name, linebreak_count, whitespace_count, character_count);
  }
}

int main(int argc, char **argv) {
  char input [256];
  char options[255];
  int i;
  for(i=0; i <= argc; i++){
    if (argv[i] == NULL){
      break;
    }
    else if (strcmp(argv[i],"-l")==0){
      options[i] = 'l';
    }
    else if (strcmp(argv[i],"-w")== 0){
      options[i] = 'w';
    }
  }
  if(argv[2] == NULL){
    options[0] = 'n';
  }
  //printf("%s", argv[2]);
  read_file(argv[1], options);
  }

