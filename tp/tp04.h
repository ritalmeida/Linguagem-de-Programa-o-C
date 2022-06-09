//
//  tp04.h
//  lp1_ufp
//
//  Created by Rui on 10/10/17.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef tp04_h
#define tp04_h

#define MAXSIZEARRAY 30

#include <stdio.h>
#include "tp03.h"

/**
 * Receives an integer and recursively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 */
int numberOfDigitsRecursive(int a);                         //feito

/**
 * Multiplies 2 numbers using a recursive algorithm.
 * @param a - fisrt operand
 * @param b - second operand
 * @return the product of a and b
 */
double multiply_recursive(int a, int b);                    //feito

/**
 * Uses a recursive algorithm to calculate the factorial of a number.
 * @param n - the number to calculate the factorial from
 * @return the factorial of the parameter
 */
double factorial_recursive(int n);                          //feito

/**
 * Prints recursively the multiplaction table of a given number.
 * @param n - number to calculate and print the multiplication table
 * @param level - which level of the multiplcation table to print
 */
void print_multable_recursive(int n, int level);            //feito

/**
 * Reads vowels from stdin and stores them inside an array.
 * @param vowals - array where to store the vowels
 * @param size - max size of the array
 */
int read_vowels(char vowals[], int size);                   //feito

/**
 * Prints the vowels inside an array of chars.
 * @param c - array of vowels
 * @param size - max size of the array
 */
void print_vowels(char c[], int size);                      //feito

/**
 * Search an array of ints to find the max value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the max value inside the array
 */
int max(int ints[], int size);                              //feito

/**
 * Search an array of ints to find the min value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the min value inside the array
 */
int min(int ints[], int size);                              //feito

/**
 * Calculates the mean of an array of ints.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the mean of the elements inside the array
 */
float mean(int ints[], int size);                           //feito

/** Receives and array of ints and and array with a pattern of numbers to search.
 *  Searches how many segments of the pattern exists inside the array of ints
 *  e.g., v=[5,  2,  2,  3,  4,  4,  4,  4,  1,  1, 2, 2] e p=[2, 2]
 *      would return 2 segments of p exist in v.
 *  @param v - array of ints with patterns of ints
 *  @param sizev - number of elements inside the array
 *  @param p - array with pattern of ints to search
 *  @param sizep - size of the arrray of patterns
 *  @return number of segments p that exist inside the v array
 */
int count_segments_repeated_ints(int v[], int sizev, int p[], int sizep);       //feito

/**
 * Unit test funtcion for the 4th TP class.
 */
int main_tp04(int argc, const char * argv[]);


#endif /* tp04_h */
