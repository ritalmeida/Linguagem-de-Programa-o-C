//
//  pr09.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 19/11/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr09.h"

/**
* reads a predefined number of points from stdin
@param apts - pointer to the first position of the points array
@param size - number of points to read
*/
void read_array_points (POINT * apts, int size){
    
    for (int i = 0; i < size; i++) {
        
        scanf("%d %d ", &(apts[i].x), &(apts[i].y));
        //ou (apts+i)->x, (apts+i)->y;
    }
}

/**
* prints an array of points
@param apts - array of points to be printed
@param size - size of the point array
*/
void print_array_points (POINT * apts, int size){
    
    for (int i= 0; i < size; i++) {
        
        printf("%d %d ", (*(apts+i)).x, apts[i].x);
    }
}

/**
* translates all the given points by a given delta
@param ppts - array of points to be translated
@param size - number of points in ppts
@param delta - shift to be applied to each of the points in ppts
* i.e. input: (((1, 1) (2, 2), (3, 3)), 3, (1, 2)); output: ((2, 3), (3, 4), (4, 5))
*/
void translation_dyn_array_points (POINT * ppts, int size, POINT delta){    //feito
    
    for (int i = 0; i < size; i++) {
        
        (*(ppts+i)).x += delta.x;
        (ppts+i)->y += delta.y;
    }
}

/**
* allocates memory and reads from the stdin size circles
@param cpts - CIRCLE pointer. Starts as NULL
@param size - number of circles to read from the stdin
@return - pointer to the first position of the inserted circles
*/
CIRCLE * read_dyn_array_circles (CIRCLE * cpts, int size){          //feito
    
    cpts = (CIRCLE *) calloc(size, sizeof(CIRCLE));
    CIRCLE *c = cpts;
    for (int i = 0; i < size; i++) {
        
        scanf("%d %d %d", &c->p.x, &c->p.y, &c->radius);
        c++;
    }
    return cpts;
}

/**
* finds the circle with the greatest area in a given set of circles
@param cpts - pointer to the first position of the circle array
@param size - number of circles pointed by cpts
@return - circle with the greatest area
*/
CIRCLE find_circle_greatest_area (CIRCLE * cpts, int size);

/**
* finds the circle with the greatest perimiter in a given set of circles
@param cpts - pointer to the first position of the circle array
@param size - number of circles pointed by cpts
@return - circle with the greatest perimiter
*/
CIRCLE find_circle_greatest_perimiter (CIRCLE * cpts, int size);

int main_pr09(int argc, const char * argv[]);
