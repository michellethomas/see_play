typedef struct list_node_1 * List_node;
typedef struct list_1 * List;

struct list_node_1{
  int val;
  List_node* next;
};

struct list_1{
  List_node* head;
  List_node* tail;
};


void push(int val, List list){
  List_node retVal = malloc(sizeof(List_node));
  retVal->val = val;
  if (list->head == NULL){
    list->head = retVal;
    list->tail = retVal;
    retVal->next = NULL;
  }
  else{
    List_node* last = list->head;
    list->head = retVal;
    retVal->next = last;
  }
  List_node head = list->head;
  printf("Added: %d \n", retVal->val);
  printf("Front now: %d \n", head->val);
}

void enqueue(int val, List list){
  List_node retVal = malloc(sizeof(List_node));
  retVal->val = val;
  if (list->head == NULL){
    list->head = retVal;
    list->tail = retVal;
    retVal->next = NULL;
  }
  else{
    List_node last = list->tail;
    list->tail = retVal;
    last->next = list->tail;
    retVal->next = NULL;
  }
  List_node tail = list->tail;
  printf("Added: %d \n", retVal->val);
  printf("Back now: %d \n", tail->val);
}

void dequeue(List list){
  List_node remove = list->head;
  list->head = remove->next;
  free(remove);
}

void pop(List list){
  List_node remove = list->head;
  list->head = remove->next;
  free(remove);
}

List new_list(){
  List retVal = malloc(sizeof(List));
  return retVal;
}

void traverse_list(List list){
  int i = 0;
  List_node head = list->head;
  if(head==NULL){
    printf("There is nothing in this list %d \n", i);
  }
  else if(head->next == NULL){
    printf("Item: %d", head->val);
  }
  else{
    List_node current = head;
    while(current!=NULL){
      printf("%d\n", current->val);
      current = current->next;
    }
  }
}


