#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stack.h>

void calc(char* operand, Stack stack){
  int one = NULL;
  int two = NULL;
  if (can_pop_stack){
    two = pop_stack(stack);
    one = pop_stack(stack);
  }
  else{
    printf("your stack is full");
    return;
  }
  int three;
  if (strcmp(operand,"+")==0){
    three = one + two;
    printf("Answer = %d\n", three);
    push_stack(stack, three);
  }
  else if (strcmp(operand,"-")==0){
    three = one - two;
    printf("Answer = %d\n", three);
    push_stack(stack, three);
  }
  else if (strcmp(operand,"x")==0){
    three = one * two;
    printf("Answer = %d\n", three);
    push_stack(stack, three);
  }
  else{
    three = one / two;
    printf("Answer = %d\n", three);
    push_stack(stack, three);
  }
  return;
}

int main(int argc, char **argv) {
  int i;
  int x;
  int p;
  Stack stack = new_stack(argc);
  if(strcmp(argv[1],"-v") ==0){
      v = verbose(v);
  }
  for(i=0; i < argc; i++){
    if(argv[i] == NULL){
      printf("you have no args %d", i);
      break;
    }
    else if(isdigit(argv[i][0])){
      p = atoi(argv[i]);
      push_stack(stack, p);
    }
    else if(strcmp(argv[i],"+")==0 || strcmp(argv[i],"-")==0 || strcmp(argv[i],"x")==0 || strcmp(argv[i],"/")==0){
      char* arg = argv[i];
      calc(arg, stack);
    }
  }
}

