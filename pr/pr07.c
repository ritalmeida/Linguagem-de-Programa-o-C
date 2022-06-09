//
//  pr07.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 05/11/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr07.h"

int main_pr07(int argc, const char * argv[]){
    
    /*int *j = NULL;
    j = alloc_dyn_int();
    printf("%d\n", *j);*/
    
    //alloc_and_init_dyn_int_array(5);
    int n = 5;
    print_dyn_int_array(alloc_and_init_dyn_int_array(n), n);

    return 0;
}

/**
* allocates memory for an integer
@return pointer to the allocated memory
*/
int* alloc_dyn_int(void){
    
    /*int *x = (int *) malloc(sizeof(int) * 10);
    int *x = (int *) calloc(x, sizeof(int) * 10);
    int *x = (int *) realloc(x, sizeof(int) * 10);*/
    
    return (int *) calloc(1, sizeof(int));      //return 1 elemento com sizeof int
}

/**
* allocates memory for an array of integers
@param n - number of positions to be allocated
@return pointer to the allocated memory
*/
int* alloc_dyn_int_array(int n){
    
    return (int *) calloc(n, sizeof(int));  //fazer a implementação no mips
}

/**
* allocates memory for an array of integers, initializing all elements to zero
@param n - number of positions to be allocated
@return pointer to the allocated memory
*/
int* alloc_and_init_dyn_int_array(int n){
    
    int *array;
    array = calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        
        array[i] = 0;
    }
    
    return array;
}

/**
* prints dynamic int array
@param pints - array to print
@param n - number of elements in the array
*/
void print_dyn_int_array(int* pints, int n){
    
    for (int i = 0; i < n; i++) {
        
        printf("%d ", *(pints+i));
    }
}

/**
* creates or resizes a dynamic int array.
* if pints is NULL, create and init new dyn int array
* else returns an array with newsize, initializing the empty positions to zero
@param pints - array to create or resize
@param size - current array size (Filled positions)
@param newsize - new array size
@return array with the same content of pints, but with newsize
*/
int* create_or_resize_dyn_int_array(int *pints, int size, int newsize){
    
    //return (int *) realloc(pints, newsize); OU
     
    int *aux = (int *) calloc(newsize, sizeof(int));
    for(int i = 0; i < size; i++){
        
        *(aux + i) = *(pints + i);
    }
    free(pints);
    return aux;                 //terminar no main
}

/**
* trims and copies the content of static array str to a new dynamic array
@param str - static string
@return trimed string
* i.e. input: char * with 8 elements ((a, b, c, \0, 0, 0, 0, 0)); output: char * with 4 elements (a, b, c, \0)
*/
char* create_copy_dyn_string(char str[]){
    
    char *aux = (char *) malloc(sizeof(char *) * (strlen(str)+1));
    
    strcpy(aux, str);
    return aux;
}

/**
* Fills a static array of strings with dynamic stdin retreived strings.
* create_copy_dyn_string should be used to trim the stdin read string
@param astr - static (and empty) array of strings
@param size - size of astr
@return filled astr
*/
char** read_array_dyn_strings(char *astr[], int size){
    
    char aux[200] = " ";
    for(int i = 0; i < size; i++){
        fgets(aux, sizeof(aux), stdin);
        aux[strlen(aux) - 1] = '\0';
        astr[i] = create_copy_dyn_string(aux);
    }
    return astr;
}


char **add_dyn_string_array(char **astr, int used, int *size, char *str){
    
    if(used > (*(size)/2)){
        
        astr = (char **) realloc(astr, *size * sizeof(char *));
    }
    *(astr+used) = str;
    return astr;
}
/**
* Fills a dynamic array of strings with dynamic stdin retreived strings.
* create_copy_dyn_string should be used to trim the stdin read string
@param astr - dynamic (and empty) array of strings
@return filled astr
*/
char** read_dyn_array_dyn_strings(char ** astr, int * size){
    
    *size = 2;
    astr = (char **) malloc(sizeof(char *) * *size);
    char aux[200];
    int i = 0;
    
    while (strcmp(fgets(aux, sizeof(aux), stdin), "exit\n") != 0) {

        aux[strlen(aux) - 1] = '\0';
        astr = add_dyn_string_array(astr, i++, size, create_copy_dyn_string(aux));
    }
    
    return astr;
}
