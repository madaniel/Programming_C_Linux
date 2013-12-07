/* 
 * File:   seek.c
 * Author: student
 *
 * Created on January 20, 2012, 11:04 PM
 */

/*
 * This program will print the n char from input file from user by argument
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
    FILE * tFile;    
    int i=2;
    long length,char_n;   
    char t_char;
    
    /*Abort if there are no input files*/            
    if (argc < 3)
    {
        fprintf(stderr,"Error - no input files !\n");
        exit(EXIT_FAILURE);               
    }
    
    /*Abort if there's no char number*/            
    if ( (char_n=atol(argv[1]) ) == 0)
    {
        fprintf(stderr,"Error - no valid char number !\n");
        exit(EXIT_FAILURE);               
    }      
    
    /*read the input files*/
    while (i < argc)
    {
        tFile=fopen(argv[i++],"r");
        
        /*Abort if input file cannot be accessed*/
        if (tFile==NULL)
        {
            fprintf(stderr,"Error - failed to open file:%s !\n",argv[i-1]);
            exit(EXIT_FAILURE);       
        }        
        
        fseek(tFile,0,SEEK_END);
        
        /*Skip file if it's shorter than the char number*/
        if ( (length=ftell(tFile) ) < char_n )
        {
            fprintf(stderr,"Error - the input file: %s is shorter than the char number !\n",argv[i-1]);
            fclose(tFile);                    
            continue;
        }
        
        fseek(tFile,char_n-1,SEEK_SET);   
        t_char=fgetc(tFile);
        printf("%c\n",t_char);
        fclose(tFile);        
    }
    
    return (EXIT_SUCCESS);
}
