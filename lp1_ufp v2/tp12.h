//
//  tp12.h
//  lp1_ufp
//
//  Created by Rui on 31/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef tp12_h
#define tp12_h

#include <stdio.h>
#include "pr09.h"


typedef struct dynarrayrects
{
    RECTANGLE *prects;
    int size;
} DYNARRAYRECTS;

/** Create a dynamic array of RECTANGLE with given number of available positions */
void create_dyn_array_rects(DYNARRAYRECTS *pdar, int numberOfRectangles);

/** Print a RECTANGLE */
void print_rectangle(int i, RECTANGLE r);

/** Print the content of the dynamic array of RECTANGLE */
void print_dyn_array_rects(DYNARRAYRECTS dar);

/** Compare two RECTANGE; returns 0 if the two rectangles have the same coordinates */
int rectanle_compare(RECTANGLE r1, RECTANGLE r2);

/**
 * Insert a RECTANGLE into the fisrt available position of the dynamic array:
 * @param pdar - pointer to the dynamic  array
 * @param rect - data of RECTANGLE to insert.
 */
void insert_rect_dyn_array_rects(DYNARRAYRECTS *pdar, RECTANGLE rect);

/**
 *Read data from a file containing several RECTANGLE:
 * @param pcs - pointer to dynamic array.
 */
void read_dyn_array_rects_txt(DYNARRAYRECTS *pcs, char filename[]);

/**
 * Write content of dynamic array of RECTANGLE into a text file:
 * @param cs - copy of dynamic array.
 * @param filename - path to output text file.
 */
void save_dyn_array_rects_txt(DYNARRAYRECTS cs, char filename[]);
                                                
/**
 * Test function for class tp12.
 */
int main_tp12(int argc, const char * argv[]);


#endif /* tp12_h */
