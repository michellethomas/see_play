#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
typedef struct{
  int* vals;
  int dimension;
  int top;
} Stack;
*/

int verbose(int n){
  return n;
}

struct Stack {
  int* vals;
  int top;
  int dimension;
};

typedef struct Stack * Stack;

Stack new_stack(int dim){
  Stack retVal = malloc(sizeof(Stack));
  if (retVal == NULL){
    printf("Your Stack has not been defined"); //Do something here
    return NULL;
  }
  retVal->dimension = dim;
  retVal->vals = malloc(sizeof dim);
  retVal->top = -1;
  if (retVal->dimension ==NULL || retVal->vals ==NULL){
    printf("Your demension and values have not been defined"); //Do something here
  }
  return retVal;
}

void free_stack (Stack stack){
  if( stack == NULL ) {
    // return
  }
  else if(stack!= NULL){
    free(stack);
  }

  if (stack->vals != NULL){
    free(stack->vals);
  }
}

void push_stack (Stack stack, int pushVal){
  if(stack->top < stack->dimension){
    stack->top=stack->top+1;
    stack->vals[stack->top] = pushVal;
    printf("Pushed %d \n", pushVal);
  }
  else{
    printf("You pushed too many items onto the stack\n");
  }
  return;
}

int can_pop_stack(Stack stack) {
  if (stack->top >= 0){
    return 1;
  }
  else{
    return 0;
  }
}

int pop_stack (Stack stack){
  if(stack->top < 0){
    printf("You popped too many items off of the stack\n");
    return;
  }
  else{
    int poppedVal = stack->vals[stack->top];
    stack->top = stack->top-1;
    return poppedVal;
  }
}

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
    printf("calc %d", three);
    push_stack(stack, three);
  }
  else if (strcmp(operand,"-")==0){
    three = one - two;
    printf("calc %d", three);
    push_stack(stack, three);
  }
  else if (strcmp(operand,"x")==0){
    three = one * two;
    printf("calc %d", three);
    push_stack(stack, three);
  }
  else{
    three = one / two;
    printf("calc %d", three);
    push_stack(stack, three);
  }
  return;
}

int main(int argc, char **argv) {
  int i;
  int x;
  int p;
  Stack stack = new_stack(argc);
  for(i=0; i <= argc; i++){
    if(argv[i] == NULL){
      printf("you have no args %d", i);
      break;
    }
    else if(isdigit(argv[i][0])){
      p = atoi(argv[i]);
      printf("arg %d\n", p);
      push_stack(stack, p);
    }
    else if(strcmp(argv[i],"+")==0 || strcmp(argv[i],"-")==0 || strcmp(argv[i],"x")==0 || strcmp(argv[i],"/")==0){
      printf("arg %s\n", argv[i]);
      char* arg = argv[i];
      calc(arg, stack);
    }
    else{
      printf("args %s", argv[i]);
    }
  }
}





