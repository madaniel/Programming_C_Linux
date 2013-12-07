/* 
 * File:   prnt.c
 * Author: student
 *
 * Created on January 20, 2012, 11:04 PM
 */

/*
 * This program will print the self source code to the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 100
#define FILENAME_LENGTH 100

int main(int argc, char **argv) 
{
    FILE * tFile;
    char buffer[BUFFER_SIZE],filename[FILENAME_LENGTH];
    int i;
    
    for(i=0;i<FILENAME_LENGTH;i++)
        filename[i]=0;
    
    strcpy(filename,argv[0]);
    strcat(filename,".c");
            
    tFile=fopen(filename,"r");
    if (tFile==NULL)
    {
        fprintf(stderr,"Error - failed to open file !\n");
        exit(EXIT_FAILURE);       
    }
    
    while (fgets(buffer,sizeof(buffer),tFile) )
        printf("%s",buffer);
        
    fclose(tFile);
    
    return (EXIT_SUCCESS);
}

