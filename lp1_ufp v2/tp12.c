//
// Created by Rita Vieira de Almeida on 03/01/2022.
//

#include "tp12.h"
#include "pr09.h"

typedef struct dynarrayrects
{
    RECTANGLE *prects;
    int size;
} DYNARRAYRECTS;

/*
 FILE * fopen ( const char * filename, const char * mode );
  - filename: C string containing the name of the file to be opened. Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).
  - mode: C string containing a file access mode, e.g.:
    "r"        read: Open file for input operations (file must exist).
    "w"        write: Create an empty file for output (overrides any content).
    "a"        append: Open file for output at end (overrides); repositioning operations ignored (fseek, fsetpos, rewind);
    "r+"    read/update: Open file for both input and output (file must exist).
    "w+"    write/update: Create an empty file for both input and output (overrides any content).
    "a+"    append/update: Open a file for both input and output;
                Output done at end of file (append); input at any position (via fseek, fsetpos, rewind);
    The mode string may also specify the type of file (text - implicit or binary):
        Default type is 'text' (may also be specified by 't').
        Type 'binary' must be specified through 'b'.
        This additional "b" can either be appended at end of mode string:
            e.g. "rb", "wb", "ab", "r+b", "w+b", "a+b"
        or inserted between the letter and the "+" sign for the mixed modes:
            e.g. "rb+", "wb+", "ab+")
 */

int main_tp12(int argc, const char * argv[])
{
    // insert your test code here...
    printf("main_tp12():...\n");
    char filename[]="/Users/rui/Documents/XCodeProjects/lp1_ufp/data/rects.txt";

    DYNARRAYRECTS dar = {NULL, 0};


    RECTANGLE r1={{0,1},{1,0}}, r2={{1,2},{2,1}};

    create_dyn_array_rects(&dar, 10);
    insert_rect_dyn_array_rects(&dar, r1);
    insert_rect_dyn_array_rects(&dar, r2);
    print_dyn_array_rects(dar);
    save_dyn_array_rects_txt(dar, filename);


    read_dyn_array_rects_txt(&dar, filename);
    print_dyn_array_rects(dar);
    insert_rect_dyn_array_rects(&dar, r2);
    save_dyn_array_rects_txt(dar, filename);

    return 0;
}

/** Create a dynamic array of RECTANGLE with given number of available positions */
void create_dyn_array_rects(DYNARRAYRECTS *pdar, int numberOfRectangles)
{
    pdar->prects=calloc(sizeof(RECTANGLE), numberOfRectangles);
    pdar->size=numberOfRectangles;

    /*
    RECTANGLE r0 = {{0,0},{0,0}};

    pdar->prects=malloc(sizeof(RECTANGLE)*numberOfRectangles);
    pdar->size=numberOfRectangles;

    RECTANGLE *pr = pdar->prects;
    for(int i=0; i<numberOfRectangles; i++)
    {
        *(pr+i)=r0;
    }
    */
}

/** Print a RECTANGLE */
void print_rectangle(int i, RECTANGLE r)
{
    printf("Rectangle[%d]={(%d,%d),(%d,%d)}\n", i, r.downpt.x, r.downpt.y, r.uppt.x, r.uppt.y);
}

/** Print the content of the dynamic array of RECTANGLE */
void print_dyn_array_rects(DYNARRAYRECTS dar)
{
    puts("");
    for (int i =0 ; i< dar.size; i++)
    {
        print_rectangle(i, *(dar.prects+i));
    }
    puts("");
}

/** Compare two RECTANGE; returns 0 if the two rectangles have the same coordinates */
int rectanle_compare(RECTANGLE r1, RECTANGLE r2)
{
    return (r1.downpt.x==r2.downpt.x &&
            r1.downpt.y==r2.downpt.y &&
            r1.uppt.x==r2.uppt.x &&
            r1.uppt.y==r2.uppt.y);
}

/**
 * Insert a RECTANGLE into the fisrt available position of the dynamic array:
 * @param pdar - pointer to the dynamic  array
 * @param rect - data of RECTANGLE to insert.
 */
void insert_rect_dyn_array_rects(DYNARRAYRECTS *pdar, RECTANGLE rect)
{
    RECTANGLE *prect = pdar->prects, r0={{0,0},{0,0}};

    //Look for empty position and insert rect
    for(int i=0; i<pdar->size;i++)
    {
        if(rectanle_compare(r0, *prect)){
            (*prect) = rect;
            return;
        }
        prect++;
    }
    printf("insert_rect_dyn_array_rects(): dar.prects overflow = %d!!\n", pdar->size);
}

/**
 *Read data from a file containing several RECTANGLE:
 * @param pcs - pointer to dynamic array.
 */
void read_dyn_array_rects_txt(DYNARRAYRECTS *pcs, char filename[])
{
    FILE *fp=NULL;
    RECTANGLE *prect = NULL;

    fprintf(stdout, "read_dyn_array_rects_txt(%s): reading rectangles...\n", filename);

    if((fp=fopen(filename, "r"))==NULL)
    {
        printf("save_dyn_array_rects_txt(): error opening file %s on r mode\n", filename);
        return;
    }
    int size = 0;
    char auxStr[200]="";

    // Line format: "rectangles: 10"
    // i)   ignore string   -> %*s (until 1st white char)
    fscanf(fp, "%*s %d", &size);

    //Create dyn array...
    create_dyn_array_rects(pcs, size);

    prect = pcs->prects;
    for(int i=0;i<pcs->size;i++)
    {
        // Line format: "rect 0: 0 0 1 1"
        // i)   read until ':' (everything not ':') -> %[^:]
        // ii)  ignore ':'                          -> %*[:]
        fscanf(fp, "%[^:] %*[:] %d %d %d %d",auxStr, &(prect->downpt.x), &(prect->downpt.y), &(prect->uppt.x), &(prect->uppt.y));
        prect++;
    }
    fprintf(stdout, "read_dyn_array_rects_txt(%s): closing file\n", filename);
    fclose(fp);
}

/**
 * Write content of dynamic array of RECTANGLE into a text file:
 * @param cs - copy of dynamic array.
 * @param filename - path to output text file.
 */
void save_dyn_array_rects_txt(DYNARRAYRECTS cs, char filename[])
{
    FILE *fp=NULL;
    RECTANGLE *prect = cs.prects;

    fprintf(stdout, "save_dyn_array_rects_txt(%s): saving rectangles...\n", filename);

    if((fp=fopen(filename, "w"))==NULL)
    {
        fprintf(stdout, "save_dyn_array_rects_txt(): error opening file %s on w mode\n", filename);
        return;
    }

    //Write number of rectangles
    fprintf(fp, "rectangles: %d\n", cs.size);

    //Write each rectangle in a single line
    for(int i=0;i<cs.size;i++)
    {
        fprintf(fp, "rect %d: %d %d %d %d\n", i, prect->downpt.x, prect->downpt.y, prect->uppt.x, prect->uppt.y);
        prect++;
    }
    fprintf(stdout, "save_dyn_array_rects_txt(%s): closing file\n", filename);
    fclose(fp);
}