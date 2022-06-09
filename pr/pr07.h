#ifndef pr07_h
#define pr07_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
* allocates memory for an integer
* @return pointer to the allocated memory
*/
int* alloc_dyn_int(void);       //feito

/**
* allocates memory for an array of integers
* @param n - number of positions to be allocated
* @return pointer to the allocated memory
*/
int* alloc_dyn_int_array(int n);                    //feito

/**
* allocates memory for an array of integers, initializing all elements to zero
* @param n - number of positions to be allocated
* @return pointer to the allocated memory
*/
int* alloc_and_init_dyn_int_array(int n);                           //feito

/**
* prints dynamic int array
* @param pints - array to print
* @param n - number of elements in the array
*/
void print_dyn_int_array(int* pints, int n);                    //feito

/**
* creates or resizes a dynamic int array.
* if pints is NULL, create and init new dyn int array
* else returns an array with newsize, initializing the empty positions to zero
* @param pints - array to create or resize
* @param size - current array size (Filled positions)
* @param newsize - new array size
* @return array with the same content of pints, but with newsize
*/
int* create_or_resize_dyn_int_array(int *pints, int size, int newsize);     //feito

/**
* trims and copies the content of static array str to a new dynamic array
* @param str - static string
* @return trimed string
* i.e. input: char * with 8 elements ((a, b, c, \0, 0, 0, 0, 0)); output: char * with 4 elements (a, b, c, \0)
*/
char* create_copy_dyn_string(char str[]);           //feito

/**
* Fills a static array of strings with dynamic stdin retreived strings.
* create_copy_dyn_string should be used to trim the stdin read string
* @param astr - static (and empty) array of strings
* @param size - size of astr
* @return filled astr
*/
char** read_array_dyn_strings(char *astr[], int size);          //feito

/**
* Fills a dynamic array of strings with dynamic stdin retreived strings.
* create_copy_dyn_string should be used to trim the stdin read string
* @param astr - dynamic (and empty) array of strings
* @return filled astr
*/
char** read_dyn_array_dyn_strings(char ** astr, int * size);            //feito


int main_pr07(int argc, const char * argv[]);

#endif /* pr07_h */
