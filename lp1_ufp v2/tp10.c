//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include <limits.h>
#include "tp10.h"

/** Structure characterizing a node for storing a point */
typedef struct node_point
{
    struct pt info;
    //Self-referencing
    struct node_point *pdown;
}NODE_POINT;

/** Structure characterizing a stack of node points (LIFO management: push, pop, peep). */
typedef struct stack_node_points
{
    int nnodes;
    //Cross-referencing
    NODE_POINT *ptop;
} STACK_NODE_POINTS;

int main_tp10(int argc, const char * argv[]){

    STACK_NODE_POINTS stack1 = {0, NULL};
    struct pt pt1 = {0,0};

    push_stack_node_points(&stack1, pt1);

    struct pt pt2 = (struct pt) pop_stack_node_points_copynode(&stack1);

    //NODE_POINT pnp1 = pop_stack_node_points_copy(&stack1);

    return 0;
}

/**
 * Push a new node into the stack..
 * @param psnp -  pointer to stack of node points.
 * @param newpt - new point to push into stack.
 */
void push_stack_node_points(STACK_NODE_POINTS *psnp, struct pt newpt){

    NODE_POINT *pnp = (NODE_POINT *) malloc(sizeof(NODE_POINT));

    pnp->pdown = psnp->ptop;                                          //ou (*pnp).pdown
    pnp->info = newpt;
    psnp->ptop = pnp;
    psnp->nnodes++;
}


/**
 * Checks if stack is empty.
 * @param snp - copy of stack of node points.
 * @return 0 (false) or 1 (true)
 */
int is_empty_stacknodepoints_v2(STACK_NODE_POINTS snp){

    if(snp.nnodes == 0 && snp.ptop == NULL){

        return 1;
    }
    return 0;
}


/**
 * Pop the node at the top of stack and frees the node memory.
 * @param psnp -  pointer to stack of node points.
 * @return copy of point that was stored in the node info at top of stack.
 */
struct pt pop_stack_node_points_copynode(STACK_NODE_POINTS* psnp){                  //remoção à cabeça

    struct pt pt = {INT_MAX, INT_MAX};

    NODE_POINT *pnp = psnp->ptop;

    if(is_empty_stacknodepoints_v2(*psnp)){

        return pt;
    }

    pt = psnp->ptop->info;                       //ou pt = (*(*psnp).ptop).info;
    psnp->ptop = psnp->ptop->pdown;             //ou psnp->ptop = pnp->pdown;
    free(pnp);
    psnp->nnodes--;
    return pt;
}


/**
 * Peep the node info below delta from the top of stack.
 * @param psnp -  pointer to stack of node points.
 * @return copy of node info below delta position from top of stack.
 */
struct pt peep_stack_node_points_copy(const STACK_NODE_POINTS *psnp, int delta){

    struct pt pt = {INT_MAX, INT_MAX};

    if(!is_empty_stacknodepoints_v2(*psnp)){

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