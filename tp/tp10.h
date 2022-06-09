//
//  tp10.h
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 23/11/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#ifndef tp10_h
#define tp10_h

#include "tp09.h"
#include <limits.h>
#include <stdio.h>

typedef struct node_point{              //B
    
    struct pt info;
    struct node_point *pdown;
}NODE_POINT;

typedef struct stack_node_point{        //A
    
    int n_nodes;
    NODE_POINT *ptop;
}STACK_NODE_POINTS;

void push_stack_node_points(STACK_NODE_POINTS *psup, struct pt info);               //feito

int is_empty(STACK_NODE_POINTS snp);                                        //feito

struct pt pop_stack_node_points_copy(STACK_NODE_POINTS *psnp);              //feito

struct pt peep_stack_node_points_copy(const STACK_NODE_POINTS *psnp, int delta);    //feito

int main_tp10(int argc, char argv);

#endif /* tp10_h */
