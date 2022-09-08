//
// Created by Rita Vieira de Almeida on 20/09/2021.
//

#ifndef LP1_TP02_H
#define LP1_TP02_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main_tp02(int argc, const char *argv[]);

/**
 * Imprimir uma tabela com o nome dos tipos de dados primitivos e respetivos:
 * | nº bits (sizeof()) | nº bytes (sizeof()/8) | valor máximo | valor mínimo.
 */
void printPrimitiveDataTypesSizeLimits();               //FEITO

/**
 * Verifica se um dado char é uma letra (a...z/A...Z)
 * @param c char dado
 * @return 1 se verdadeiro. 0 se falso.
 */
int checkIfLetter(char c);                              //FEITO


void guessSecretChar();                             //FEITO!!


#endif //LP1_TP02_H
