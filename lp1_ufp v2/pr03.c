//
// Created by Rita Vieira de Almeida on 11/10/2021.
//

#include "pr03.h"



int main_pr03(int argc, const char * argv[]) {

    //print_hangman_recursive(6);

    /*int a[] = {30, 41, 41, 18, 24, 24, 4, 12};
    int size = 8;
    printf("%d", countClumps(a, size));*/

    /*int b = 2, e = 5;
    printf("%d x %d = %f", b, e, powRecursive(b, e));*/

    /*int n = 5;
    int v[] = {1,2,3,4,5};
    printf("soma: %d\n", sum(v, n));*/

    /*int a[] = {1,2,3,4};
    int b[] = {1,2,3,5};
    int size = 4;
    intCompare(a, b, size);*/

    int n = 4;
    int v[] = {1,4,2,4};
    int num = 4;
    printf("O numero %d aparece %d vezes!\n", num, countFrequencyNumber(v, num, n));
    printf("O numero que aparece mais vezes e o %d\n", numberHighestFrequency(v, n));

    return 0;
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
* count the number of clumps (a series of 2 or more adjacent equal
* elements)  in a given array
* @param a - array to be searched
* @param size - array size
* @return - number of clumps
* e.g. input: ([30, 41, 41, 18, 24, 24, 4, 12], 8); output: 2
* e.g. input: ([30, 41, 42, 18, 24, 24, 24, 12], 8); output: 1
* e.g. input: ([30, 41, 42, 18, 24, 25 , 4, 12], 8); output: 0
*/
int countClumps(int a[], int size) {

    int current = -1, clump = 0;
    for(int i = 0; i < size - 1; i++) {

        if(a[i] == a[i + 1] && a[i] != current) {

            current = a[i];
            clump++;
        }
        else {

            if(a[i] != current) {

                current = -1;
            }
        }
    }
    return clump;
}

/**
* recursively raises b to the power of e
* @param b - base
* @param e - exponent
* @returns b^e
* e.g. input: (2, 5); output: 32
* e.g. input: (10, 1); output: 10
* e.g. input: (3, 0); output: 1
*/
double powRecursive(int b, int e) {

    if(e == 0) return 1;
    return b * powRecursive(b, e - 1);
}

/**
* sum all elements of a given integer array
* @param ints - integer array
* @param size - array size
* @return - sum of all elements
* e.g. input: ([1, 2, 3, 4, 5], 5); output: 15
*/
int sum (int ints[], int size) {

    int soma = 0;

    for(int i = 0; i < size; i++){

        soma += ints[i];
    }

    return soma;
}

/**
* compare two integer arrays with the same size
* @param a - array for comparison
* @param b - array for comparison
* @param size - size for both arrays
* @return - 0 if (a == b) ; -1 if (a < b) ; 1 if (a > b)
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 5], 4); output: -1
* e.g. input: ([1, 3, 3, 4], [1, 2, 3, 4], 4); output: 1
* e.g. input: ([1, 2, 3, 4], [1, 2, 3, 4], 4); output: 0
*/
int intCompare (int a[], int b[], int size) {

    int somaa = 0, somab = 0;

    somaa = sum(a, size);
    somab = sum(b, size);

    if(somaa > somab)
        printf("1\n");
    if(somaa < somab)
        printf("-1\n");
    if (somaa == somab)
        printf("0\n");

    return 0;
}

/**
* counts how many times a given integer appears in a given array
* @param a - array to be searched
* @param n - number to search
* @param size - array size
* @return - number of times n appears in v
* e.g. input: ([1, 4, 2, 4], 4, 4); output: 2
* e.g. input: ([1, 2, 2, 2], 2, 4); output: 3
*/
int countFrequencyNumber (int a[], int n, int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {

        if(a[i] == n){
            count++;
        }
    }

    return count;
}

/**
* finds the number with the highest frequency (mode) in a given array
* @param a - array to be searched
* @param size - array size
* @return - mode of array
* e.g. input: ([1, 4, 2, 4], 4); output: 4
* e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int numberHighestFrequency (int a[], int size) {

    int moda = 0;
    int aux[size];

    for(int i = 0; i < size; i++){

        aux[i] = countFrequencyNumber(a, a[i], size);
    }

    for (int j = 0; j < size; j++) {
        for(int k = 1; k < size; k++){
            if(aux[j] > aux[k]){
                moda = a[j];
            }
        }
    }

    return moda;
}