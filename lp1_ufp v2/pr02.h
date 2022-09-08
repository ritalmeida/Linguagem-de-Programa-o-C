#ifndef pr02_h
#define pr02_h

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tp03.h"

int main_pr02(int argc, const char *argv[]);

/**
* Prints the multiplication table for a given number
* @param num - input number
* e.g. input: (2) => output: 2x1=2\n2x2=4\n2x3=6 ...
*/
void printMultiplicationTable (int num);                            //FEITO!

/**
* prints inverted pyramid
* @param width - pyramid's base width
* e.g. input: (5); output: 1 2 3 4 5
*				     		 2 3 4
*				        	   3
*/
void printPyramid (int width);                                      //FEITO!

/**
* Checks if a number is triangular, i.e., the product of three consecutive int numbers.
* @param num - number to be checked
* @return - true (0) or false (1)
* e.g. input: (504) => output: is triangular 504 = 7x8x9
* e.g. input: (1320) => output: is triangular 1320 = 10x11x12
*/
int isNumberTriangular (unsigned int num);                          //FEITO!

/**
* Converts a decimal number to binary
* @param num - decimal number
* @return - binary converted number
* e.g. input: (10); output: 1010
*/
int decimalToBinary (int num);                                                  //FEITO!

/**
* Converts a binary number to decimal
* @param bin - binary number
* @return - decimal converted number
* e.g. input: (1010); output: 10
*/
int binaryToDecimal (int bin);                                              //FEITO!

/** 
* Splits an integer into two halves
* @param n - int number to split in half.
* e.g. input: (284) -> 2 e 4; 
* e.g. input: (4587) -> 45 e 87
*/
void splitsIntHalf(int n);


#endif /* pr02.h */
