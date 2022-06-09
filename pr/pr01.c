//
//  pr01.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 18/09/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "pr01.h"
#include "tp02.h"
#include "tp03.h"

int main_pr01(int argc, const char *argv[]){
    
    /*char c = 'a';
    readCharPrintAscii(c);*/
    
    /*int min = 0, max = 10;
    printPrimeNumbers(min, max);*/
    
    //printDigitOrNot();
    
    /*char c = 'a';
    printf("O caratere %c apareceu %d vezes!\n", c, countInsertedChar(c));*/
    
    //printf("readIntsDivisionFloat(%d, %d): %.2f\n", 10, 3, readIntsDivisionFloat(10, 3));
    
    //printAsciiTableLetters();
    
    //parseCountInStream();
    
    return 0;
}

/**
 * division of two integer values
 * output -> readIntsDivisionFloat(10, 3) : 3.33
 * @param a - dividend
 * @param b - divisor@return - (float) a / b
 */
float readIntsDivisionFloat(int a, int b){              // esta certo!!
    
    float res;
    
    res = (float) a/b;
    
    return res;
}

/**
 * prints ascii table letters from 'a' to 'z' and from 'A' to 'Z'
 * output: |       A       |       65      ||      a       |       97      |  |       B       |       66      ||      b       |       98     |  ...
 */
void printAsciiTableLetters(void){              // esta certo
    
    //printf("%d", 'Z');
    int i;
    
    for(i = 65; i <= 90; i++){
        
        int aux = i + 32;
        
        printf("| %c | %d || %c | %d || ", i, i, aux, aux);
    }
}

/**
 * iteratively counts characters, digits, white spaces and special characters
 * in a user input stream
 * */
void parseCountInStream(void){
    
    char input = '\0';
    int countDigit = 0, countVowel = 0, countConsonant = 0, countWhite = 0, countSpecial = 0;
    
    printf("Insira varios carateres, digitos, espacos brancos, etc: \n");
    
    while((input = getchar()) != '\n'){
        
        if(isVowel(input)){
            countVowel++;
        }else if(isDigit(input)){
            countDigit++;
        }else if(isConsonant(input)){
            countConsonant++;
        }else if(isWhite(input)){
            countWhite++;
        }else
            countSpecial++;
    }
    
    printf("Digitos: %d, Vogais: %d, Consoantes: %d, Carateres brancos: %d, Carateres especiais: %d\n", countDigit, countVowel, countConsonant, countWhite, countSpecial);
}

/**
 * counts how many times a given char appears in an
 * iteratively user entered series of chars
 @param c - char to count
 @return - number of occurrences
 */
int countInsertedChar(char c){
    
    int countChar = 0;
    char input = '\0';
    
    printf("Insira varios carateres seguidos. Para terminar, carrege no ENTER: \n");
    
    while((input = getchar()) != '\n'){

        if(input == c){
            
            countChar++;
        }
    }
    
    return countChar;
}

/**
 * iteratively checks if a user input char is a digit
 * output: '0' is a digit; 'a' is not a digit
 */
void printDigitOrNot(void){         //está certa!!
    
    char input = '\0';
    
    do{
        
        printf("Insira um caratere e prima '.' quando quiser terminar: ");
        scanf(" %c", &input);
        printf("\n");
        
        if(checkIfLetter(input)){
            printf("%c nao e um digito\n\n", input);
        }else if(input >= '0' && input <= '9'){
            printf("%c e um digito\n\n", input);
        }
    }while(input != '.');
        
}

/**
 * print the ascii value of a given character
 * output -> readCharPrintAscii('a') : 97
 * @param c - char to be converted
 */
void readCharPrintAscii(char c){        //está certa!!
    
    printf("o caratere: %c\no respetivo codigo ascii: %d\n\n ", c, c);
}

/**
 * prints all prime numbers between min and max
 * output -> printPrimeNumbers(0, 10) : 2, 3, 5, 7
 * @param min - valor minimo
 * @param max - valor maximo
 * */
void printPrimeNumbers(int min, int max){
 
    /*if((min % min == 0 || min % 1 == 0) && (max % max == 0 || max % 1 == 0)){       //min e maximo sao primos
     
        for(int i = min; i <= max; i++){
            printf("%d ", i);
        }
    }*/
    
    /*int count = 0;
    
    for(int i = min; i <= max; i++){        // ciclo para verificar se numero é primo
        if(i <= 1) continue;
        for(int j = i; j <= i/2; j++){
            if(i % j == 0){
                count++;
            }
        }
    }
    
    if(count == 0){
        //primo
    }
    count = 0;*/
    
    int primo, i, j;
    
    for (i = min; i <= max; i++) {          // ciclo do dividendo
        if (i == 0 || i == 1) {
            primo = 0;
        } else {
            primo = 1;                      // considero inicialmente que o número é primo
            for(j = 2; j < i; j++) {        // ciclo do divisor
                if (i % j == 0) {
                    primo = 0;              // consigo provar que ele não é primo
                }
            }
        }
        if (primo == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

