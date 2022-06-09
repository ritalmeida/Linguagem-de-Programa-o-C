//
//  tp07e08.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 09/11/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "tp07e08.h"

int main_tp07e08(int argc, const char * argv[]){
    
    
    /*char m1[MAX128][MAX128];
    char m2[MAX128][MAX128];
    count_consonants(4, argv, m1, m2);*/
    
    int **ppi = NULL;
    ppi = create_dynmatrix_ints(10, 10);
    
    return 0;
}

//===================== tp07.h =====================

/** Implemente função que recebe argc/argv e invoca várias funções para:
 * i) Usar 2 matrizes 2D de chars, a primeira para armazenar uma copia das strings
 * do argv e a segunda para armazenar apenas as consoantes dessas strings;
 * ii) TPC: ordenar de forma crescente as strings e respectivas consoantes, em função
 * do número de consoantes;
 * iii) imprimir as strings e respectivo número de consoantes.
 * e.g. $ prog um quatro nove ----> um (1 consoante), nove (2 consoantes), quatro (3 consoantes)
 */
void count_consonants(int c, const char *astr[], char strings[][MAX128], char consonants[][MAX128]){
    
    int k = 0;
    
    for (int line = 0; line < c; line++) {
        
        strcpy(strings[line], astr[line]);
        
        for (int col = 0; strings[line][col] != '\0'; col++) {
            
            if(isConsonant(strings[line][col])){
                
                consonants[line][k++] = strings[line][col];
            }
        }
        
        consonants[line][k++] = '\0';
        printf("Nº consoantes consonants[%d] = %s -> %d\n", line, consonants[line], k);
    }
}

//TPC

/** Desenvolver uma função que recebe um array de strings e imprime apenas as
 * que não se repetem, e.g., dadas as strings abaixo
 * char *mstrs[] = { ""aa"", ""bbb"", ""ccc"", ""aa"", ""ccc"", ""ddd"" };
 * imprime apenas "bbb" e "ddd"
 */

/*
void print_non_repeated_strs(const char *astr[], int size){
    
    
}*/


/** Checks if str exists into astr before position i.
 * @param str - string to check.
 * @param argv - array of strings to be cheked against.
 * @param line - position before which to check.
 * @return 0 (false) or 1 (true).
 */
int str_exists_before(const char str[], const char *argv[], int line){
    
    return 0;
}



//===================== tp08.h =====================

/**
* Função para criar uma matriz dinâmica de ints;
*  i) malloc dyn array int* (correspondente ao array de  apontadores para int)
*  ii) ciclo para malloc dos vários arrays dinâmicos de int
*/
int** create_dynmatrix_ints(int lines, int columns){
    
    int **pp = (int**) malloc(sizeof(int*) * lines);
    
    for (int i = 0; i < lines; i++) {
        
        int *p = (int*) malloc(sizeof(int) * columns);
       
        *(pp+i) = p;
    }
    
    return pp;
}

/** Função para imprimir a matriz dinâmica de floats
 * @param ppints - apontador para a matriz de inteiros;
 * @param lines - número de linhas;
 * @param columns - número de colunas;
 */
void print_dynmatrix_ints(int **ppints, int lines, int columns){
    
    for (int l = 0; l < lines; l++) {
        
        for (int c = 0; c < columns; c++) {
            
            printf("%d\t", *(*(ppints + l) + c));
        }
        printf("\n");
    }
}

//TPC

/** Função para mudar um valor existente nas células da matriz dinâmica de ints, por outro novo valor.
 * @param ppints - apontador para a matriz de inteiros;
 * @param lines - número de linhas;
 * @param columns - número de colunas;
 * @param value - valor a mudar.
 * @param newvalue - novo valor.
 */
void set_dynmatrix_ints(int **ppints, int lines, int columns, int value, int newvalue){
    
    
}

/** Função para libertar memória de uma matriz dinâmica de ints
 * @param ppints - apontador para a matriz de inteiros;
 * @param lines - número de linhas;
 * @param columns - número de colunas.
 */
void free_dynmatrix_ints(int **ppints, int lines){
    
    for (int l = 0; l < lines; l++) {
        
        //free cada int[]
        free(*(ppints + l));
    }
    //free do int**
    free(ppints);
}
