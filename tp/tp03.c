//
//  tp03.c
//  lp1_ufp
//
//  Created by Rita Vieira Almeida on 28/09/2020.
//  Copyright © 2020 Rita Vieira Almeida. All rights reserved.
//

#include "tp03.h"


int main_tp03(int argc, const char * argv[]){
 
    //char c = 'R';
    
    //printf("%c e digito se %d = 1 \n", c, isDigit(c));
    
    //readKeysPressedPrintDigits();
    
    //printf("%c e vogal se %d = 1 \n", c ,isVowel(c));
    //printf("%c e consoante se %d = 1 \n", c, isConsonant(c));
    //printf("%c e carater branco se %d = 1 \n", c, isWhite(c));
    
    //printKeyType(c);
    
    //readKeysPressedPrintKeyType();
    
    //printf("Tem %d palavra(s)!\n", countWordsStdin());
    
    int a = 218;
    numberOfDigitsIterative(a);
    
    return 0;
}

/**
 * This function checks if a char is a digit or not.
 * @param c - char to be checked.
 * @return 1 (if is digit); 0 otherwise.
 */
int isDigit(char c){
    
    if(c >= '0' && c <= '9'){
        return 1;
    }
    return 0;
}

/**
 * Ler em ciclo uma tecla seguida por \n (Terminar com '.') e para cada tecla
 * retorna imprime %c - is digit | not digit.
 */
void readKeysPressedPrintDigits(void){
    
    char c = '\0';
    
    printf("Pressione uma tecla e prima enter! Quando quiser terminar, carrege em . (ponto final): \n");
    
    do{
        printf("Carater: ");
        scanf(" %c", &c);
        if(isDigit(c)){
            printf("%c e digito!\n", c);
        }
        else printf("%c nao e digito!\n", c);
    }while (c != '.');
}

/**
 * This function checks if a char is a vowel.
 * @param c - the char to be checked.
 * @return 1 (if is vowel: 'a' 'e' | 'i' | 'o' | 'u'); 0 otherwise.
 */
int isVowel(char c){
    
    //char x = tolower(c); -> poe carateres em minusculas
    
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
        return 1;
    }
    return 0;
}

/**
 * This function checks if a char is a consonante.
 * @param c - the char to be checked.
 * @return 1  (if is consonant); 0 otherwise.
 */
int isConsonant(char c){
    
    if((!isVowel(c)) && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))){
        return 1;
    }
    return 0;
}

/**
 * This function checks if a char is a white/invisible.
 * @param c - the char to be checked.
 * @return 1 (if is white char: ' ' '\t' | '\n' | '\r'); 0 otherwise.
 */
int isWhite(char c){
    
    if(c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\0'){
        return 1;
    }
    return 0;
}


/**
 * This function prints a char type: digit, vowel, consonant, special.
 * @param c - the char to be checked.
 */
void printKeyType(char c){
    
    if(isDigit(c)){
        printf("O caratere %c e um digito\n", c);
    }else if(isVowel(c)){
        printf("O caratere %c e uma vogal\n", c);
    }else if(isConsonant(c)){
        printf("O caratere %c e uma consoante\n", c);
    }else if(isWhite(c)){
        printf("O caratere %c e branco\n", c);
    }
    
}

/**
 * Esta função deverá ler em ciclo uma tecla seguida por \n (Terminar com '.')
 * e para cada tecla imprimir o tipo de caracter, i.e.
 * digito =  %d", "vogal = %c", "consoante = %c", "outro = %c".
 */
void readKeysPressedPrintKeyType(void){
    
    char c = '\0';
    
    printf("Insira uma tecla e prima enter! Para terminar o ciclo, carrege na tecla . (ponto final): \n");
    
    do{
        
        printf("Caratere: ");
        scanf(" %c", &c);
        
        if(isDigit(c)){
            printf("digito = %c\n", c);
        }else if(isVowel(c)){
            printf("vogal = %c\n", c);
        }else if(isConsonant(c)){
            printf("consoante = %c\n", c);
        }else
            printf("outro = %c\n", c);
        
    }while(c != '.');
}

/**
 * This function read characters from stdin (WITHOUT using strings) managing only input from
 * the keyboard buffer and counting the number of words (set of chars separated by whitespaces, i.e.
 * {' ', '\t', '\n', '\r'}.
 */
int countWordsStdin(void){
    
    char c = '\0';
    int count = 0;
    int dentroPalavra = 0;  //tipo booleano
    
    printf("Insira uma frase e termine com ENTER: ");
    
    while((c = getchar()) != '\n'){
       
        /*if((isWhite(c) == 1) && (dentroPalavra == 1)){              //sair da palavra
            count++;
            if(c == '\n'){
                count++;
            }
            dentroPalavra = 0;
        }else if((isWhite(c) == 0) && (dentroPalavra == 0)){        //entrar na palavra
            dentroPalavra = 1;
        }else if((isWhite(c) == 0) && (dentroPalavra == 1)){
            dentroPalavra = 1;
        }*/
       for (int i = 0;i < sizeof(c); i++){
         if (isWhite(c))
             dentroPalavra = 0;         //se o carater é branco, nao está dentro da palavra
         else{
             
             if (dentroPalavra == 0){
                 count++;
             }
             dentroPalavra = 1;
         }
        }
    }
    return count;
}

/**
 * This function receives an integer and iteratively returns the number of digits,
 * e.g. 218 = 3 digits (2, 1, 8).
 *  @param a - an int value to be sperated in digits.
 *  @return the number of digits found on the submitted int value.
 */
int numberOfDigitsIterative(int a){
    
    int aux = 0;
    
    while(a != 0){
        
        aux = a % 10;
        printf("%d ", aux);
        a /= 10;
    }
    return 0;
}
