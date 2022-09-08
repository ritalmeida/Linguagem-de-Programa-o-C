//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "pr08.h"


int main_pr08(int argc, const char * argv[]){

    return 0;
}

/**
* Prints a dynamic array of strings
@param size - number of strings in ppstrs
@param ppstrs - pointer to the first position of the string array
*/
void print_dyn_array_strings(char **ppstrs, int size){

    for (int i = 0; i < size; i++) {

        printf("%s (%p)\n", *(ppstrs + i), (ppstrs + i));

        for (int i = 0; i < size; i++) {

            free(*(ppstrs + i));        //ou * i
        }
        free(ppstrs);
        size = 0;

    }
}

/**
* Deallocates the memory pointed by ppstr
@param ppstr - pointer to the first position of the string array
@param psize - pointer to the size of the string array
@return NULL
*/
char **free_dyn_array_strings(char **ppstr, int *psize){

    ppstr = (char**)malloc((unsigned long)psize);

    return NULL;
}

/**
* splits a string by a given delimiter
@param str - string to split
@param delimiter - spliting pattern
@return pointer to the first position of the resulting string array
* i.e. input: ("ola meu mundo!", " "); output: ("ola", "meu", "mundo!")
*/
char ** string_explode (char * str, char * delimiter, int * size);

/**
* prints all the non repeated strings in a string array
@param astr - pointer to the first position of the string array
@param size - number os strings in astr
* i.e. input: (("aa", "bbb", "ccc", "aa", "ccc", "ddd"), 6); output: "bbb, ddd"
* i.e. input: (("ola", "mundo", "ola", "mundo"), 4); output: ""
*/
void print_non_repeated_strs(const char *astr[], int size){ // from TP classes. Implementation should be done in tp07.c!


}
