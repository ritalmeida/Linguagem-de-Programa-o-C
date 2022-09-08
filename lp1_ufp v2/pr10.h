#ifndef pr10_h
#define pr10_h

// in tp11.h

#include "tp11.h"

/*typedef struct student {
    char *pname;
    int number;
    float grade;
} STUDENT;*/


typedef struct student_node {
    STUDENT student_info;
    struct student_node *pnext;
} STUDENT_NODE;

typedef struct classstudents_queue {
    char name[MAX200];
    STUDENT_NODE *pstudents;
    int nstudents;
} CLASSSTUDENTS_QUEUE;

/**
 * Insert a new student into the ordered queue CLASSSTUDENTS_QUEUE.
 * The queue is ordered by name
 * Consider the 4 possibilities: Queue is empty, insert head, insert tail, insert in the middle
 * @param pcs - pointer to CLASSSTUDENTS_QUEUE
 * @param name - student name.
 * @param number - student number.
 * @param grade - student grade.
 */
void insert_student_ordered(CLASSSTUDENTS_QUEUE *pcs, char name[], float grade, int number);

/**
 * Find student and remove from the ordered queue CLASSSTUDENTS_QUEUE.
 * Consider the 5 possibilities: Queue is empty,name not found, remove head, remove tail, remove in the middle
 * @param pcs - pointer to CLASSSTUDENTS_QUEUE
 * @param name - student name.
 */
void remove_student_ordered(CLASSSTUDENTS_QUEUE *pcs, char name[]);

/**
 * Print all students inside dynamic array CLASSSTUDENTS_QUEUE.
 * @param cs - copy of CLASSSTUDENTS_QUEUE
 */
void print_students(CLASSSTUDENTS_QUEUE cs);

/**
 * Search student inside ordered queue CLASSSTUDENTS_QUEUE.
 * @param cs - copy of CLASSSTUDENTS_QUEUE
 * @param name - name of student to search for.
 * @return pointer to found student (NULLif not found).
 */
STUDENT_NODE* find_student_ordered(CLASSSTUDENTS_QUEUE cs, char name[]);

/**
 * Set student's grade into the ordered queue CLASSSTUDENTS_QUEUE.
 * @param cs - copy of CLASSSTUDENTS_QUEUE
 * @param name - student name.
 * @param grade - student grade.
 */
void set_student_grade_ordered(CLASSSTUDENTS_QUEUE cs, char name[], int grade);

/**
 * Get student's grade into the ordered queue CLASSSTUDENTS_QUEUE.
 * @param cs - copy of CLASSSTUDENTS_QUEUE
 * @param name - student name.
 */
float get_student_grade_ordered(CLASSSTUDENTS_QUEUE cs, char name[]);

/**
 * Compute the average of thr student's grades in the ordered queue CLASSSTUDENTS_QUEUE.
 * @param cs - copy of CLASSSTUDENTS_QUEUE
 */
float get_avg_class_grade(CLASSSTUDENTS_QUEUE cs);


#endif //pr10_h
