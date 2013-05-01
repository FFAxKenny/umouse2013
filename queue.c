// A looped array queue
#include "queue.h"

void q_push(Queue * q, Cell * cellptr) {
    q->tail++;
    if (q->tail >= MAX_ELEMENT) q->tail = 0;
    q->element[q->tail] = cellptr;
}

Cell * q_pop(Queue * q) {
    Cell * result = q->element[q->head];
    q->head++;
    if (q->head >= MAX_ELEMENT) q->head = 0;
    return result;
}
