//
//  tp02.h
//  lp1_ufp
//
//  Created by Rui on 26/09/17.
//  Copyright © 2017 Rui. All rights reserved.
//
//  Revised:
//  * 21/09/2020: add summary for the class
//  ==========================================================================
//  1. Introdução à programação em C
//  1.1. Ambiente de programação
//  1.1.3. Ciclo de desenvolvimento
//  1.1.4. Execução de programas
//  1.2. Conceitos básicos em C
//  1.2.1. Estrutura dos programas
//  1.2.2. Entrada e saída de dados básica
//  1.3. Variáveis e tipos de dados
//  1.3.1. Tipos de dados primitivos
//  1.3.2. Declaração e atribuição
//  1.3.3. Operadores e expressões
//  Exercícios introdutórios de I/O e manipulação de dados.
//  ==========================================================================

#ifndef tp02_h
#define tp02_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

/**
 * Imprimir uma tabela com o nome dos tipos de dados primitivos e respectivos:
 * | nº bits (sizeof()) | nº bytes (sizeof()/8) | valor máximo | valor mínimo.
 */
void printPrimitiveDataTypesSizeLimits(void);                   //feito

/**
 * Checks if a given char is an alphabet letter (a..z / A..Z).
 * Returns 1 (true) if so, 0 (false) otherwise.
 */
int checkIfLetter(char c);                                      //feito

/**
 * Game for 2 players:
 * 1st player: inserts a secret char ('a'..'z' || 'A'..'Z') followed by clean screen (system('clear');).
 * 2nd player: guesses the secret char; after hiting the char, prints it and the number of guesses.
 */
void guessSecreteChar(void);                                    //feito

int main_tp02(int argc, const char * argv[]);

#endif /* tp02_h */
