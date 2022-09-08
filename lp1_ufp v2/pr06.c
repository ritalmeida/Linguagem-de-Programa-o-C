//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "pr06.h"

int main_pr06(int argc, const char * argv[]){

    //print_received_args(argc, argv);

    //calculator_command_line(argc -1, argv +1);

    /*char str[] = "minus";
    char *pstr = str;
    char str_M[] = "";
    str_to_upper(pstr, str_M);*/


    return 0;
}

/**
* print args received from the command line
@param argc - number of args
@param argv - set of received args
*/
void print_received_args(int argc, const char *argv[]){

    for (int i = 0; i < argc; i++) {

        printf("%s\n", *(argv+i));
    }
}

/**
* Convert a string to uppercase
@param pstr - input string
@param strUpper - resulting uppercase string
@return resulting uppercase string
* i.e. input: ("minus", ""); output: "MINUS"
*/
char* str_to_upper(char *pstr, char strUpper[]){

    int i = 0;

    while (pstr[i] != '\0'){

        strUpper[i] = putchar(toupper(pstr[i]));
        i++;
    }
    printf("\n");

    return strUpper;
}

/**
* Computes the sum (PLUS), subtraction (MINUS), multiplication (MULT) or division (DIV) of two
* received numbers
@param argc - number of args
@param argv - numbers and operation
@return - result
* i.e. input:(4, ("./main", "12", "plus", "3")); output: 15
* i.e. input:(4, ("./main", "5", "MULT", "4")); output: 20
*/
int calculator_command_line(int argc, const char *argv[]){

    int a = atoi(*(argv+0));
    int b = atoi(*(argv+2));

    int result = 0;

    if(strcmp("plus", *(argv+1)) == 0){

        result = a + b;
    }
    else if(strcmp("minus", *(argv+1)) == 0){

        result = a - b;
    }
    else if(strcmp("mult", *(argv+1)) == 0){

        result = a * b;
    }
    else if(strcmp("div", *(argv+1)) == 0){

        result = a / b;
    }

    return result;
}

/**
* concatenates two strings
@param pstr1 - first string
@param pstr2 - second string
@param str - resulting string after concatenation
@return - resulting string after concatenation
* i.e. input:("ola", " mundo", ""); output: "ola mundo"
* i.e. input:("ola mundo", "!", ""); output: "ola mundo!"
*/
char* string_cat(const char *pstr1, const char *pstr2, char str[]){

    int i;

    for (i = 0; *(pstr1 + i); i++) {

        *(str + i) = *(pstr1 + i);
    }
    for (int j = 0; *(pstr2 + i) != '\0'; j++) {

        *(str + i) = *(pstr2 + i);
        i++;
    }

    return str;
}

/**
* concatenates argv strings
@param argc - number of entries in argv
@param argv - args to concatenate
@param str - resulting string after concatenation
@return - resulting string after concatenation
* i.e. input:(3, ("ola", " mundo", "!"), ""); output: "ola mundo!"
* i.e. input:(4, ("four", " args", " to", " cat"), ""); output: "four args to cat"
*/
char* cat_argv_strings(int argc, const char *argv[], char str[]){



    return str;
}

/**
* computes the frequency of each word in the argv array
@param argc - number of args
@param argv - set of args
@param freqs - frequencies of each string
@return - number of distinct strings in argv (size of freqs)
* i.e. input:(6, ("aa", "bbb", "ccc", "aa", "ccc", "aa"), ""); output: 3, freq[] = {3, 1, 2}
* i.e. input:(6, ("aa", "bbb", "ccc", "aaa", "ccc", "ddd"), ""); output: 5, freq[] = {1, 1, 2, 1, 1}
*/
int frequencies_strings_argv(int argc, const char *argv[], int freqs[]){

    /*int i = 0, j = 0, count = 0, k = 0;
    for(i = 0; i < argc;i++){
        if((!strExistsBefore(*(argv+i), argv, i)) == 0){
            for(j = i; j < argc; j++){
                if(strcmp(*(argv+1), *(argv+j)) == 0)
                    count++;
            }
            printf("%s: %d\n", *(argv+i), count);
            freqs[k++] = count;
            count = 0;
        }
    }
    return k;*/
    return 0;
}

/**
* sums all numbers is argv
@param argc - number of args
@param argv - set of args
@return argv sum
* i.e. input: (3, ("1", "2", "3")); output: 6
* i.e. input: (5, ("1", "2", "3", "4", "1")); output: 11
*/
int sum_all_argv(int argc, const char *argv[]){

    int sum = 0;

    for (int i = 0; i < argc; i++) {
    }
    return sum;
}

/**
* splits a string by a user-defined delimiter. The result is stored
* in a given array of strings.
* @param string - input string
* @param ret - char matrix, each line is a substring of
* string formed by splitting it on boundaries formed by the
* string delimiter.
* @param delimitr - boundary string
*/
void explode_string (char * string, char ret[][MAX100], char * delimiter){}