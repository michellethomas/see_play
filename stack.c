#include <stdlib.h>
#include <stdio.h>
/*
typedef struct{
  int* vals;
  int dimension;
  int top;
} Stack;
*/

// FIXME DCC -- Does this work?
struct Stack {
  int* vals;
  int top;
  int dimension;
};

typedef struct Stack * Stack;
// END DCC

Stack new_Stack(int dim){
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

int canPop_Stack(Stack stack) {
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

int main (void){
  int i;
  int x;
  int p;
  Stack stack = new_Stack(10);
  for(i=0; i<10;i++){
    push_stack(stack, i);
  }
  for(x=0; x<11;x++){
    if(canPop_Stack(stack)== 1) {
      p = pop_stack(stack);
      printf("Popped %d \n", p);
    } else {
      printf( "YOU CAN NOT POP" );
    }
  }
  return 0;
}





