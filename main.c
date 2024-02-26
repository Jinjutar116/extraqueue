#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"

#include "Queue.h"

int main(int argc , char **argv) {
  Queue  q;
  main_init(&q);
  int i,x; 

  for(i = 1; i < argc; i++){
    if(strcmp(argv[i], "x") == 0) {
      if(q.size != 0) {
        x = dequeue_struct(&q);
        printf("dequeing %d\n", x);
      }
      else dequeue_struct(&q);
    }
    else {
      enqueue_struct(&q, atoi(argv[i]));
    }
  }
  return 0;
}
