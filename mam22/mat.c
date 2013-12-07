/*
*  File:  mat.c  from Mam22 Project
*  
*  Note - all functions can accept commas (,) in their input but in most times they assume the user entered it in place.  
* 
*/

#include "mat.h"

mat_list mats[]={ 
{"mat_a",&mat_a},
{"mat_b",&mat_b},
{"mat_c",&mat_c},
{"mat_d",&mat_d},
{"mat_e",&mat_e},
{"mat_f",&mat_f},
{"#",NULL}    
};

abc_parms parm;
asb_parms parm2;

void read_mat(void)
{
    char *ptr=NULL;
    char input[LEN],temp[LEN];
    double mat_temp[SIZE*SIZE];
    int i,x=0,y=0,z=0;

    for(i=0;i<SIZE*SIZE;i++)
        mat_temp[i]=0.0;  
    
    fgets (input , 100 , stdin);
    
    strcpy(temp,input);

    if(*input=='\n') 
        {
        printf("\nERROR - No Matrix entered, try again.\n");
        return;
        }    

    ptr=strtok(temp," ,"); /*cut the Matrix name*/
    for(i=0; mats[i].address ;i++) /*scan until NULL in mats[].address*/
        if(strcmp(ptr,mats[i].name)==0)/*if Matrix name matches*/
                break;

    if(mats[i].address==NULL)/*no match found*/
        {
        printf("\nERROR - Matrix does not exist , try again.\n");
        return;
        }
    
    strcpy(temp,"");
    strcat(temp,mats[i].name);
    strcat(temp,",");
    ptr=strstr(input,temp);      
    
    if(ptr==NULL) 
    {
            printf("\nERROR - no comma entered after Matrix name. try again.\n");          
            return;     
    }    
    else
    {
        while (*ptr!=',')
                ptr++;
    }
        
    /*getting input to temp matrix*/
    
    while(*ptr!='\0' && z < SIZE*SIZE)        
    {
        if (*ptr==',')
            if ( (ptr[1] >= '0' && ptr[1]<='9') || ptr[1]==' ') /*comma and number afterwards, bypassing spaces*/
                ptr++;
            else /*no number after the comma*/
            {
                printf("\nERROR - invalid number entered. try again.\n");
                return;
            }
        else; /*empty else*/
                        
       mat_temp[z++]=strtod(ptr,&ptr);        
    }
    z=0;
    /*Entering input from flat array into Matrix*/
    for(y=0;y<(SIZE) ;y++)
        for(x=0;x<(SIZE) ;x++)        
                mats[i].address[0][y][x]=mat_temp[z++];  
    
    printf("\nOK.\n");
    
}

void print_mat(void)
{
    char *ptr=NULL;    
    char input[LEN];    
    int i,x,y;  
        
    fgets (input , 100 , stdin);
    
    ptr=strtok(input," \n"); /*cut the Matrix name*/
    
    if(ptr==NULL || *ptr=='\n') 
        {
        printf("\nERROR - No Matrix entered, try again.\n");
        return;
        } 

    for(i=0; mats[i].address ;i++) 
        if(strcmp(ptr,mats[i].name)==0)
                break;

    if(mats[i].address==NULL)
        {
        printf("\nERROR - Matrix does not exist , try again.\n");
        return;
        }    
    else
    { 
       printf("\nMatrix %s:\n",mats[i].name);
       for(y=0;y<(SIZE) ;y++)
       {
                for(x=0;x<(SIZE) ;x++)                 
                        printf("%g ",mats[i].address[0][y][x]);
                printf("\n");
       }        
    }    

}

void add_mat(void)
{
   int x,y;
    
   if(get_matrix_ABC()==OK)
   {
        /*Entering results from first and second Matrix*/
        for(y=0;y<(SIZE) ;y++)
            for(x=0;x<(SIZE) ;x++)        
                    parm.result[0][y][x]=parm.first_parm[0][y][x] + parm.second_parm[0][y][x];      

        printf("\nOK.\n");       
   }
   else
       return;   
}

void sub_mat(void)
{
    int x,y;
    
   if(get_matrix_ABC()==OK)
   {
        /*Entering results from first and second Matrix*/
        for(y=0;y<(SIZE) ;y++)
            for(x=0;x<(SIZE) ;x++)        
                    parm.result[0][y][x]=parm.first_parm[0][y][x] - parm.second_parm[0][y][x];      

        printf("\nOK.\n");       
   }
   else
       return;    
}

void mul_mat(void)
{
    int x,y,z;
    
    
   if(get_matrix_ABC()==OK)
   {
        /*Entering results from first and second Matrix*/
        for(y=0;y<(SIZE) ;y++)
            for(x=0;x<(SIZE) ;x++)
            {
                parm.result[0][y][x]=0; /*reset each Matrix cell*/
                for(z=0;z<(SIZE) ;z++)                                                        
                    parm.result[0][y][x]+= parm.first_parm[0][y][z] * parm.second_parm[0][z][x] ;                
            }
        printf("\nOK.\n");       
   }
   else
       return;        
}

void mul_scalar(void)
{
    int x,y;    
    
   if(get_matrix_ASB()==OK)
   {
        /*Entering results from first Matrix and Scalar*/
        for(y=0;y<(SIZE) ;y++)
            for(x=0;x<(SIZE) ;x++)        
                    parm2.result[0][y][x]=parm2.first_parm[0][y][x] * parm2.scalar;      

        printf("\nOK.\n");       
   }
   else
       return;         
}

void trans_mat(void)
{
   int x,y;
    
   if(get_matrix_AB()==OK)
   {
        /*Entering results from first and second Matrix*/
        for(y=0;y<(SIZE) ;y++)
            for(x=0;x<(SIZE) ;x++)        
                    parm.result[0][y][x]=parm.first_parm[0][x][y]; 

        printf("\nOK.\n");       
   }
   else
       return;   
}

void stop(void)
{
printf("\nProgram stopped by user request.\n");
           
exit(0);
}

int get_matrix_ABC(void)
{
   char *ptr=NULL;
   char input[LEN]; 
   int i;
   
   fgets (input , 100 , stdin);
    
   ptr=strtok(input," ,\n"); /*cut Matrix A name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix A is missing, try again.\n");
        return ERROR;
    }
   else
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix does not exist , try again.\n");
                return ERROR;
            }
            else  
                parm.first_parm=mats[i].address;
           
   }
           
   ptr=strtok(NULL," ,\n"); /*cut Matrix B name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix B is missing, try again.\n");
        return ERROR;
    }
   else        
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else            
                parm.second_parm=mats[i].address;
   }
   
   ptr=strtok(NULL," ,\n"); /*cut Matrix C name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix C is missing, try again.\n");
        return ERROR;
    }
   else        
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else            
                parm.result=mats[i].address;
   }
   return OK;
}

int get_matrix_ASB(void)
{
   char *ptr=NULL;
   char input[LEN]; 
   int i;
   
   fgets (input , 100 , stdin);
    
   ptr=strtok(input," ,\n"); /*cut Matrix A name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix A is missing, try again.\n");
        return ERROR;
    }
   else
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else  
                parm2.first_parm=mats[i].address;
           
   }
           
   ptr=strtok(NULL," ,\n"); /*cut Scalar*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Scalar is missing, try again.\n");
        return ERROR;
    }
   else           
       parm2.scalar=strtod(ptr,&ptr);           

   ptr=strtok(NULL," ,\n"); /*cut Matrix B name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix B is missing, try again.\n");
        return ERROR;
    }
   else        
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else            
                parm2.result=mats[i].address;
   }
   return OK;    
}


int get_matrix_AB(void)
{
   char *ptr=NULL;
   char input[LEN]; 
   int i;
   
  fgets (input , 100 , stdin);
    
   ptr=strtok(input," ,\n"); /*cut Matrix A name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix A is missing, try again.\n");
        return ERROR;
    }
   else
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else  
                parm.first_parm=mats[i].address;
           
   }
           
   ptr=strtok(NULL," ,\n"); /*cut Matrix B name*/
    
   if(ptr==NULL) 
    {
        printf("\nERROR - Matrix B is missing, try again.\n");
        return ERROR;
    }
   else        
   {
            for(i=0; mats[i].address ;i++) /*find matrix*/
                if(strcmp(ptr,mats[i].name)==0)
                          break;

            if(mats[i].address==NULL)
            {
                printf("\nERROR - Matrix \"%s\" does not exist , try again.\n",ptr);
                return ERROR;
            }
            else            
                parm.result=mats[i].address;
   }
   
    return OK;
}


