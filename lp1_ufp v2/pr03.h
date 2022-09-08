#ifndef pr03_h
#define pr03_h

#include <stdio.h>
#include <math.h>

/**
* recursively raises b to the power of e
* @param b - base
* @param e - exponent
* @returns b^e
* e.g. input: (2, 5); output: 32
* e.g. input: (10, 1); output: 10
* e.g. input: (3, 0); output: 1
*/
double powRecursive(int b, int e);                                  //FEITO!

/**
* recursively prints n parts of the hangman 
* @param level - number of members to print
* e.g. input: (6); output: \O/
*							|
*						   / \
* e.g. input: (4); output: \O/
*							|
*/
void print_hangman_recursive(int level);                            //FEITO

/**
* sum all elements of a given integer array
* @param ints - integer array
* @param size - array size
* @return - sum of all elements
* e.g. input: ([1, 2, 3, 4, 5], 5); output: 15
*/
int sum (int ints[], int size);                                             //FEITO

/**
* compare two integer arrays with the same size
* @param a - array for comparison
* @param b - array for comparison
* @param size - size for both arrays
* @return - 0 if (a == b) ; -1 if (a < b) ; 1 if (a > b)
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 5], 4); output: -1
* e.g. input: ([1, 3, 3, 4], [1, 2, 3, 4], 4); output: 1
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 4], 4); output: 0
*/
int intCompare (int a[], int b[], int size);                                  //FEITO

/**
* counts how many times a given integer appears in a given array
* @param a - array to be searched
* @param n - number to search
* @param size - array size
* @return - number of times n appears in v
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 2
* e.g. input: ([1, 2, 2, 2], 2, 4); output: 3
*/
int countFrequencyNumber (int a[], int n, int size);                        //FEITO

/**
* finds the number with the highest frequency (mode) in a given array
* @param a - array to be searched
* @param size - array size
* @return - mode of array
* e.g. input: ([1, 4, 2, 4], 4); output: 4
* e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int numberHighestFrequency (int a[], int size);                         //FEITO

/**
* count the number of clumps (a series of 2 or more adjacent equal
* elements)  in a given array
* @param a - array to be searched
* @param size - array size
* @return - number of clumps
* e.g. input: ([30, 41, 41, 18, 24, 24, 4, 12], 8); output: 2
* e.g. input: ([30, 41, 42, 18, 24, 24, 24, 12], 8); output: 1
* e.g. input: ([30, 41, 42, 18, 24, 25 , 4, 12], 8); output: 0
*/
int countClumps (int a[], int size);                                            //FEITO!!


int main_pr03(int argc, const char * argv[]);

#endif /* pr03_h */



