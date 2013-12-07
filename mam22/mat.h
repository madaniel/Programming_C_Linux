/* 
 * File:   mat.h from Mam22
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define SIZE 4 /*Matrix size*/
#define LEN 100 /*Input size*/
#define FOREVER for(;;)
#define OK 1
#define ERROR 0

typedef double matrix[SIZE][SIZE];

matrix mat_a,mat_b,mat_c,mat_d,mat_e,mat_f;

typedef struct {
    char *name;
    matrix *address;    
} mat_list;

typedef struct 
{
    char *name;
    void (*func)(void);
} mat_command;

typedef struct {
    matrix *first_parm;
    matrix *second_parm;
    matrix *result;    
}abc_parms;

typedef struct {
    matrix *first_parm;
    double scalar;
    matrix *result;    
}asb_parms;

void read_mat(void);
void print_mat(void);
void add_mat(void);
void sub_mat(void);
void mul_mat(void);
void mul_scalar(void);
void trans_mat(void);
void stop(void);
int get_matrix_ABC(void);
int get_matrix_ASB(void);
int get_matrix_AB(void);

