//
// Created by Rita Vieira de Almeida on 27/09/2021.
//

#include "tp03.h"

int main_tp03(int argc, const char *argv[]) {

    /*char c = 'r';
    printf("char '%c' é vogal %d\n", c, isVowel(c));
    printf("char '%c' é consoante %d\n", c, isConsonant(c));
    printf("char '%c' é digito %d\n", c, isDigit(c));
    printf("char '%c' é espaço branco %d\n", c, isWhite(c));*/

    //readKeysPressedPrintDigits();

    //printKeyType('A');
    /*int n = 54321;
    printf("Numero de digitos em %d: %d", n, numberOfDigitsIterative(n));*/
    /*int n = 23437860;
    printf("numero %d, %hd", n, highestEvenOrOddDigitsFrequency(n));*/
    //printf("Tem %d palavras!\n", countDigitsStdin());

    int x = 1000;
    printf("Highest frequency: %d\n", highestFrequencyDigit(x));

    return 0;
}

/**
 * Verifica se o carater é um digito
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isDigit(char c) {

    if(c >= '0' && c <= '9') {

        return 1;
    } else
        return 0;
}

/**
 * Verifica se o carater é uma vogal
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isVowel(char c) {

    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {

        return 1;
    }
    return 0;
}

/**
 * Verifica se carater é consoante
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isConsonant(char c) {

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') && (!isVowel(c))) {

        return 1;
    }else{
        return 0;
    }
}

/**
 * Verifica se carater é um espaço branco
 * @param c carater inserido pelo utilizador
 * @return 1 se true. 0 se false
 */
int isWhite(char c) {

    if((c == ' ') || (c == '\n') || (c == '\r') || (c == '\t')) {

        return 1;
    }else{
        return 0;
    }
}

/**
 * Ler em ciclo uma tecla seguida por \n (Terminar com '.') e para cada tecla
 * retorna imprime %c - is digit | not digit.
 */
void readKeysPressedPrintDigits() {

    char c = '\0';

    printf("Pressione uma tecla e prima enter! Quando quiser terminar, carrege em . (ponto final): \n");

    do{
        printf("Carater: ");
        scanf(" %c", &c);
        if(isDigit(c)){
            printf("%c é digito!\n", c);
        }
        else printf("%c nao é digito!\n", c);
    }while (c != '.');
}

/**
 * This function prints a char type: digit, vowel, consonant, special.
 * @param c - the char to be checked.
 */
void printKeyType(char c) {

    if(isDigit(c)){
        printf("O caratere %c é um digito\n", c);
    }else if(isVowel(c)){
        printf("O caratere %c é uma vogal\n", c);
    }else if(isConsonant(c)){
        printf("O caratere %c é uma consoante\n", c);
    }else if(isWhite(c)){
        printf("O caratere %c é branco\n", c);
    }else {
        printf("O caratere %c é um caratere especial\n", c);
    }
}

/**
 * Receber um inteiro e retornar iterativamente o numero de dígitos
 *  @param n - o inteiro que vamos analizar
 *  @return o numero de digitos encontrados em n
 */
int numberOfDigitsIterative(int n) {

    int count = 0;

    do {
        n /= 10;
        count++;
    } while (n != 0);

    return count;
}

/*** Receives an integer and iteratively counts the frequency of odd and even digits
 * e.g. 218 2 = returns frequency of even digits = 3 (because > frequency of odd).
 * @param n - integer number;
 * @return even or odd digits highest frequency.
 */
short highestEvenOrOddDigitsFrequency(int n) {

    int aux, par = 0, impar = 0;

    do {
        aux = n % 10;
        if (aux % 2 == 0)
            par++;
        else
            impar++;
        n /= 10;
    } while (n != 0);

    if (par > impar)
        return par;
    else
        return impar;
}

/**
 * quantas palavras até metermos o enter. qualquer conjunto de carateres sem ser o white
 * @return
 */
int countDigitsStdin() {

    char c = '\0';
    int count = 0;
    int dentroPalavra = 0;  //tipo booleano

    printf("Insira uma frase e termine com ENTER: ");

    while((c = getchar()) != '\n'){

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
 * Count the occorrencer of digit x un n
 * @param x the ingeger
 * @param d the digit to count
 * @return number of ocurrencies
 */
int aux_highestFrequencyDigit(int x, int d) {

        // Initialize count
        // of digit d
        int count = 0;
        while (x > 0)
        {
            // Increment count if
            // current digit is
            // same as d
            if (x % 10 == d)
                count++;
            x = x / 10;
        }
        return count;
    }

/**
 * Receives an integer and iteratively returns the highest frequency of digit,
 * e.g. 218 2 = returns digit 2 which has highest frequency.
 * @param n - integer number;
 * @return digit with highest frequency.
 */
int highestFrequencyDigit(int n) {

    // Handle negative number
    if (n < 0)
        n = -n;

// Initialize result
// which is a digit
    int result = 0;

// Initialize count
// of result
    int max_count = 1;

// Traverse through
// all digits
    for (int d = 0; d <= 9; d++)
    {
        // Count occurrences
        // of current digit
        int count = aux_highestFrequencyDigit(n, d);

        // Update max_count
        // and result if needed
        if (count >= max_count)
        {
            max_count = count;
            result = d;
        }
    }
    return result;
}