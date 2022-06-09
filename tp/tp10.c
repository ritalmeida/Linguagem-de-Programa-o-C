//
//  tp10.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 23/11/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "tp10.h"


int main_tp10(int argc, char argv){
    
    STACK_NODE_POINTS stack1 = {0, NULL};
    struct pt pt1 = {0,0};
    
    push_stack_node_points(&stack1, pt1);
    
    struct pt pt2 = pop_stack_node_points_copy(&stack1);
    
    //NODE_POINT pnp1 = pop_stack_node_points_copy(&stack1);
    
    return 0;
}

void push_stack_node_points(STACK_NODE_POINTS *psnp, struct pt info){
    
    NODE_POINT *pnp = (NODE_POINT *) malloc(sizeof(NODE_POINT));
    
    pnp->pdown = psnp->ptop;                                          //ou (*pnp).pdown
    pnp->info = info;
    psnp->ptop = pnp;
    psnp->n_nodes++;
}


int is_empty(STACK_NODE_POINTS snp){
    
    if(snp.n_nodes == 0 && snp.ptop == NULL){
        
        return 1;
    }
    return 0;
}


struct pt pop_stack_node_points_copy(STACK_NODE_POINTS *psnp){                  //remoção à cabeça
    
    struct pt pt = {INT_MAX, INT_MAX};
    
    NODE_POINT *pnp = psnp->ptop;
    
    if(is_empty(*psnp)){
        
        return pt;
    }
    
    pt = psnp->ptop->info;                       //ou pt = (*(*psnp).ptop).info;
    psnp->ptop = psnp->ptop->pdown;             //ou psnp->ptop = pnp->pdown;
    free(pnp);
    psnp->n_nodes--;
    return pt;
}

struct pt peep_stack_node_points_copy(const STACK_NODE_POINTS *psnp, int delta){
    
    struct pt pt = {INT_MAX, INT_MAX};
    
    if(!is_empty(*psnp)){
        
        NODE_POINT *pnp = psnp->ptop;
        int i = 0;
        while (i < delta && pnp != NULL){
            
            pnp = pnp->pdown;
            i++;
        }
        return pnp->info;
    }
    return pt;
}
