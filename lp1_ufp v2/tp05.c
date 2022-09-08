//
// Created by Rita Vieira de Almeida on 11/10/2021.
//

#include "tp05.h"


int main_tp05(int argc, const char * argv[]) {

    printf("Aula teórica de LP1 - 11 de outubro de 2021:\n\n");
    char str[] = "Ola Mundo";
    char sub[] = "Mundo";
    //printf("str[] = %s\n", str);
    //printf("O indice da primeira vogal é: str[%d]\n", index_first_vogal(str));
    //printf("%s\n", replace_char_by_char(str, 'a', 'i'));
    //printf("%s\n", remove_blanks(str));
    //printf("%s\n", remove_sub(str, sub));
    //printf("Indice: %d\n", index_sub_left(str, sub));
    //printf("Indice: %d\n", index_sub_right(str, sub));
    /*int mNx100[][MAXCOLS100] = {{ 1, 1, 1, 1 },
                                { 2, 2, 2, 2 },
                                { 3, 3, 3, 3 },
                                { 4, 4, 4, 4 }};*/

    //print_matrixNx100_ints(mNx100, 4, 4);
    /*int mNx100[MAXCOLS100][MAXCOLS100];
    read_matrixNx100_ints(mNx100, 4, 4);
    printf("\nMatriz inserida: \n\n");
    print_matrixNx100_ints(mNx100, 4, 4);*/
    /*multiply_matrixNx100_line_by_scalar(mNx100, 4, 4, 2, 3);
    print_matrixNx100_ints(mNx100, 4, 4);*/
    /*int mNx100[][MAXCOLS100] = {{ 1, 1, 1, 1 },
                                { 1, 2, 3, 4 },
                                { 0, 0, 0, 0 }};

    sum_lines_matrixesNx100(mNx100, 1, 2, 3, 4);
    print_matrixNx100(mNx100, 3, 4);*/
    /*int mNx100[][MAXCOLS100] = {{ 1, 2, 3, 4 },
                                { 5, 6, 7, 8 },
                                { 9, 10, 11, 12 },
                                { 13, 14, 15, 16 }};

    print_matrixNx100_ints(mNx100, 4, 4);
    printf("\nMatriz transposta: \n\n");
    transposed_matrixNx100(mNx100, 4);*/
    return 0;
}

/**
 * Função que procura o índice da 1a vogal na string dada.
 * @param str - string a analisar.
 * @return index da primeira vogal da string
 * */
int index_first_vogal(char str[]) {

    int index = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++) {

        if (isVowel(str[i])) {

            index = i;
            break;
        }
    }
    return index;
}

/**
 * Função que substitui um char o por outro r numa string.
 * @param str - string a analisar.
 * @param o - char original a substiruir.
 * @param r - char pelo qual substituir.
 * @return endereço da string actualizada.
 */
char* replace_char_by_char(char str[], char o, char r) {

    int size = strlen(str);

    for (int i = 0; i < size; i++) {

        if (str[i] == o) {

            str[i] = r;
        }
    }
    return str;
}

/**
 * Função que remove caracteres brancos existentes na string.
 * @param str - string a analisar.
 * @return endereço da string actualizada.
 */
char* remove_blanks(char str[]) {

    int aux = 0;
    int size = strlen(str);

    for (int i = 0; i < size; i++) {

        str[i] = str[i+aux];

        if (isWhite(str[i])) {

            aux++;
            i--;
        }
    }
    return str;
}

/**
 * Função que remove substring sub da string str.
 * @param str - string a analisar.
 * @param sub - substring com chars a remover.
 * @return endereço da string actualizada.
 */
char* remove_sub(char str[], char sub[]) {

    int size_str = strlen(str);
    int size_sub = strlen(sub);
    int aux, check = 0, i = 0, j = 0;

    for (i = 0; i < size_str; i++) {

        aux = i;
        for (j = 0; j < size_sub; j++) {

            if (str[i] == sub[j]) {

                i++;
            }
            check = i - aux;

            if (check == size_sub) {

                i = aux;
                for (j = i; j < (size_str-size_sub); j++) {

                    str[j] = str[j+size_sub];
                }
                size_str = size_str - size_sub;
                str[j] = '\0';
            }
        }
    }

    return str;
}

/**
 * Função que retorna índiice mais à esquerda de sub dentro de str.
 * @param str - string a analisar.
 * @aparam sub - sub string a encontrar.
 * @return índice da sub na str.
 *
 */
int index_sub_left(char str[], char sub[]) {

    char *find = strstr(str, sub);
    long index = 0;

    if (find) {

        index = find - str;
    }

    return (int)index;
}

/**
 * Função que retorna índice mais à direita de sub dentro de str.
 * @param str - string a analisar.
 * @aparam sub - sub string a encontrar.
 * @return índice da sub na str.
 *
 */
int index_sub_right(char str[], char sub[]) {

    int size = strlen(sub);

    return (int) (index_sub_left(str, sub) + size -1);
}

/**
 * Função que imprime matrizes Nx100.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void print_matrixNx100_ints(int mNx100[][MAXCOLS100], int lines, int columns) {

    for (int i = 0; i < lines; i++) {

        for (int j = 0; j < columns; j++) {

            printf("%d ", mNx100[i][j]);
        }
        printf("\n");
    }
}

/**
 * Função de inicialização/leitura de matriz de ints cujo número columns < NCOLUMNS.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void read_matrixNx100_ints(int mNx100[][NCOLUMNS], int lines, int columns) {

    printf("Preencha a matriz: \n");
    for (int i = 0; i < lines; i++) {

        for (int j = 0; j < columns; j++) {

            scanf("%d", &mNx100[i][j]);
        }
    }
}

/**
 * Função de inicialização/leitura de matriz de strings, cujo número columns < NCOLUMNS.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 */
void read_matrixNx100_strings(char mNx100[][NCOLUMNS], int lines, int columns) {

    scanf("%s", &mNx100[lines][columns]);
}

/**
 * Função para multiplicar uma linha de uma matriz por um dado número escalar.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lines - número de linhas da matriz.
 * @param columns - número de colunas da matriz (<MAXCOLS100).
 * @param line - linha a multiplicar pelo escalar.
 * @param scalar - número pelo qual multiplicar a linha.
 */
void multiply_matrixNx100_line_by_scalar(int mNx100[][MAXCOLS100], int lines, int columns, int line, int scalar) {

    line = line - 1;

    for (int i = line; i <= line; i++) {

        for (int j = 0; j < columns; j++) {

            mNx100[i][j] = scalar * mNx100[i][j];
        }
    }
}

/**
 * Função que some os elementos das linhas lin1 e lin2 de uma matriz, colocando o resultado na lin3.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param lin1 - 1a linha da matriz a somar.
 * @param lin2 - 2a linha da matriz a somar.
 * @param lin3 - linha onde colocar o resultado da somas das linhas lin1 e lin2.
 */
void sum_lines_matrixesNx100(int mNx100[][MAXCOLS100], int lin1, int lin2, int lin3, int columns) {

    lin1 = lin1 - 1;
    lin2 = lin2 - 1;
    lin3 = lin3 - 1;

    for (int i = lin1; i <= lin1; i++) {

        for (int j = lin2; j <= lin2; j++) {

            for (int k = lin3; k <= lin3; k++) {

                for (int c = 0; c < columns; c++) {

                    mNx100[k][c] = mNx100[i][c] + mNx100[j][c];
                }
            }
        }
    }
}

/** Função que calcula a transposta de uma matriz.
 * @param mNx100 - matriz com número máximo de colunas definido por MAXCOLS100.
 * @param size - número de linhas/colunas da matriz.
 */
void transposed_matrixNx100(int mNx100[][MAXCOLS100], int size) {

    int mAux[size][size];

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            mAux[j][i] = mNx100[i][j];
        }
    }
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            printf("%d ", mAux[i][j]);
        }
        printf("\n");
    }
}