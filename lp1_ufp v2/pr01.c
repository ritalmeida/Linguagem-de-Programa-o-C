//
// Created by Rita Vieira de Almeida on 24/09/2021.
//

#include "pr01.h"

int main_pr01(int argc, const char *argv[]){

    printf("PR01 - 24 de setembro de 2021\n");

    //readDateGender();

    /*char c = 'a';
    readCharPrintAscii(c);*/

    //readIntsDivisionFloat(10, 3);

    //printDigitOrNot();

    /*char c = 'r';
    printf("The char '%c' appears %d times!", c, countInsertedChar(c));*/

    //findLongestWord();

    findGreatestSequenceRepeatedChars();
    return 0;
}

/**
* Reads from stdin a birthdate and gender and prints
* a formatted string to the stdout
* i.e. Input: "5 2 1990 male"; output: "The inserted date is | 5/2/1990 | and the gender is: | m |"
*/
void readDateGender(void) {

    int day, month, year;
    char* gender;

    printf("Please insert your birthday and gender: \n");
    scanf("%d %d %d %s", &day, &month, &year, &gender);

    printf("The inserted date is | %d/%d/%d | and the gender is: | %s |\n", day, month, year, &gender);
}

/* print the ascii value of a given character
* output -> readCharPrintAscii('a') : 97
* @param c - char to be converted
*/
void readCharPrintAscii(char c) {

    printf("readCharPrintAscii(%c) : %d\n", c, c);
}

/**
* division of two integer values
* output -> readIntsDivisionFloat(10, 3) : 3.33
* @param a - dividend
* @param b - divisor
* @return - (float) a / b
*/
float readIntsDivisionFloat(int a, int b) {

    printf("readIntsDivisionFloat(%d, %d) : %.2f\n", a, b, ((float)a/b));
}

/**
* iteratively checks if a user input char is a digit
* output: '0' is a digit; 'a' is not a digit
*/
void printDigitOrNot(void) {

    char input = '\0';

    do {

        printf("Insert a character. Press '.' when finish:\n");
        scanf(" %c", &input);

        if(input >= '0' && input <= '9'){
            printf("%c is a digit\n", input);
        } else if (input == '.') {
            printf("Exit!\n");
        } else
            printf("%c is not a digit!\n", input);
    }while(input != '.');
    /*char c = '\0';

    while (c != '.') {
        printf("\nInsert a char! Press '.' when finish.\n");
        scanf("%c", &c);

        if (c <= '9' && c >= '0') {

            printf("'%c' is a digit!", c);
        } else {
            printf("'%c' is not a digit!", c);
        }
    }*/

    /*printf("\nInsert a char! Press ENTER when finish.\n");
    scanf("%c", &c);

    while((c = getchar()) != '\n') {
        if (c <= '9' && c >= '0') {
            printf("'%c' is a digit!", c);
            continue;
        }
        printf("'%c' is not a digit!", c);
    }*/
}

/**
* counts how many times a given char appears in a
* series of chars iteratively entered by the user
* @param charToCount - char to count
* @return - number of occurrences
*/
int countInsertedChar(char charToCount) {

    int countChar = 0;
    char input = '\0';

    printf("Insert characters. To stop, press ENTER: \n");

    while((input = getchar()) != '\n'){

        if(input == charToCount){

            countChar++;
        }
    }

    return countChar;
}

/**
* Finds the longest word in a series of
* chars iteratively entered by the user
* i.e. input: "ab ccc dededede f"; output: "The longest word has 8 characters\n"
* i.e. input: "aa 123 ababa23"; output: "The longest word has 7 characters"
* i.e. input: "a b c d e"; output: "The longest word has 1 characters"
*/
void findLongestWord(void) {

    char c = "\0";
    int count = 0, max = 0;

    printf("Insert characters. To stop, press ENTER: \n");
    while((c = getchar()) != '\n'){

        if (c == ' ') {
            count = 0;
        }else {
            count++;
        }
        //printf("%d", count);

        if (count >= max) {
            max = count;
        }
    }
    printf("The longest word has %d characters\n", max);
}

/**
* Finds the greatest sequence of repeated chars in a
* series of chars iteratively entered by the user
* i.e. input: "abcccdedededef"; output: "The character c appeard consecutively 3 times\n"
* i.e. input: "abcdef"; output: "The character a appeard consecutively 1 times\n"
* i.e. input: "abdddccdddefffff"; output: "The character f appeard consecutively 5 times\n"
*/
void findGreatestSequenceRepeatedChars(void) {                      //nao terminado

    char c = "\0";
    char prev = "\0";
    int count = 1, max = 0;

    printf("Insert characters. To stop, press ENTER: \n");
    while((c = getchar()) != '\n'){

    }

    printf("%d ", max);
}