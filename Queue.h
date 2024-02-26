
/*
typedef struct {
	NodePtr headPtr,tailPtr;
	int size;
} Queue;
*/
void payment(int , int);

typedef struct {
  orderPtr headPtr, tailPtr;
  int size;
} Queue;

void main_init(Queue *q){
  q->headPtr = NULL;
  q->tailPtr = NULL;
  q->size = 0;
}

void enqueue_struct(Queue* q, int x, int y){
  orderPtr new_node = (orderPtr)malloc(sizeof(order));
  if(new_node){ 
    new_node->order_number = x;
    new_node->q = y;
    new_node->nextPtr = NULL;
    if(q->size == 0) q->headPtr = new_node;
    else q->tailPtr->nextPtr = new_node;
    q->tailPtr = new_node;
    q->size++;
  }
  else printf("No space left.");
}


void dequeue_struct(Queue *q){
  orderPtr t = q->headPtr;
  if(t){
    int orderNum = t->order_number;
    int quantity = t->q;
    q->headPtr = t->nextPtr;
    if(q->size == 1) q->tailPtr = NULL;
    q->size--;
    free(t);
    payment(orderNum, quantity);
  }
  else printf("Empty queue\n");
}

void payment(int order_number, int quantity){
  int price;
  switch(order_number){
    case 1: 
      printf("Ramen"); 
      price = 100;
      break;
    case 2: 
      printf("Somtum"); 
      price = 20;
      break;
    case 3: 
      printf("Fried Chicken"); 
      price = 50;
      break;
  }
  int total = price*quantity;
  int pay;
  printf("\nYou have to pay %d\n", total);
  printf(":Cash:");
  scanf("%d", &pay);
  while(pay<total){
    printf("Cash:");
    scanf("%d", &pay);
  }
  printf("Thank you\n");
  if(pay>total) printf("Change is:%d\n",pay-total);
}