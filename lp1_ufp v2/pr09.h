#ifndef pr09_h
#define pr09_h

#include <stdio.h>
#include <stdlib.h>

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

/**
* Allocates memory and reads from the stdin size circles
* @param cpts - CIRCLE pointer in whitch the circles will be stored. Starts as NULL
* @param size - number of circles to read from the stdin
* @return - pointer to the first position of the inserted array of circles
*/
CIRCLE * read_dyn_array_circles (CIRCLE * cpts, int size);

/**
* Finds the circle with the greatest perimiter in a given set of circles
* @param cpts - pointer to the first position of the circle array
* @param size - number of circles pointed by cpts
* @return - circle with the greatest perimiter
*/
CIRCLE find_circle_greatest_perimiter (CIRCLE * cpts, int size);

/**
* Allocates memory and inits a rectangle queue
* @return - pointer to the created RECT_QUEUE
*/
RECT_QUEUE * create_rect_queue ();

/**
* Allocates memory and inits a rectangle queue node
* @param downpt - rectangle's downpt
* @param uppt - rectangle's uppt
* @return pointer to the created queue node
*/
RECT_QUEUE_NODE * create_rect_queue_node (POINT downpt, POINT uppt);

/**
* Adds a rectangle node to the rectangles queue (FIFO)
* Enqueue at tail
* @param rect_queue queue of rectangles
* @param downpt - rectangle's down point
* @param uppt - rectangle's up point
*/
void enqueue_rectangle (RECT_QUEUE * rect_queue, POINT downpt, POINT uppt);

/**
* Removes a rectangle node from the rectangles queue (FIFO)
* Dequeue at head
* @param rect_queue queue of rectangles
* @return removed rectangle queue node
*/
RECT_QUEUE_NODE * dequeue_rectangle (RECT_QUEUE * rect_queue);

/**
* prints a given rectangle queue
* @param rqu - rectangle queue to be printed
*/
void print_rect_queue (RECT_QUEUE * rqu);

/**
* Dequeus and prints the area of each rectangle node in a given rectangle queue
* @param rqu - rectangle queue
*/
void get_rect_queue_node_area (RECT_QUEUE * rqu);

#endif /* pr09_h */