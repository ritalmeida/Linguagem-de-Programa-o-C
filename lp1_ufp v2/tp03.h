//
// Created by Rita Vieira de Almeida on 27/09/2021.
//

#ifndef LP1_TP03_H
#define LP1_TP03_H

#include <stdio.h>
#include <stdlib.h>

int main_tp03(int argc, const char *argv[]);

/**
 * Verifica se o carater é um digito
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isDigit(char c);                                            //FEITO!!

/**
 * Verifica se o carater é uma vogal
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isVowel(char c);                                            //FEITO!!

/**
 * Verifica se carater é consoante
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isConsonant(char c);                                            //FEITO!!

/**
 * Verifica se carater é um espaço branco
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isWhite(char c);                                                        //FEITO!!

/**
 * Ler em ciclo uma tecla seguida por \n (Terminar com '.') e para cada tecla
 * retorna imprime %c - is digit | not digit.
 */
void readKeysPressedPrintDigits();                                              //FEITO!!

/**
 * This function prints a char type: digit, vowel, consonant, special.
 * @param c - the char to be checked.
 */
void printKeyType(char c);                                                       //FEITO!!

/**
 * Receber um inteiro e retornar iterativamente o numero de dígitos
 *  @param n - o inteiro que vamos analizar
 *  @return o numero de digitos encontrados em n
 */
int numberOfDigitsIterative(int n);                                                 //FEITO!!


/*** Receives an integer and iteratively counts the frequency of odd and even digits
 * e.g. 218 2 = returns frequency of even digits = 3 (because > frequency of odd).
 * @param n - integer number;
 * @return even or odd digits highest frequency.
 */
short highestEvenOrOddDigitsFrequency(int n);                               //FEITO!!

/**
 * Receives an integer and iteratively returns the highest frequency of digit,
 * e.g. 218 2 = returns digit 2 which has highest frequency.
 * @param n - integer number;
 * @return digit with highest frequency.
 */
int highestFrequencyDigit(int n);                                           //FEITO!!

/**
 * quantas palavras até metermos o enter. qualquer conjunto de carateres sem ser o white
 * @return
 */
int countDigitsStdin();                                                         //FEITO!!

#endif //LP1_TP03_H
