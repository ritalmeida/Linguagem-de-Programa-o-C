//
//  pr05.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 22/10/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr05.h"
#include "string.h"
#include "math.h"

int main_pr05(int argc, const char * argv[]){
    
    /*int x = 5, y = 7;
    printf("%d %d\n", x, y);
    swap_pxy(&x, &y);
    printf("%d %d\n", x, y);*/
    
    /*double v[]={1,2,3,4};
    double *pi = &v[0];
    for (int i = 0; i < 4; i++) {
        printf("%.1f ", v[i]);
    }
    printf("\n");
    swap_double_array_ptr(pi, 0, 2);
    for (int i = 0; i < 4; i++) {
        printf("%.1f ", v[i]);
    }
    printf("\n");*/
    
    /*double r1;
    double r2;
    calc_roots(2, -14, 20, &r1, &r2);
    printf("r1: %.1f\nr2: %.1f\n", r1, r2);*/
    
    /*int size = 5;
    double a[] = {1.2, 2.3, 3.4, 4.5, 5.1};
    double *ptr = &a[0];
    printf("Unsando o indice: ");
    print_array_double_with_index(ptr, size);
    printf("\nSem o indice: ");
    print_array_double_without_index(ptr, size);
    printf("\n\n");*/
    
    /*char str[] = "HELLO WORLD";
    char *ptr = &str[0];
    printf("%d \n", strlen_ptr(ptr));*/
    
    int a[] = {11, 23, -1, 7};
    int minmaxa[2];
    int *pi = &a[0];
    int *minmax = &minmaxa[0];
    search_minmax(pi, 4, minmax);
    for (int i = 0; i < 2; i++) {
        printf("%d ", minmaxa[i]);
    }
    printf("\n");
    
    //init_and_print_alphabet();
    
    
    return 0;
}

/**
* swap values of x and y
@param px - pointer to x
@param py - pointer to y
*/
void swap_pxy(int* px, int* py){
    
    int aux;
    aux = *px;
    *px = *py;
    *py = aux;
}

/**
* swap two positions of a given double array, using pointer notation
@param pi - pointer to the first position of the double array
@param pos1 - position 1
@param pos2 - position 2
@return array after swap
* i.e. input: ((1, 2, 3, 4), 0, 2); output: (3, 2, 1, 4)
*/
double* swap_double_array_ptr(double* pi, int pos1, int pos2){
    
    double aux;
    aux = *(pi + pos1);
    *(pi + pos1) = *(pi + pos2);
    *(pi + pos2) = aux;

    return pi;
}


/**
* calc the roots of a 2º grade polinomial ax^2 + bx + c
@param a - retreived from ax^2
@param b - retreived from bx
@param c - retreived from c
@param r1 - first root
@param r2 - second root
* i.e. input: (2, -14, 20, &r1, &r2); output: r1=5.00, r2=2.00
*/
void calc_roots(int a, int b, int c, double* r1, double* r2){
    
    *r1 = (-b + sqrt(pow(b, 2) - (4*a*c)))/(2*a);
    *r2 = (-b - sqrt(pow(b, 2) - (4*a*c)))/(2*a);
}

/**
* prints all the elements in a given double array
@param pi - pointer to the first position of the given array
@param size - array size
*/
void print_array_double_with_index(double *pi, int size){
    
    for (int i = 0; i < size; i++) {
        
        printf("%.1f ", *(pi+i));
    }
    printf("\n");
}

/**
* prints all the elements in a given double array, without using an index var to iterate the array
@param pi - pointer to the first position of the given array
@param size - array size
*/
void print_array_double_without_index(double *pi, int size){
    
    double *curr;
    
    for (curr = pi; curr < pi+size; curr++) {
        
        printf("%.1f ", *curr);
        
        
    }
}

/**
* strlen implementation using pointer notation. Calculates the length of a string
@param ps - pointer to the first position of the given string
@return string length
* i.e. input: ("hello world"); output: 11
*/
int strlen_ptr(char* ps){
    
    int size = 0;

    while (*ps) {
        
        *ps++;
        size++;
    }
    return size;
}

/**
* find the highest and lowest numbers in a given array
@param pi - pointer to the first position of the given array
@param size - array size
@param maxmin - pointer to the first position of the maxmin array
@return maxmin array
* i.e. input: (11, 23, -1, 7); output: (-1, 23)
*/
int* search_minmax(int *pi, int size, int *maxmin){
   
    int max = -1000, min = 1000;
    
    for (int i = 0; i < size; i++) {
        
        if(*pi > max){
            max = *pi;
        }else if(*pi < min){
            min = *pi;
        }
        pi++;
    }
    
        
    *maxmin = min;
    *(maxmin+1) = max;
    
    return maxmin;
}


/**
* stores the 26 characters of the alphabet in a string and prints them using pointer notation
*/
void init_and_print_alphabet (void){
    
    char abc[26];
    char *ptr = &abc[0];
    
    printf("Alfabeto: ");
    for (int i = 0; i < 26; i++) {
        
        scanf("%c", &(*(ptr+i)));
    }
    
    for (int i = 0; i < 26; i++) {
        
        printf("%c", *(ptr+i));
    }
    printf("\n");
}
