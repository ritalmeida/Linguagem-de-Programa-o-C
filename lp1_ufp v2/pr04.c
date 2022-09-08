//
// Created by Rita Vieira de Almeida on 19/10/2021.
//

#include "pr04.h"


int main_pr04(int argc, const char * argv[]) {

    /*char s[] = "abcadbf";
    printf("%s ", delete_repeated_chars(s));*/

    /*char s[] = "HELLO";
    printf("%s \n", shift_n(s, -1 ));*/

    /*char str[] = "Ana rita vieira de almeida";
    printf("numero de palavras: %d\n", count_words_string(str));*/

    int matrix[2][2] = {{5,8},{4,3}};
    multiply_matrix_by_scalar(matrix, 2, 2, 3);

    return 0;
}

/**
* delete repteades characters in a given string
* @param s - string
* @return trimmed string
* e.g. input: ("abcadbf"); output: "abcdf"
* e.g. input: ("aa   bb"); output: "a b"
*/
char* delete_repeated_chars(char s[]) {

    int i2 = 0, j;

    for(int i = 0; s[i] != '\0'; i++){
        for(j = i-1; j >= 0; j--){
            if(s[i] == s[j]){
                break;
            }
        }
        if(j == -1){
            s[i2++] = s[i];
        }
    }
    s[i2] = '\0';

    return s;
}

/**
* counts the number of words in a given string
* @param str - string
* @return number of words in str
* e.g. input: ("hello hello world"); output: 3
* e.g. input: ("o um dois tres   quatro"); output: 6
*/
int count_words_string (char str[]) {

    int count = 1;
    unsigned long size = strlen(str);

    for (int i = 0; i < size; i++) {

        if(str[i] == ' ' || str[i] == '\0'){
            count++;
        }
    }

    return count;
}

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
char* shift_n(char s[], int n) {

    unsigned long size = strlen(s);
    char aux[size];


    for (int i = 0; i < size; i++) {

        //sift right
        if(n > 0){

            if(i < n){
                aux[i] = s[i+(n+1)];
            }else if(i >= n){
                aux[i] = s[i-n];
            }
        }
        //sift left
        if(n < 0){

            if(i == (size-1)){
                aux[i] = s[i-i];
            }else
                aux[i] = s[i-n];
        }
    }
    strcpy(s, aux);

    return s;
}

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
void multiply_matrix_by_scalar (int m[][MAXCOLS100], int lines, int columns, int scalar) {

    int aux[lines][columns];

    for (int i = 0; i < lines; i++) {

        for (int j = 0; j < columns; j++) {

            aux[i][j] = scalar * m[i][j];
        }
    }

    for (int i = 0; i < lines; i++) {

        for (int j = 0; j < columns; j++) {

            printf("%d ", aux[i][j]);
        }
        printf("\n");
    }
}
