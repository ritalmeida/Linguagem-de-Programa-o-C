//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "tp09.h"

/**
 * Declare a new structure to represent Cartesian points in 2D spaces.
 *  e.g. struct pt  p1 = {1.0f, 1.0f};
 * NB 1: on pr09.h an equivalent structure is created but named struct point.
 * NB 2: instead of defining a structure it also possible to declare a new type PT with:
 *  typedef struct { int x, y; } PT;
 */
struct pt {
    float x, y;
};
//typedef struct { float x, y; } PT;

/**
 * Declare a new data type to represent rectangles (contains two fields: down and up points).
 *  e.g. RECT r1 = { {0.0f, 0.0f}, {1.0f, 1.0f} }
 */
typedef struct rect {
    struct pt downpt, uppt;
}RECT;

int main_tp09(int argc, const char * argv[]){

    /*struct pt p1={1,1}, p2={2,2},p3;
    p3=p1;
    PT p4={5,5};
    printf("p1=(%d,%d)\n",p1.x,p1.y);
    scanf("%d%d",&p1.x,&p1.y);
    // if(p3==p1) -> não funciona
    // p3=p1*5;
    if(compare_pts(p1,p3))
        printf("IGUAIS!\n");

    PT *pp1=NULL;
    pp1 =&p2;
    pp1=(PT*)calloc(sizeof(PT),1);
    if((p2.x==(*pp1).x)&&(p2.y==pp1->y))
        ;
    (*pp1).x=10;
    pp1->y=20;
    read_pf(&p1);

    RECT r1={{1,2},{2,1}};
    RECT r2 ={{1,3},{3,1}};
    RECT r3=r2;
    RECT *pr=NULL;
    pr=&r1;
    pr=(RECT*)calloc(sizeof(RECT),1);
    *pr=r1;
    read_rect(&r1);
    r3=read_rect(&r2);
    print_RECT(&r1);*/
    return 0;
}

/** Compare to points in space (equal if both have the same coordinates).
 * @param pt1 - one point in space.
 * @param pt2 - another point in space.
 * @return 1 (true) or 0 (false).
 */
int compare_pts(struct pt pt1, struct pt pt2){

    return (pt1.x==pt2.x)&&(pt1.y==pt2.y);
}

/** Compare to rectangles in space (equal if both have the same points).
 * @param r1 - one rectangle in space.
 * @param r2 - another rectangle in space.
 * @return 1 (true) or 0 (false).
 */
int compare_rects(RECT r1, RECT r2){

    return (compare_pts(r1.downpt,r2.downpt)&& compare_pts(r1.uppt,r1.downpt));
}

/** Allocate heap memory for storing the coordinates of a point.
 * @return address to allocated point memory.
 */
struct pt* create_pt(struct pt p);

/** Allocate heap memory for storing a rectangle in space.
 * @return address to allocated rectangle memory.
 */
struct rect* create_rect(RECT r);

/** Use scanf to read the coordinates of a point and store them into memory pointed by pp.
 * @param pp - pointer to a point.
 */
void read_pt(struct pt* pp);

/** Use scanf to read the coordinates of points of a rectangle and store them into memory pointed by pr.
 * @param pr - pointer to a rectangle.
 */
void read_rect(struct rect* pr){

    printf("r=( (%d,%d),(%d,%d) )\n", (*pr).uppt.x,(*pr).uppt.y,pr->downpt.x,pr->downpt.y);
}

/** Print the coordinates of a point.
 * @param pt_label - string containing the label of the point to print.
 * @param p - point to print.
 */
void print_pt(char pt_label[], struct pt p);

/** Print the coordinates of the points of a rectangle pointed by pr.
 * @param rect_label - string containing the label of the rectangle to print.
 * @param pr - pointer to rectangle to print.
 */
void print_rect_v2(char rect_label[], const RECT *pr);
