/*
 *  File:  main.c  from Mam22 Project
 */

#include "mat.h"

mat_command cmd[]={
    {"read_mat",read_mat},
    {"print_mat",print_mat},
    {"add_mat",add_mat},
    {"sub_mat",sub_mat},
    {"mul_mat",mul_mat},
    {"mul_scalar",mul_scalar},
    {"trans_mat",trans_mat},
    {"stop",stop},
    {"not_valid",NULL}
};

int main(void)
{
    int i;
    char command[30];    
    printf("Please enter matrix calc command:\n");
    FOREVER    
    if ( scanf("%s",command) ) /*scanf succeeded*/
    {        
        for(i=0 ; cmd[i].func ; i++) /*scan until NULL in cmd[].func*/
              if (strcmp(command,cmd[i].name)==0) /*command match*/
                    break;       
            
        if(cmd[i].func==NULL)
        {
                printf("\nERROR - Command \"%s\" does not exist , try again.\n",command);
                while (getchar()!='\n');/*clean the input*/
        }            
                else
                    (*(cmd[i].func))();/*run the func*/
    }      
    
    return 0;
}

