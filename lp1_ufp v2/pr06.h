

#ifndef pr06_h
#define pr06_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef MAX100
#define MAX100 100
#endif

/**
* print args received from the command line
* @param argc - number of args
* @param argv - set of received args
*/
void print_received_args(int argc, const char *argv[]);

/**
* Computes the sum (PLUS), subtraction (MINUS), multiplication (MULT) or division (DIV) of two
* received numbers
* @param argc - number of args
* @param argv - numbers and operation
* @return - result
* i.e. input:(4, ("./main", "12", "plus", "3")); output: 15
* i.e. input:(4, ("./main", "5", "MULT", "4")); output: 20
*/
int calculator_command_line(int argc, const char *argv[]);

/**
* sums all numbers is argv
* @param argc - number of args
* @param argv - set of args
* @return argv sum
* i.e. input: (3, ("1", "2", "3")); output: 6
* i.e. input: (5, ("1", "2", "3", "4", "1")); output: 11
*/
int sum_all_argv(int argc, const char *argv[]);

/**
* concatenates argv strings
* @param argc - number of entries in argv
* @param argv - args to concatenate
* @param str - resulting string after concatenation
* @return - resulting string after concatenation
* i.e. input:(3, ("ola", " mundo", "!"), ""); output: "ola mundo!"
* i.e. input:(4, ("four", " args", " to", " cat"), ""); output: "four args to cat"
*/
char* cat_argv_strings(int argc, const char *argv[], char str[]);

/**
* computes the frequency of each word in the argv array
* @param argc - number of args
* @param argv - set of args
* @param freqs - frequencies of each string
* @return - number of distinct strings in argv (size of freqs)
* i.e. input:(6, ("aa", "bbb", "ccc", "aa", "ccc", "aa"), ""); output: 3, freq[] = {3, 1, 2}
* i.e. input:(6, ("aa", "bbb", "ccc", "aaa", "ccc", "ddd"), ""); output: 5, freq[] = {1, 1, 2, 1, 1}
*/
int frequencies_strings_argv(int argc, const char *argv[], int freqs[]);

/**
* splits a string by a user-defined delimiter. The result is stored
* in a given array of strings.
* @param string - input string
* @param ret - char matrix, each line is a substring of 
* string formed by splitting it on boundaries formed by the 
* string delimiter. 
* @param delimitr - boundary string
*/
void explode_string (char * string, char ret[][MAX100], char * delimiter);

#endif //pr06_h
