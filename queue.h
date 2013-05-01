#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include "cell.h"

#define MAX_ELEMENT 400

typedef struct{
    Cell * element[MAX_ELEMENT];
    int tail;
    int head;
} Queue;

void init_queue(Queue * queue);
void q_push(Queue * q, Cell * cellptr);
Cell * q_pop(Queue * q);
bool is_empty(Queue * q);
#endif

