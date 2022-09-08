#ifndef pr08_h
#define pr08_h

#include <stdlib.h>
#include <stdio.h>

typedef struct point { float x, y; } POINT;

/**
* allocates memory for a new array of strings. If ppstrs is null
* the function allocates space for 10 strings. If ppstrs is non null
* allocates space for psize + 10 strings.
* @param psize - number of strings in ppstrs
* @param ppstrs - pointer to the first position of the string array
* @return pointer to the first position of the string array
*/
char **create_dyn_array_strings(char** ppstrs, int *psize);

/**
* inserts string into the first free position of
* an array of strings
* @param str - string to insert
* @param ppstrs - pointer to the first position of the string array
* @param psize - pointer to the size of the string array
* @return pointer to the first position of the string array
*/
char **insert_string_dyn_array_strings(char** ppstrs, int *psize, char *str);

/**
* Prints a dynamic array of strings
* @param size - number of strings in ppstrs
* @param ppstrs - pointer to the first position of the string array
*/
void print_dyn_array_strings(char **ppstrs, int size);

/**
* Clones the received command line arguments into a new array of strings
* @param argc - number of arguments
* @param argv - arguments
* @return arguments clone
* i.e. input: (3, ("ola", "meu", "mundo")); output: ("ola", "meu", "mundo")
*/
char **clone_argv(int argc, const char *argv[]);

/**
* allocates memory for an array of points
* @param apts - pointer to the first position of the points array
* @param psize - pointer to array size
* @param size - new array size
* @return pointer to the resized array
*/
struct point *create_dyn_array_points(struct point *apts, int *psize, int newSize);

/**
* reads a predefined number of points from stdin
* @param apts - pointer to the first position of the points array
* @param size - number of points to read
*/
void read_array_points(struct point *apts, int size);

/**
* prints an array of points
* @param apts - array of points to be printed
* @param size - size of the point array
*/
void print_array_points(struct point *apts, int size);

#endif //pr08_h
