#ifndef pr05_h
#define pr05_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pr04.h"
#include <math.h>


/**
* finds all the prime numbers present in a given matrix
* @param m - matrix to search for prime numbers
* @oaram lines - number of lines
* @param columns - number of columns
* @param primes - array in which the found prime numbers will be stored
* @return - array containing all the found prime numbers
*/
int * find_prime_numbers_matrix (int m[][MAXCOLS100], int lines, int columns, int * primes, int * psize);

/**
* swap values of x and y
* @param px - pointer to x
* @param py - pointer to y
*/
void swap_pxy(int* px, int* py);                                            //FEITO

/**
* calc the roots of a 2º grade polinomial ax^2 + bx + c
* @param a - retreived from ax^2
* @param b - retreived from bx
* @param c - retreived from c
* @param r1 - first root
* @param r2 - second root
* i.e. input: (2, -14, 20, &r1, &r2); output: r1=5.00, r2=2.00
*/
void calc_roots(int a, int b, int c, double* r1, double* r2);                                       //FEITO

/**
* prints all the elements in a given double array
* @param pi - pointer to the first position of the given array
* @param size - array size
*/
void print_array_double_with_index(double *pi, int size);                                               //FEITO

/**
* prints all the elements in a given double array, without using an index var to iterate the array
* @param pi - pointer to the first position of the given array
* @param size - array size
*/
void print_array_double_without_index(double *pi, int size);                                                //FEITO

/**
* swap two positions of a given double array, using pointer notation
* @param pi - pointer to the first position of the double array
* @param pos1 - position 1
* @param pos2 - position 2
* @return array after swap
* i.e. input: ((1, 2, 3, 4), 0, 2); output: (3, 2, 1, 4)
*/
double* swap_double_array_ptr(double* pi, int pos1, int pos2);                  //FEITO

/**
* find the mode, mean and median of a given integer array
* @param pi - pointer to the first position of the given array
* @param size - array size
* @param mmm - pointer to the first position of the array containing the results
* @return mmm (mode, mean and median) of the given array
* i.e. input: ((11, 23, -1, 7, 11, -10, 5, 1), 8); output: (11, 5.88, 5)
*/
double* find_mode_mean_median (int *pi, int size, double *mmm);

/**
* strstr implementation using pointer notation. Checks for the first
* occurrence of a substring in a given string
* @param pstr - pointer to the first position of the given string
* @param psubstr - pointer to the first position of the given substring
* @return pointer to the first occurrence of substr in str or NULL if not present
*/
char* strstr_ptr(char* pstr, char * psubstr);

int main_pr05(int argc, const char * argv[]);

#endif /* pr05_h */



