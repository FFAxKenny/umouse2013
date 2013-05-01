#ifndef QUEUE_H
#define QUEUE_H
#include "cell.h"

#define MAX_ELEMENT 400

typedef struct{
    Cell * element[MAX_ELEMENT];
    int tail;
    int head;
} Queue;

void q_push(Queue * q, Cell * cellptr);
Cell * q_pop(Queue * q);
#endif
