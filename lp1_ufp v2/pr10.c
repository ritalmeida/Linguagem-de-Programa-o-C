//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "pr10.h"

int main_pr11(int argc, const char * argv[]){

    CLASSSTUDENTS_QUEUE turma = {"LP1", NULL, 0};
    insert_student_ordered(&turma, "A", 16.0, 1);
    return 0;
}

/**
* inserts a new student into a sorted linked list
* @param cs - class pointer
* @param name - new student's name
* @param grade - new stdudent's grade
* @param number - new student's number
* Note: Insertion at FIRST, HEAD, TAIL, MIDDLE
*/
void insert_student_ordered(CLASSSTUDENTS_QUEUE *cs, char name[], float grade, int number){

    STUDENT *s = (STUDENT *) malloc(sizeof(STUDENT));
    s->grade = grade;
    s->number = number;
    strcpy(s->pname, name);
    s->pnext = NULL;

    if(cs->pstudents == NULL){

        cs->pstudents = s;
        cs->nstudents++;
        return;
    }

    STUDENT *pcurrent = cs->pstudents, *pnext = NULL;
    while (pcurrent != NULL && strcmp(name, pcurrent->pname) > 0) {

        pnext = pcurrent;
        pcurrent = pcurrent->pnext;
    }

    if(pcurrent == cs->pstudents){
        s->pnext = pcurrent;
        cs->pstudents = s;
        cs->nstudents++;
        return;
    }

    if(pcurrent == NULL){
        pnext->pnext = s;
        cs->nstudents++;
        return;
    }

    pnext->pnext = s;
    s->pnext = pcurrent;
    cs->nstudents++;
}

/**
* removes a student from a sorted linked list
* @param pcs - class pointer
* @param name - student's name
* Note: Remove at EMPTY, HEAD, DO_NOT_EXIST, TAIL/MIDDLE
*/
void remove_student_ordered(CLASSSTUDENTS_QUEUE *pcs, char name[]){

    if(pcs->pstudents == NULL){             //EMPTY
        return;
    }
    STUDENT *pnext = NULL, *pcurrent = pcs->pstudents;
    while (pcurrent != NULL && strcmp(pcurrent->pname, name) != 0) {

        pnext = pcurrent;
        pcurrent = pcurrent->pnext;
    }

    if(pcurrent == NULL) return;

    if(pnext == NULL){      //HEAD

        pcs->pstudents = pcurrent->pnext;
        free(pcurrent);
        pcs->nstudents--;
        return;
    }

    pnext->pnext = pcurrent->pnext;
    free(pcurrent);
    pcs->nstudents--;
    return;

}

/**
* Finds a student in a sorted linked list of students
* @param cs - class of students
* @param name - student's name
* @return - pointer student with matching name
*/
STUDENT* find_student_ordered(CLASSSTUDENTS_QUEUE cs, char name[]);

/**
* calcs the average class grade, given a sorted linked list of students
* @param cs - class of students
* @return - avg class grade
*/
float get_avg_class_grade(CLASSSTUDENTS_QUEUE cs);

// changes student grade
void set_student_grade_ordered(CLASSSTUDENTS_QUEUE cs, char name[], int grade);

// retreives student grade
float get_student_grade_ordered(CLASSSTUDENTS_QUEUE cs, char name[]);

// prints all the students in a given class
void print_students(CLASSSTUDENTS_QUEUE cs);