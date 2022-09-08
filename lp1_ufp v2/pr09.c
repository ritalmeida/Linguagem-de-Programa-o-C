//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "pr09.h"
#include "pr08.h"

typedef struct rectangle {
    struct point downpt, uppt;
}RECTANGLE;

typedef struct rect_queue_node {
    RECTANGLE r;
    struct rect_queue_node * pnext;
}RECT_QUEUE_NODE;

typedef struct rect_queue {
    RECT_QUEUE_NODE * phead, * ptail;
}RECT_QUEUE;

int main_pr10(int argc, const char * argv[]){

    RECT_QUEUE *rq;
    rq = create_rect_queue();

    POINT p1 = {1,1}, p2 = {2,3}, p3 = {4,2}, p4 = {5,3};
    enqueue_rectangle(rq, p1, p3);
    enqueue_rectangle(rq, p1, p4);
    enqueue_rectangle(rq, p2, p2);

    return 0;
}

/**
* Inits a rectangle queue
@return - pointer to the created RECT_QUEUE
*/
RECT_QUEUE * create_rect_queue (){

    RECT_QUEUE *rq = (RECT_QUEUE *) malloc(sizeof(RECT_QUEUE));
    rq->phead = NULL;
    rq->ptail = NULL;

    return rq;
}

/**
* Inits a rectangle queue node
@param downpt - rectangle's downpt
@param uppt - rectangle's uppt
@return pointer to the created queue node
*/
RECT_QUEUE_NODE * create_rect_queue_node (POINT downpt, POINT uppt){

    RECT_QUEUE_NODE *rqn = (RECT_QUEUE_NODE *) malloc(sizeof(RECT_QUEUE_NODE));
    rqn->r.downpt.x = downpt.x;
    rqn->r.downpt.y = downpt.y;
    rqn->r.uppt.x = uppt.x;
    rqn->r.uppt.y = uppt.y;
    rqn->pnext = NULL;
    return rqn;
}

/**
* Adds a rectangle node to the rectangles queue (FIFO)
* Enqueue at tail
@param rq queue of rectangles
@param downpt - rectangle's down point
@param uppt - rectangle's up point
*/
void enqueue_rectangle (RECT_QUEUE * rq, POINT downpt, POINT uppt){

    RECT_QUEUE_NODE *rqn = create_rect_queue_node(downpt, uppt);

    if(rq->ptail == NULL){

        rq->ptail = rq->phead = rqn;
    }
    rq->ptail->pnext = rqn;
    rq->ptail =rqn;
}

/**
* Removes a rectangle node from the rectangles queue (FIFO)
* Dequeue at head
@param rq queue of rectangles
@return removed rectangle queue node
*/
RECT_QUEUE_NODE * dequeue_rectangle (RECT_QUEUE * rq){

    if(rq->phead == NULL){

        return NULL;
    }

    RECT_QUEUE_NODE *rqn = rq->phead;
    rq->phead = rq->phead->pnext;

    if(rq->phead == NULL){

        rq->ptail = NULL;
    }
    return rqn;
}

/**
* prints a given rectangle queue
@param rqu - rectangle queue to be printed
*/
void print_rect_queue (RECT_QUEUE * rqu){


}

/**
* Dequeus and prints the area of each rectangle node in a given rectangle queue
@param rqu - rectangle queue
*/
void get_rect_queue_node_area (RECT_QUEUE * rqu){


}