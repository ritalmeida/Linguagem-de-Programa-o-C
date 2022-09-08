//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "pr11.h"


int main_pr12(int argc, const char * argv[]){

    CLASSSTUDENTS_DYNARR cs = {"LP1", NULL, 0};
    read_students_txt(&cs, "/data/pr12.txt");
    print_dynarray_classstudents(cs);
    //insert_student_dynarray_classstudents(cs, <#char *name#>, <#int number#>, <#float grade#>);
    print_dynarray_classstudents(cs);
    save_students_txt(cs, "/data/pr12.txt");

    return 0;
}

/**
* saves a given class in a text file
* @param cs - class to save
* @param fn - name of the text file
*/
void save_students_txt(CLASSSTUDENTS_DYNARR cs, char fn[]){

    FILE *fp;
    int mstd = 0;
    fp = (fopen("fn", "w"));

    if(fp != NULL){

        fprintf(fp, "%*s %*s %s", cs.name);
        fprintf(fp, "%*s %*s %d", &mstd);

    }

}

/**
* fills a class by reading the contents of a given text file
* @param pcs - class pointer
* @param fn - name of the text file
*/
void read_students_txt(CLASSSTUDENTS_DYNARR *pcs, char fn[]){

    FILE *fp;
    int mstd = 0;
    fp = fopen(fn, "r");

    if (fp != NULL){

        fscanf(fp, "%*s %*s %s", pcs->name);
        fscanf(fp, "%*s %*s %d", &mstd);

        char name[100], sname[100];
        int number = 0;
        float grade = 0.0;

        for (int i = 0; i < mstd; i++){

            fscanf(fp, "%s %s %d %1f", name, sname, &number, &grade);

            sname[strlen(sname)-1] = '\0';      //por causa da ,
            sprintf(name, "%s %s", name, sname);

            insert_student_dynarray_classstudents(pcs, name, number, grade);
        }
        fclose(fp);
    }
}

/**
* saves a given class in a text file without saving nstudents variable
* @param cs - class to save
* @param fn - name of the text file
*/
void save_students_txt_no_header(CLASSSTUDENTS_DYNARR cs, char fn[]){

    FILE *fp;
    fp = fopen(fn, "w");

    if (fp != NULL){

        fprintf(fp, "Class name: %s\n", cs.name);
        fprintf(fp, "Number of students: %d\n", cs.pstudents);

        STUDENT *s = cs.pstudents;

        while (s != NULL){

            fprintf(fp, "%s %d %.1f\n", s->pname, s->number, s->grade);
            s = s->pnext;
        }
        fclose(fp);
    }
}

/**
* fills a class by reading the contents of a given text file with no nstudents indication
* @param pcs - class pointer
* @param fn - name of the text file
*/
void read_students_txt_no_header(CLASSSTUDENTS_DYNARR *pcs, char fn[]){


}
