#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  Queue  q;
  main_init(&q);
  int i = 1, x = 1; 

  while(i < argc){
    if(strcmp(argv[i], "x") == 0) {
      if(q.size != 0) {
        printf("Customer no: %d\n", x++);
        dequeue_struct(&q);
      }
      else dequeue_struct(&q);
      i++;
    }
    else {
      printf("My order is %d\n", atoi(argv[i]));
      enqueue_struct(&q, atoi(argv[i]), atoi(argv[i+1]));
      i+=2;
    }
  }
  printf("=================================================\n");
  if(q.size != 0){
    printf("  There are %d ppl left in queue\n", q.size);
  }
  return 0;
}
