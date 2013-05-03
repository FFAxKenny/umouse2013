// A looped array queue
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(Queue * queue) {
    if(queue != NULL) {
        queue->head = 0;
        queue->tail = 0;
    }
}

void q_push(Queue * q, Cell * cellptr) {
    if(q != NULL && cellptr != NULL) {
        q->element[q->tail] = cellptr;
        q->tail++;
        if (q->tail >= MAX_ELEMENT) q->tail = 0;
    }
}

Cell * q_pop(Queue * q) {
    if(q != NULL) {
        Cell * result = q->element[q->head];
        q->head++;
        if (q->head >= MAX_ELEMENT) q->head = 0;
        return result;
    }
    else return NULL;
}

bool is_empty(Queue * q){
    if(q != NULL) {
        if(q->head == q->tail) return true;
        else return false;
    }
    else return true;
}

