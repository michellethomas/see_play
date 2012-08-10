struct Stack {
  int* vals;
  int top;
  int dimension;
};

typedef struct Stack * Stack;

int v = 0;
int verbose(int v){
  return 1-v;
}

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
    if(v == 1){
      printf("Pushed %d \n", pushVal);
    }
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
    if(v == 1){
      printf("Popped %d \n", poppedVal);
    }
    return poppedVal;
  }
}
