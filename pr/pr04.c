//
//  pr04.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 15/10/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr04.h"
#include <string.h>
#include <err.h>
#include <stdlib.h>

int main_pr04(int argc, const char * argv[]){
    
    //printf("%.2f \n", pow_recursive(2, 5));
    
    //print_hangman_recursive(6);
    
    /*char str[] = "hello hello world";
    printf("%d\n", greatest_word_string(str));*/
    
    /*char s[] = "abcadbf";
    printf("%s ", delete_repeated_chars(s));*/
    
    /*char s[] = "HELLO";
    printf("%s \n", shift_n(s, -1 ));*/
    
    /*char str[100] = "olaxxxmeuxxxmundo\n";
    printf("%s ", str);
    replace_sub2rep(str, "xxx", "??");
    printf("%s ", str);*/
    
    /*char str[] = "Ana rita vieira de almeida";
    printf("numero de palavras: %d\n", count_words_string(str));*/
    
    /*int matrix[2][2] = {{5,8},{4,3}};
    multiply_matrix_by_scalar(matrix, 2, 2, 3);*/
    
    int lines = 4, columns = 4;
    
    int matA[MAXLIN100][MAXCOLS100] = { { 1, 1, 1, 1 },
                                        { 2, 2, 2, 2 },
                                        { 3, 3, 3, 3 },
                                        { 4, 4, 4, 4 } };
    
    int matB[MAXLIN100][MAXCOLS100] = { { 1, 1, 1, 1 },
                                        { 2, 2, 2, 2 },
                                        { 3, 3, 3, 3 },
                                        { 4, 4, 4, 4 } };
    
    int matC[lines][columns];
    
    multiply_matrixesNxMAXCOLS100(matA, matB, matC, lines, columns);
    
    return 0;
}

/**
* recursively raises b to the power of e
@param b - base
@param e - exponent
@returns b^e
* e.g. input: (2, 5); output: 32
* e.g. input: (10, 1); output: 10
* e.g. input: (3, 0); output: 1
*/
double pow_recursive(int b, int e){
    
    if(e == 0) return 1;
    return b * pow_recursive(b, e - 1);
}

/**
* recursively prints n parts of the hangman
@param level - number of members to print
* e.g. input: (6); output: \O/
                            |
                           / \
* e.g. input: (4); output: \O/
                            |
*/
void print_hangman_recursive(int level){
    
    if(level > 1)
        print_hangman_recursive(level - 1);
    switch(level){
        case 1: printf("\\"); break;
        case 2: printf("o"); break;
        case 3: printf("/"); break;
        case 4: printf("\n |"); break;
        case 5: printf("\n/"); break;
        case 6: printf("\\"); break;
    }
}

/**
* delete repteades characters in a given string
@param s - string
@return trimmed string
* e.g. input: ("abcadbf"); output: "abcdf"
* e.g. input: ("aa   bb"); output: "a b"
*/
char* delete_repeated_chars(char s[]){
    
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
* shift all the characters in a given string
@param s - string
@param n - number of shifts. if n<0 shift left; if n>0 shift right
@return shifted string
* e.g. input: ("hello",  2); output: "lohel"
* e.g. input: ("hello", -1); output: "elloh"
*/
char* shift_n(char s[], int n){
    
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
* replace all the ocurrences of a given substring in a given string
@param str - main string
@param sub - substring to be replaced
@param rep - replacement substring
@return str after replacement
* e.g. input: ("olaxxxmeuxxxmundo", "xxx", "??"); output: "ola??meu??mundo"
*/
char* replace_sub2rep(char str[], char sub[], char rep[]){
    
   char* result;
      int i, cnt = 0;
      unsigned long newWlen = strlen(rep);
      unsigned long oldWlen = strlen(sub);
      
      // Counting the number of times old word
      // occur in the string
      for (i = 0; str[i] != '\0'; i++) {
          if (strstr(&str[i], sub) == &str[i]) {
              cnt++;
                // Jumping to index after the old word.
              i += oldWlen - 1;
            }
        }
      
        // Making new string of enough length
        result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
      
        i = 0;
        while (*str) {
            // compare the substring with the result
            if (strstr(str, sub) == str) {
                strcpy(&result[i], rep);
                i += newWlen;
                str += oldWlen;
            }
            else
                result[i++] = *str++;
        }
      
         result[i] = '\0';
      
      strcpy(str, result);

    return str;
}

/**
* counts the number of words in a given string
@param str - string
@return number of words in str
* e.g. input: ("hello hello world"); output: 3
* e.g. input: ("o um dois tres   quatro"); output: 6
*/
int count_words_string (char str[]){
    
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
* find the greatest word in a given string
@param str - string
@return lenght of the greatest word
* e.g. input: ("hello hello world"); output: 5
* e.g. input: ("o um dois tresquatro"); output: 10
*/
int greatest_word_string (char str[]){
    
    int count = 0, max = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){   //melhorar condicao
        
            if(count > max){
                max = count;
            }
            count = 0;
        }
        else count++;
    }
    if(count > max)
        max = count;
    
    return max;
}

/**
* multiply matrix by scalar
@param m - matrix to be multiplied
@param lines - number of matrix lines
@param scalar - multiplier
* e.g. input: ([[5, 8], [4, 3]], 3); output: [[15, 24], [12, 9]]
*/
void multiply_matrix_by_scalar (int m[l][col], int lines, int columns, int scalar){
    
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

/**
* multiply two matrices
@param mA100 - matrix A
@param mB100 - matrix B
@param mC100 - matrix to store the result
@param linesA - number of lines in matrix A
@param columnsB - number of columns in matrix B
*/
void multiply_matrixesNxMAXCOLS100(int mA100[][MAXCOLS100], int mB100[][MAXCOLS100], int mC100[][MAXCOLS100], int linesA, int columnsB){
    
    
    for (int i = 0; i < linesA; i++) {
        
        for (int j = 0; j < columnsB; j++) {
            
            mC100[i][j] = mA100[i][j]*mB100[i][j];
            
        }
    }
    
    for (int i = 0; i < linesA; i++) {
        
        for (int j = 0; j < columnsB; j++) {
            
            printf("%d ", mC100[i][j]);
            
        }
        printf("\n");
    }
    
}
