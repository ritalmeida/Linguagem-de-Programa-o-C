//
// Created by Rita Vieira de Almeida on 20/09/2021.
//

#include "tp02.h"

int main_tp02(int argc, const char *argv[]) {

    //printPrimitiveDataTypesSizeLimits();

    /*checkIfLetter('7');
    checkIfLetter('a');
    checkIfLetter('R');*/

    guessSecretChar();
    return 0;
}

/**
 * Imprimir uma tabela com o nome dos tipos de dados primitivos e respetivos:
 * | nº bits (sizeof()) | nº bytes (sizeof()/8) | valor máximo | valor mínimo.
 */
void printPrimitiveDataTypesSizeLimits() {

    int bits = 0;
    int bytes = 0;
    double limit = 0;

    //char
    bytes = sizeof(char);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    printf("CHAR\n num bits: %d | num bytes: %d | valor minimo: %f | valor maximo: %f\n\n", bits, bytes, limit-1, limit*-1);

    //short
    bytes = sizeof(short);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    printf("SHORT\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n\n", bits, bytes, limit-1, limit*-1);

    //int
    bytes = sizeof(int);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    printf("INT\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n\n", bits, bytes, limit-1, limit*-1);

    //long
    bytes = sizeof(long);
    bits = 8 * bytes;
    limit = pow(2, bits-1); //maior valor limits*-1 menor valor limits-1
    printf("LONG\n num bits: %d | num bytes: %d | valor maximo: %0.0f | valor minimo: %0.0f\n\n", bits, bytes, limit-1, limit*-1);

    //float
    bytes = sizeof(float);
    bits = 8 * bytes;
    printf("FLOAT\n num bits: %d | num bytes: %d | valor minimo: %0.0f | valor maximo: %0.0f\n\n", bits, bytes, FLT_MIN, FLT_MAX);

    //double
    bytes = sizeof(double);
    bits = 8 * bytes;
    printf("DOUBLE\n num bits: %d | num bytes: %d | valor minimo: %0.0f | valor maximo: %0.0f\n\n", bits, bytes, DBL_MIN, DBL_MAX);
}

/**
 * Verifica se um dado char é uma letra (a...z/A...Z)
 * @param c char dado
 * @return 1 se verdadeiro. 0 se falso.
 */
int checkIfLetter(char c){

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){

        return 1;
    }

    return 0;
}

/**
* Game for 2 players:
* 1st player: inserts a secret char ('a'..'z' || 'A'..'Z') followed by clean screen (system('clear');).
* 2nd player: guesses the secret char; after hiting the char, prints it and the number of guesses.
*/
void guessSecretChar() {

    char secret = '\0', guess = '\0';
    int tries = 1;

    do {
        printf("Player 1, insert a character: \n");
        scanf("%c", &secret);

        if(checkIfLetter(secret)) {
            break;
        }else{
            printf("Invalid character! Try again: \n");
        }
    } while (1);

    system("clear");

    do{

        printf("\nPlayer 2, try to guess the character: ");
        scanf(" %c", &guess);

        if(guess == secret){
            break;
        }
        printf("\nTry again!\n");
        tries++;

    }while(1);

    printf("\nCongratulations!! The secret char was '%c'! It took %d tries!!\n\n", secret, tries);
}