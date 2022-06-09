//
//  pr02.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 01/10/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr02.h"
#include "tp03.h"

int main_pr02(int argc, const char *argv[]){
    
    //printf("\n%d\n\n", readDigitsToInt());
    
    int n = 218, size = 3;
    printNumberClassesUnitsToUpperClasses(n);
    printNumberClassesFromHigherToUnits(n, size);
    printNumberClassesFromHigherToUnitsRecursive(n);
    
    /*int num = 10;
    printf("Decimal para binario: %d -> %d\n", num, decimalToBinary(num));
    
    int bin = 1010;
    printf("Binario para decimal: %d -> %d\n\n", bin, binaryToDecimal(bin));*/
    
    /*int a = 10, b = 4;
    printf("%d x %d = %d \n", a, b, multiplication(a, b));*/
    
    /*int num = 7;
    printf("Tabuada do %d: \n", num);
    printMultiplicationTable(num);*/
    
    /*int num = 6;
    printf("%d e triangular se %d = 1!!\n", num, isNumberTriangular(num));*/
    
    /*int width = 10;
    printPyramid (width);*/
    
    /*float f = 2.59;
    floatToHoursMinutes(f);*/
    
    return 0;
}

/**
    * Iteratively reads chars (from '0' to '9') and returns the complete decimal number
    * @return - decimal number
    * e.g. input: ('2', '1', '8', 'e') => output: 218
    * e.g. input: ('4', '3', 'e') => output: 43
 */
int readDigitsToInt(void){
    
    char c = '\0';
    int num = 0;
    
    printf("Input: ");
    while ((c = getchar()) != 'e') {
        
        if(c >= '0' && c <= '9'){
            
            num *= 10;
            num += c - '0';
        }
    }
    return num;
}

/**
    * splits a number and prints each class in an ascending order
    * @param n - decimal value to be splited
    * e.g. input: (218); output => 8, 1, 2
*/
void printNumberClassesUnitsToUpperClasses(int n){
    
    /*int resto = 0;
    
    while (n != 0) {
        
        resto = n % 10;
        n = n / 10;
        printf("%d ", resto);
    }*/
    while (n != 0) {
        printf("%d ", (n % 10));
        n /= 10;
    }
    printf("\n");
}

/**
    * Converts a decimal number to binary
    * @param num - decimal number
    * @return - binary converted number
    * e.g. input: (10); output: 1010
*/
int decimalToBinary (int num){
    
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
int binaryToDecimal (int bin){
    
    int dec = 0, i = 0, aux = 0;
    
    while (bin != 0) {
        
        aux = bin % 10;
        bin /= 10;
        dec += aux * pow(2, i++);
    }

    return dec;
}

/**
    * iteratively multiplies two numbers by unfolding the multiplication into sums
    * @param a - num to be multiplied
    * @param b - multiplier
    * @return - multilpication result
    * e.g. input: (2, 5) => output: 10
*/
int multiplication (int a, int b){
    
    int res = 0;
    
    for(int i = 0; i < b; i++){
        
        res += a;
    }
    
    return res;
}

/**
    * prints the multiplication table for a given number
    * @param num - input number
    * e.g. input: (2) => output: 2x1=2\n2x2=4\n2x3=6 ...
*/
void printMultiplicationTable (int num){            //feito
    
    for(int i = 0; i <= 10; i++){
        printf("%d x %d = %d\n", num, i, multiplication(num, i));
    }
}

/**
    * checks if a number is a product of three consecutive numbers
    * @param num - number to be checked
    * @return - true (0) or false (1)
    * e.g. input: (504) => output: is triangular 504 = 7x8x9
    * e.g. input: (1320) => output: is triangular 1320 = 10x11x12
*/
int isNumberTriangular (unsigned int num){
    
    int calc = 0;
    
    for(int i = 0; i < num; i++){
        
        calc = i * (i+1) * (i+2);
        
        if(calc == num){
            return 1;   //true
        }else if(calc > num){
            return 0;
        }
    }
    
    return 0;
}

/**
    * prints inverted pyramid
    * @param width - pyramid's base width
    * e.g. input: (5); output: 1 2 3 4 5
    *                             2 3 4
    *                               3
*/
void printPyramid (int width){                      //feito
    
    int i, j;

    for (i = 0; i <= width / 2; i++) {                      //altura

        for(j = 0; j < i; j++) {

            printf("  ");
        }
            for (j = i + 1; j <= (width - i); j++) {       //comprimento

                printf("%d ", j);
            }
        printf("\n");
    }
}

/**
    * receives a float in format hh.mm and splits it into hours and minutes
    * @param f - hour in format hh.mm
    * input: (2.59); output: 2h, 59 min
*/
void floatToHoursMinutes(float f){
    
    int hh = (int) f;
    int mm = ((f - hh) * 100) + 1;
    printf("%d hh, %d mm\n", hh, mm);
}

/**
    * splits a number and prints each class in a descending order
    * @param n - decimal value to be splited
    * e.g. input: (218); output => 2, 1, 8
*/
void printNumberClassesFromHigherToUnits(int n, int size){
    
    int aux = 0, i = 0;
    
    int arr[size];
    
    while(n != 0){
        aux = n % 10;
        arr[i] = aux;
        n /=10;
        i++;
    }
    
    for(int j = (size-1); j >= 0; j--){
        
        printf("%d ", arr[j]);
    }
    
    printf("\n");
}

void printNumberClassesFromHigherToUnitsRecursive (int n){
    
    if(n == 0) return;
    printNumberClassesFromHigherToUnitsRecursive(n/10);
    printf("%d ", n%10);
}
