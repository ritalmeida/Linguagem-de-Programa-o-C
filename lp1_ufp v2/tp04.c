//
// Created by Rita Vieira de Almeida on 04/10/2021.
//

#include <string.h>
#include "tp04.h"

int main_tp04(int argc, const char * argv[]) {

    /*int a = 5;
    int b = 2;
    printf("%d x %d = %.2f\n", a, b, multiply_recursive(a, b));*/

    //printf("%d", numberOfDigitsRecursive(218));

    /*int n = 5;
    printf("Fatorial de %d = %.2f\n", n, factorial_recursive(n));*/

    /*int n = 2;
    int level = 1;
    print_multable_recursive(n, level);*/

    /*char vowals[MAXSIZEARRAY];
    read_vowels(vowals, MAXSIZEARRAY);*/

    /*char c[] = "Ola meu mundo";
    unsigned long size = strlen(c);
    print_vowels(c, (int)size);*/
    /*int ints[] = {3,7,5,1,2};
    int size = 5;
    printf("Valor maximo: %d\n", max(ints, size));
    printf("Valor minimo: %d\n", min(ints, size));*/
    /*int ints[] = {7, 2, 12, 1, 15, 7, 2, 7, 3, 8};
    int size = 10;
    printf("Media: %.2f\n", mean(ints, size));*/
    int v[] = {5, 2, 2, 3, 4, 4, 4, 4, 1, 1, 2, 2};
    int sizev = 12;
    int p[] = {2, 2};
    int sizep = 2;
    printf("Numero de repeticoes: %d\n", count_segments_repeated_ints(v, sizev, p, sizep));
    return 0;
}

/**
 * Receives an integer and recursively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param a - int number to decompose
 *  @return number of digits of a
 */
int numberOfDigitsRecursive(int a) {

    if (a >= 0 && a <= 9) {
        return 1;
    }
    return 1 + numberOfDigitsRecursive(a/10);
}

/**
 * Multiplies 2 numbers using a recursive algorithm.
 * @param a - fisrt operand
 * @param b - second operand
 * @return the product of a and b
 */
double multiply_recursive(int a, int b) {

    if(b == 0){
        return 0;
    }else{

        return (multiply_recursive(a, b-1) + a);
    }
}

/**
 * Uses a recursive algorithm to calculate the factorial of a number.
 * @param n - the number to calculate the factorial from
 * @return the factorial of the parameter
 */
double factorial_recursive(int n) {

    if(n >= 1){

        return n * factorial_recursive(n-1);
    }else{

        return 1;
    }
}

/**
 * Prints recursively the multiplaction table of a given number.
 * @param n - number to calculate and print the multiplication table
 * @param level - which level of the multiplcation table to print
 */
void print_multable_recursive(int n, int level) {

    if(level > 10){
        return;
    }else{
        printf("%d x %d = %d\n", n, level, (n*level));
        print_multable_recursive(n, (level+1));
    }
}

/**
 * Reads vowels from stdin and stores them inside an array.
 * @param vowels - array where to store the vowels
 * @param size - max size of the array
 * @return number of vowels read
 */
int read_vowels(char vowels[], int size) {

    char c = '\0';
    int i = 0, j = 0;

    printf("Insira uma frase: ");

    while ((c = getchar()) != '\n') {

        if((isVowel(c))){
            vowels[j] = c;
            j++;
        }
    }

    for (i = 0; i < j; i++) {

        printf("%c ", vowels[i]);
    }
    printf("\n");

    return 0;
}

/**
 * Prints the vowels inside an array of chars.
 * @param vowels - array of vowels
 * @param size - max size of the array
 */
void print_vowels(char vowels[], int size) {

    for (int i = 0; i < size; i++) {

        if(isVowel(vowels[i])){
            printf("%c ", vowels[i]);
        }
    }
    printf("\n");
}

/**
 * Search an array of ints to find the max value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the max value inside the array
 */
int max(int ints[], int size) {

    int maximo = 0, aux;

    for (int i = 0; i < size; i++) {

        for (int j = 1; j < size; j++) {

            if(ints[i] > ints[j]){
                aux = ints[i];
                if(aux > maximo){
                    maximo = aux;
                }
            }else if(ints[i] < ints[j]){
                aux = ints[j];
                if(aux > maximo){
                    maximo = aux;
                }
            }
        }
    }

    return maximo;
}

/**
 * Search an array of ints to find the min value.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the min value inside the array
 */
int min(int ints[], int size) {

    int minimo = 0, aux;

    for (int i = 0; i < size; i++) {

        for (int j = 1; j < size; j++) {

            if(ints[i] < ints[j]){
                aux = ints[i];
                if(aux > minimo){
                    minimo = aux;
                }
            }else if(ints[i] > ints[j]){
                aux = ints[j];
                if(aux < minimo){
                    minimo = aux;
                }
            }
        }
    }

    return minimo;
}

/**
 * Calculates the mean of an array of ints.
 * @param ints - the array of ints
 * @param size - the number of elements in the array
 * @return the mean of the elements inside the array
 */
float mean(int ints[], int size) {

    float media = 0.0, soma = 0.0;

    for (int i = 0; i < size; i++) {

        soma += ints[i];
    }

    media = (soma / size);

    return media;
}

/** Receives and array of ints and and array with a pattern of numbers to search.
 *  Searches how many segments of the pattern exists inside the array of ints
 *  e.g., v=[5,  2,  2,  3,  4,  4,  4,  4,  1,  1, 2, 2] e p=[2, 2]
 *      would return 2 segments of p exist in v.
 *  @param v - array of ints with patterns of ints
 *  @param sizev - number of elements inside the array
 *  @param r - array with pattern of ints to search
 *  @param sizer - size of the arrray of patterns
 *  @return number of segments p that exist inside the v array
 */
int count_segments_repeated_ints(int v[], int sizev, int r[], int sizer) {

    int count = 0;

    for (int i = 0; i < sizev; i++) {

        for (int j = 0 ; j < sizer; j++) {

            if(v[i] == r[j]){

                i++;
                j++;
                if (v[i] == r[j]) {

                    count++;
                }
            }
        }
    }

    return count;
}