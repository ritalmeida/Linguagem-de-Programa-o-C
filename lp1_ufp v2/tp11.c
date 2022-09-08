//
// Created by Rita Vieira de Almeida on 03/01/2022.
//
#include "tp11.h"
#define MAX200 200

/** Define structs for STUDENT and CLASSSTUDENTS_DYNARR */
typedef struct student {
    char *pname;
    int number;
    float grade;
} STUDENT;

typedef struct classstudents {
    char name[MAX200];
    STUDENT *pstudents;
    int size_students; //Size of the dynamic array
    int current_student; //Current number of students inside dynamic array
} CLASSSTUDENTS_DYNARR;

int main_tp11(int argc, const char * argv[]){

    CLASSSTUDENTS_DYNARR turma_Lp1 = {"Lp1", NULL, 0};

    create_dynarray_classstudents(&turma_Lp1, 2);

    insert_student_dynarray_classstudents(&turma_Lp1, "Rita Almeida", 35456, 0.0f);
    insert_student_dynarray_classstudents(&turma_Lp1, "Joao Ribeiro", 35987, 0.0f);
    insert_student_dynarray_classstudents(&turma_Lp1, "Jose Silva", 36487, 0.0f);
    //insert_student_dynarray_classstudents(&turma_Lp1, "Diogo Ferreira", 37821, 0.0f);

    print_dynarray_classstudents(turma_Lp1);
    return 0;
}

/**
 * Criar um array dinâmico de students com um dado tamanho inicial.
 * @param pcs - apontador para o array que caracteriza a turma de estudantes (CLASSSTUDENTS).
 * @param initsize - tamanho inicial do array dinâmico de estudantes.
 */
void create_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, int initsize){

    STUDENT *pstudents = calloc(initsize, sizeof(STUDENT));
    pcs->pstudents = pstudents;
    (*pcs).pstudents = initsize;
}

/**
 * Insere um student no array dinâmico da turma de students.
 * @param pcs - apontador para o array que caracteriza a turma de estudantes (CLASSSTUDENTS).
 * @param name - nome do aluno a inserir no array dinâmico de estudantes.
 * @param number - número do aluno a inserir no array dinâmico de estudantes.
 * @param grade - nota do aluno a inserir no array dinâmico de estudantes.
 */
void insert_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[], int number, float grade){

    int i = 0;
    STUDENT *pstudent = pcs->pstudents;

    for (i = 0; i < pcs->pstudents; i++) {

        if(pstudent->pname == NULL){

            pstudent->pname = (char*) malloc(strlen(name)+1);
            strcpy(pstudent->pname, name);
            pstudent->number = number;
            pstudent->grade = grade;
            return;
        }
        pstudent++;
    }
    if(i == pcs->pstudents){                         //realocar memória

        int oldsize = pcs->pstudents, newsize = oldsize + 10;
        pcs->pstudents = (STUDENT*) realloc(pcs->pstudents, newsize * sizeof(STUDENT));
        pcs->pstudents = newsize;
        pstudent = pcs->pstudents + oldsize;

        for (i = oldsize; i < newsize; i++) {

            pstudent->pname = NULL;
            pstudent->number = 0;
            pstudent->grade = 0.0f;
            pstudent++;
        }
        pstudent = pcs->pstudents + oldsize;
        pstudent->pname = (char*) malloc(strlen(name)+1);
        strcpy(pstudent->pname, name);
        pstudent->number = number;
        pstudent->grade = grade;
    }
}

/**
 * Procura um student no array dinâmico da turma de students.
 * @param cs - cópia do array que caracteriza a turma de estudantes (CLASSSTUDENTS).
 * @param name - nome do aluno a procurar no array dinâmico de estudantes.
 * @return apontador para o student ou NULL (caso não exista).
 */
STUDENT* find_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR cs, char name[]){

    STUDENT *pst = cs.pstudents;

    if(pst == NULL){

        printf("find_student_dynarray_classstudents(): classe %s has no students data to find!!\n", cs.name);
        return pst;
    }

    for (int i = 0; (i < cs.pstudents && pst->pname != NULL && strcmp(pst->pname, name) != 0); i++) {

        printf("find_student_dynarray_classstudents(): student name: %s, number: %d, grade: 0.2f\n", pst->pname, pst->number, pst->grade);
        pst++;
    }
    return (pst->pname != NULL && strcmp(pst->pname, name) == 0?pst:NULL);
}

/**
 * Imprime os students do array dinâmico da turma de students.
 * @param cs - cópia do array que caracteriza a turma de estudantes (CLASSSTUDENTS).
 */
void print_dynarray_classstudents(CLASSSTUDENTS_DYNARR cs){

    STUDENT *pstudent = cs.pstudents;
    for (int i = 0; i < cs.pstudents; i++) {

        //if(pstudent->pname != NULL){

        printf("print_dynarray_classstudents(): student[%d] = %s, %d, %0.1f\n", i, pstudent->pname, pstudent->number,pstudent->grade);
        pstudent++;
    }
}

/**
 * Remove um student do array dinâmico da turma de students.
 * @param pcs - apontador para o array que caracteriza a turma de estudantes (CLASSSTUDENTS).
 * @param name - nome do aluno a procurar no array dinâmico de estudantes.
 * @return cópia do student removido ou NULL (caso não exista).
 */
STUDENT remove_student_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs, char name[]){

    STUDENT st = {NULL, 0, 0.0f};
    STUDENT *pst = find_student_dynarray_classstudents(*pcs, name);

    if(pst != NULL){

        st = *pst;
        while (pst < (pcs->pstudents + pcs->pstudents - 1) && pst->pname != NULL) {

            *pst = *(pst + 1);
            pst++;
        }
        if(pst == pcs->pstudents + pcs->pstudents-1){

            pst->pname = NULL;
            pst->number = 0;
            pst->grade = 0.0f;
        }
    }
    return st;
}

/**
 * Liberta os dados de todos os students armazenados no array de students da turma.
 */
void free_dynarray_classstudents(CLASSSTUDENTS_DYNARR *pcs){

    STUDENT *pst = pcs->pstudents;

    if(pst == NULL){

        printf("free_dynarray_classstudents(): classe %s has no students data to free!!\n", pcs->name);
        return;
    }

    for (int i = 0; i < pcs->pstudents; i++) {

        free(pst->pname);
        //pst = pst -> pnext;
    }
    free(pcs->pstudents);
}