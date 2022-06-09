//
//  tp06.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 19/10/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "tp06.h"
#include "string.h"
 
int main_tp06(int argc, const char * argv[]){
    
    /*int x = 10;
    printf("a = %d\n", x);
    double_xy(x);
    printf("a = %d\n", x);*/
    
    /*int x = 10;
    int *p = &x;
    printf("a = %d\n", x);
    double_pxy(p);
    printf("a = %d\n", x);*/
    
    //int a[10] = {1,2,3,4};
    
    /*int *p= NULL;
    printf("a[%d] = %d\n", 2, a[2]);
    print_array_ints_ptr(p, size);*/
    
    //print_array("a[%d] \n", double_array_ints_ptr(a, 10));       //a ou &a[0]
    
    int a[4] = {1,2,3,4};
    int *ptr = &a[0];
    print_array_ints_ptr(ptr, 4);
    
    
    return 0;
}

/**
 * Função simples que calculo a dobro de um parâmetro passado por valor.
 * @param x - valor que se pretende mudar para o dobro.
 */
void double_xy(int x){          //passagem por valor
    
    x = 2 * x;
}
/**
 * Função simples que calculo a dobro de um parâmetro passado por referência.
 * @param px - apontador para uma variável que se pretende mudar para o dobro.
 */
void double_pxy(int *px){       //passagem por referencia
    
    (*px) = 2 * (*px);
}

/**
 * Função que imprime o valor de cada elemento de um array.
 * Ao percorrer o array demosntrar a utilização da notação de *(p++)
 * @param pi - apontador para o 1º elemento do array.
 * @param size - número de elementos do array.
 * */
void print_array_ints_ptr(int* pi, int size){
    
    for (int i = 0; i < size; i++) {
        
        printf("%d ", *(pi+i));
    
    }
}

/**
 * Função que calcula o dobro de cada elemento de um array.
 * Ao percorrer o array demosntrar a utilização da notação *(pd+i).
 * @param pi - apontador para o 1º elemento do array.
 * @param size - número de elementos do array.
 * @return endereço do 1º elemento do array.
 * */
int* double_array_ints_ptr(int* pi, int size){ //Usar *(pi+ i)

    for(int i = 0; i < size; i++){
        
        // p+i -> &a[i]
        *(pi+i) *= 2;           //ou *(pi + i) = *(pi + i) * 2;
    }
    return pi;
}

/**
 * Função que recebe uma str e uma sub, para eliminar a primeira
 * ocorrência da sub dentro de str (mas usando apontadores).
 * @param pstr - endereço do char inicial da string.
 * @param psub - endereço do char inicial da sub-string.
 * @return endereço da string modificada.
 */
char* del_substr(char *pstr, char *psub){
    
    int k = 0;
    
    for (int i = 0;*(pstr + i) != '\0'; i++) {                  //*(pstr + i) = str[i]
        
        if(*(pstr+i) == *(pstr+0)){                              //str[i] = sub[0]
            
            for (k = 1; *(psub+k) != '\0'; k++) {
                
                if(*(psub+k) == *(pstr+i+k)){
                    continue;
                }else{
                    break;
                }
            }
        }
        if (k == strlen(psub)) {
            
            int j = 0;
            for(j = 0; j < strlen(psub); j++){
                
                *(pstr +i+j) = *(pstr+i+j+k);
            }
        }
    }
    
    return pstr;
}

/**
 * Função que recebe uma str e uma sub, para eliminar todas as
 * ocorrências de sub dentro de str (mas usando apontadores).
 * @param pstr - endereço do char inicial da string.
 * @param psub - endereço do char inicial da sub-string.
 * @return endereço da string modificada.
 */
char* del_allsubstr(char *pstr, char *psub);

/**
 * Função que concatena uma string org a outra string dest (usando notação apontador).
 * Versão usando:
 *   char *ps1= pdest + strlen(pdest), *ps2 = porg + strlen(porg);
 *   while(*ps1!='\0') { ps1++ e ps2++; }
 * @param pdest - apontador para a string destino.
 * @param porg - apontador para a string origem.
 * @return endereço da string destino.
 */
char* strcat_ptr1(char *pdest, char *porg);

/**
 * Função que concatena uma string org a outra string dest (usando notação apontador).
 * Versão usando:
 *   int i=0, size1= strlen(pdest), size2=strlen(porg);
 *   for(i=0;i<=size2;i++) {  ...  }
 * @param pdest - apontador para a string destino.
 * @param porg - apontador para a string origem.
 * @return endereço da string destino.
 */
char* strcat_ptr2(char *pdest, char *porg);
