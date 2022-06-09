//
//  pr03.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 08/10/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr03.h"

int main_pr03(int argc, const char * argv[]){
    
    
    /*int n = 5;
    int v[] = {1,2,3,4,5};
    printf("soma: %d\n", sum(v, n));*/
    
    /*int n = 4;
    int v[] = {1,4,2,4};
    int num = 4;
    printf("Indice minimo: %d\n", lowest_index_number(v, num, n));
    printf("Indice maximo: %d\n", highest_index_number(v, num, n));
    printf("O numero %d aparece %d vezes!\n", num, count_frequency_number(v, num, n));
    printf("O numero que aparece mais vezes e o %d\n", number_highest_frequency(v, n));*/
    
    /*int a[] = {1,2,3,4};
    int b[] = {1,2,3,5};
    int size = 4;
    int_compare(a, b, size);*/
    
    int v[] = {55, 22, 22, 33, 44, 44, 44, 1, 1};
    int size = 9;
    printf("Tamanho da maior sequencia de ints repetidos: %d\n", size_greatest_segment_repeated_ints(v, size));
    print_unique_numbers(v, size);
    //size_greatest_segment_repeated_ints(v, size);
    
    /*int v1[] = {1, 2, 3, 4, 5};
    int size = 5;
    int v2[size];
    copy_array(v1, v2, size);*/
    
    
    return 0;
}


/**
 sum all elements of a given integer array
 @param ints - integer array
 @param size - array size
 @return - sum of all elements
 e.g. input: ([1, 2, 3, 4, 5], 5); output: 15
*/
int sum(int ints[], int size){
    
    int soma = 0;
    
    for(int i = 0; i < size; i++){
       
        soma += ints[i];
    }
    
    return soma;
}

/**
 searches for the lowest index of a given integer
 @param v - array to be searched
 @param n - number to search
 @param size - array size
 @return - lowest index which contains the integer n
 e.g. input: ([1, 4, 2, 4], 4, 4); output: 1
*/
int lowest_index_number(int v[], int n, int size){
    
    int index = 0;
    
    for (int i = 0; i < size; i++) {
        
        if(v[i] == n){
            index = i;
            break;
        }
    }
    
    return index;
}

/**
 searches for the highest index of a given integer
 @param v - array to be searched
 @param n - number to search
 @param size - array size
 @return - highest index which contains the integer n
 e.g. input: ([1, 4, 2, 4], 4, 4); output: 3
*/
int highest_index_number(int v[], int n, int size){
    
    int index = 0;
    
    for (int i = size; i >= 0; i--) {
        
        if(v[i] == n){
            index = i;
            break;
        }
    }
    
    return index;
}

/**
 counts how many times a given integer appears in a given array
 @param v - array to be searched
 @param n - number to search
 @param size - array size
 @return - number of times n appears in v
 e.g. input: ([1, 4, 2, 4], 4, 4); output: 2
 e.g. input: ([1, 2, 2, 2], 2, 4); output: 3
*/
int count_frequency_number(int v[], int n, int size){
    
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        
        if(v[i] == n){
            count++;
        }
    }
    
    return count;
}

/**
 compare two integer arrays with the same size
 @param a - array for comparison
 @param b - array for comparison
 @param size - size for both arrays
 @return 0 if (a == b) ; -1 if (a < b) ; 1 if (a > b)
 e.g. input: ([1, 2, 3, 4], [1, 2, 3, 5], 4); output: -1
 e.g. input: ([1, 3, 3, 4], [1, 2, 3, 4], 4); output: 1
 e.g. input: ([1, 2, 3, 4], [1, 2, 3, 4], 4); output: 0
*/
int int_compare(int a[], int b[], int size){
    
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
 finds the number with the highest frequency (mode) in a given array
 @param v - array to be searched
 @param size - array size
 @return mode of array
 e.g. input: ([1, 4, 2, 4], 4); output: 4
 e.g. input: ([1, 1, 1, 4], 4); output: 1
*/
int number_highest_frequency(int v[], int size){
    
    int moda = 0;
    int aux[size];
    
    for(int i = 0; i < size; i++){
        
        aux[i] = count_frequency_number(v, v[i], size);
    }
    
    for (int j = 0; j < size; j++) {
        for(int k = 1; k < size; k++){
            if(aux[j] > aux[k]){
                moda = v[j];
            }
        }
    }
    
    return moda;
}

/**
 get the lenght of the greatest sequence of repeated ints
 @param v - array to be searched
 @param size - array size
 @return - lenght of the greatest sequence
 e.g. input: ([55, 22, 22, 33, 44, 44, 44, 1, 1], 9); output: 3
*/
int size_greatest_segment_repeated_ints(int v[], int size){
    
    int count_aux = 1, count = 1, max_count = 0;
    int i;

    if(size == 0)
    {
        return 0;
    }
    else
    {
        for(i=0; i<size-1; i++)
        {
            if(v[i+1] == v[i])
            {
                count ++;

                if (count > count_aux)
                {
                    count_aux = count;
                }
            }
            else
            {
                count_aux = count;
                count = 1;
            }

            if(count > max_count)
                max_count = count;
        }
        return max_count;
    }
}

/*
 recebe array e copia para outro
 @param v1 - array inicializado e preenchido
 @param v2 - array inicializado e nao preenchido
 @param size - tamanho dos arrays
 */
void copy_array(int *v1, int *v2, int size){
    
    
    for(int i = 0; i < size; i++){
        
        v2[i] = v1[i];
    }
    
    printf("v1[] = ");
    for (int j = 0; j < size; j++) {
        
        printf("%d ", v1[j]);
    }
    
    printf("\nv2[] = ");
    for (int j = 0; j < size; j++) {
        
        printf("%d ", v2[j]);
    }
    printf("\n");
}

/**
 
 @param v - array a considerar
 @param n - tamanho do array
 */
void print_unique_numbers(int *v, int n){
    
    int i, j, k, ctr = 0;
    printf("Os elementos unicos no array sao: ");
    for(i = 0; i<n; i++){
        
        ctr = 0;
        for(j = 0,k = n; j < k+1; j++){
            /*Increment the counter when the seaarch value is duplicate.*/
            if (i != j){
               if(v[i]==v[j]){
                 ctr++;
               }
             }
        }
       if(ctr==0){
          printf("%d ",v[i]);
        }
    }
    printf("\n");
}
