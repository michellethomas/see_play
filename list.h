struct list_node{
    int val;
    list_node* next;
}

struct list{
    list_node* head;
    list_node* tail;
}

typedef struct list_node * list_node;
typedef struct list * list;


void add(int val, list* l){
    list_node retVal = malloc(sizeof(list_node));
    retVal->val = val;
    if (l->head == NULL){
        l->head = retVal;
        l->tail = retVal;
        retVal->next = NULL;
    }
    else{
        list_node* last;
        last = l->head;
        l->head = retVal;
        retVal->next = last;
    }
}


