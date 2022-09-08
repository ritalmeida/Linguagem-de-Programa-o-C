//
//  tp13.h
//  lp1_ufp
//
//  Created by Rui on 13/12/17.
//  Copyright © 2017 Rui. All rights reserved.
//

#ifndef tp13_h
#define tp13_h

#include <stdio.h>
#include <stdlib.h>
#include "pr11.h"

/**
 * Manage a binary file containing data from a queue of students (CLASSSTUDENT_QUEUE).
 *  Format of the file:
 *  <strlen(class_name)> <class_name> <nstudents> { <strlen(student_name)> <student_name> <number> <grade>...}
 *  [4] ["LP1\0"] [3] { [6] ["PEDRO\0"] [1111] [12.50] ...}
 */

/**
 * Saves the informaton of a queue of students into a binary fle.
 * @param cs - copy of class students;
 * @param fname - path to binary file.
 */
void save_students_bin(CLASSSTUDENTS_QUEUE cs, char fname[]);

/**
 * Reads the informaton of a queue from a binary flle and loads it into main memory.
 * @param pcs -pointer to class students;
 * @param fname - path to binary file.
 */
void read_students_bin(CLASSSTUDENTS_QUEUE *pcs, char fname[]);


int main_tp13(int argc, const char * argv[]);


#endif /* tp13_h */
