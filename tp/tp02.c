//
//  tp02.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 21/09/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

// Direttivas pré  processador
#include "tp02.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#define MAX128 128

int main_tp02(int argc, const char * argv[]){
    
    //printPrimitiveDataTypesSizeLimits();
    /*char c = 'A';
    printf("Char %c e letra se 1 = %d\n", c, checkIfLetter(c));*/
    guessSecreteChar();
    return 0;
}

/**
 * Imprimir uma tabela com o nome dos tipos de dados primitivos e respectivos:
 * | nº bits (sizeof()) | nº bytes (sizeof()/8) | valor máximo | valor mínimo.
 */
void printPrimitiveDataTypesSizeLimits(void){
    
    int bits = 0;
    int bytes = 0;
    double limit = 0;
    
    bytes = sizeof(char);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    
    printf("CHAR\n num bits: %d | num bytes: %d | valor minimo: %f | valor maximo: %f\n", bits, bytes, limit-1, limit*-1);
    
    bytes = sizeof(short);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    
    printf("SHORT\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n", bits, bytes, limit-1, limit*-1);

    bytes = sizeof(int);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    
    printf("INT\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n", bits, bytes, limit-1, limit*-1);
    
    bytes = sizeof(long);
    bits = 8 * bytes;
    
    printf("LONG\n num bits: %d | num bytes: %d | valor maximo: %0.0lld | valor minimo: %0.0lld\n", bits, bytes, LLONG_MIN, LLONG_MAX);
    
    bytes = sizeof(float);
    bits = 8 * bytes;
    
    printf("FLOAT\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n", bits, bytes, FLT_MIN, FLT_MAX);
    
    bytes = sizeof(double);
    bits = 8 * bytes;

    printf("DOUBLE\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n", bits, bytes, DBL_MIN, DBL_MAX);
}

/**
 * Checks if a given char is an alphabet letter (a..z / A..Z).
 * Returns 1 (true) if so, 0 (false) otherwise.
 */
int checkIfLetter(char c){
    
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        
        return 1;
    }
    
    return 0;
}

/**
 * Game for 2 players:
 * 1st player: inserts a secret char ('a'..'z' || 'A'..'Z') followed by clean screen (system('clear');).
 * 2nd player: guesses the secret char; after hiting the char, prints it and the number of guesses.
 */
void guessSecreteChar(void){
    
    char caratGuess = '\0', caratSecret = '\0';
    int countGuess = 1;

    do{
        printf("Adivinhe a letra: ");
        scanf(" %c", &caratSecret);
        
        if(checkIfLetter(caratSecret)) {
            break;
        }else{
            printf("Nao e uma letra! ");
        }

    }while (1);
    
    do{
        
        printf("\nAdivinhe o carater: ");
        scanf(" %c", &caratGuess);
        
        if(caratGuess == caratSecret){
            break;
        }
        printf("\nTente novamente!\n");
        countGuess++;
        
    }while(1);
    
    printf("\nParabens!! O caratere secreto era %c! Demorou %d tentativas!!\n\n", caratSecret, countGuess);
}
