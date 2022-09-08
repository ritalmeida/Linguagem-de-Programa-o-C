//
// Created by Rita Vieira de Almeida on 01/10/2021.
//

#include "pr02.h"

int main_pr02(int argc, const char *argv[]) {

    printf("Aula 1 de outubro de 2021\n\n");
    //printMultiplicationTable(7);
    //printPyramid(5);

    /*int n = 1320;
    printf("The number %d is triangular if %d = 1!\n", n, isNumberTriangular(n));*/

    /*int dec = 10;
    printf("Decimal: %d -> Binary: %d\n", dec, decimalToBinary(dec));*/

    /*int bin = 1010;
    printf("Binary: %d -> Decimal: %d\n", bin, binaryToDecimal(bin));*/

    splitsIntHalf(284);

    return 0;
}

/**
* Prints the multiplication table for a given number
* @param num - input number
* e.g. input: (2) => output: 2x1=2\n2x2=4\n2x3=6 ...
*/
void printMultiplicationTable (int num) {

    for (int i = 1; i <= 10; i++) {

        printf("%d x %d = %d\n", num, i, (num*i));
    }
}

/**
* prints inverted pyramid
* @param width - pyramid's base width
* e.g. input: (5); output: 1 2 3 4 5
*				     		 2 3 4
*				        	   3
*/
void printPyramid (int width) {

    for (int i = 0; i <= width; i++) {

        for (int j = 0; j < i; j++) {       // para o espaço à esquerda

            printf(" ");
        }
        for (int j = i+1; j <= (width - i); j++) {      // comprimento

            printf("%d", j);
        }
        printf("\n");
    }
}

/**
* Checks if a number is triangular, i.e., the product of three consecutive int numbers.
* @param num - number to be checked
* @return - true (0) or false (1)
* e.g. input: (504) => output: is triangular 504 = 7x8x9
* e.g. input: (1320) => output: is triangular 1320 = 10x11x12
*/
int isNumberTriangular (unsigned int num) {

    int res;

    for (int i = 0; i < num; i++) {

        res = i * (i+1) * (i+2);

        if (res == num) {

            return 1;
        } else if(res > num) {

            return 0;
        }
    }
    return 0;
}

/**
* Converts a decimal number to binary
* @param num - decimal number
* @return - binary converted number
* e.g. input: (10); output: 1010
*/
int decimalToBinary (int num) {

    int bin = 0, i = 0;

    while (num != 0) {

        bin += (num % 2) * pow(10, i++);
        num /= 2;
    }

    return bin;
}

/**
* Converts a binary number to decimal
* @param bin - binary number
* @return - decimal converted number
* e.g. input: (1010); output: 10
*/
int binaryToDecimal (int bin) {

    int dec = 0, i = 0, aux;

    while (bin != 0) {

        aux = bin % 10;
        bin /= 10;
        dec += aux * pow(2, i++);
    }

    return dec;
}

/**
* Splits an integer into two halves
* @param n - int number to split in half.
* e.g. input: (284) -> 2 e 4;
* e.g. input: (4587) -> 45 e 87
*/
void splitsIntHalf(int n) {                                                     //NAO TERMINADO

    printf("%d / %d = %d\n", 2021, 100, (2021/100));
    printf("%d %% %d = %d\n", 2021, 100, (2021%100));

    printf("%d / %d = %d\n", 115200, 1000, (115200/1000));
    printf("%d %% %d = %d\n", 115200, 1000, (115200%1000));
}
