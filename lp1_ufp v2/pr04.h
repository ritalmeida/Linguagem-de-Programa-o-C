#ifndef pr04_h
#define pr04_h

#include <stdio.h>
#include <string.h>

#define MAXCOLS100 100

/**
* delete repteades characters in a given string
* @param s - string
* @return trimmed string
* e.g. input: ("abcadbf"); output: "abcdf"
* e.g. input: ("aa   bb"); output: "a b"
*/
char* delete_repeated_chars(char s[]);                                              //FEITO!!

/**
* counts the number of words in a given string
* @param str - string
* @return number of words in str
* e.g. input: ("hello hello world"); output: 3
* e.g. input: ("o um dois tres   quatro"); output: 6
*/
int count_words_string (char str[]);                                            //FEITO

/**
* Capitalize first letter of each word in string
* @param str - string
* @return str - string after capitalization
* e.g. input: "ola Meu mundo" output: "Ola Meu Mundo"
*/
char* capitalize_string(char str[]);

/**
* shift all the characters in a given string
* @param s - string
* @param n - number of shifts. if n<0 shift left; if n>0 shift right
* @return shifted string
* e.g. input: ("hello",  2); output: "lohel"
* e.g. input: ("hello", -1); output: "elloh"
*/
char* shift_n(char s[], int n);                                                         //FEITO

/**
* Sum the integer of the diagonal elements of a matrix
* @param mNx100 - matrix
* @param lines - number of line
* @param columns - number of columns
* @return sumdiag - sum of diagonal elements.
* e.g. input: 1 2 3 output: "15"
*             4 5 6
*             7 8 9
*/
int sumdiag_mNx100(int mNx100[][MAXCOLS100], int lines, int columns);

/**
* multiply matrix by scalar
* @param m - matrix to be multiplied
* @param lines - number of matrix lines
* @param columns - number of matrix columns
* @param scalar - multiplier
* e.g. input: ([[5, 8], [4, 3]], 3); output: [[15, 24], [12, 9]]
*/
void multiply_matrix_by_scalar (int m[][MAXCOLS100], int lines, int columns, int scalar);           //FEITO

int main_pr04(int argc, const char * argv[]);


#endif /* pr04_h */



