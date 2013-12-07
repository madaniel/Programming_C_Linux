#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int main()
{
	double num1=0,num2=0,result=0;
	char arr[LEN]={0};
	int c=0,sign=0,i;
	
	printf("Please enter exercise [e.g. 1 + 2 <enter>]\n");
while ( (c=getchar() )!=EOF)
	{
		arr[0]=c; /*Saving the first char*/
		
		for(i=1;(c=getchar() )!=' ';i++) /*Taking chars until <space>*/
		{
			arr[i]=c;
		}
		num1=atof(arr);
		
		for (i=0;i<LEN;i++) /*Cleaning the array*/
			arr[i]=0;
		
		while( (sign=getchar() )==' '); /*Passing the spaces and saving the sign*/
			
		for(i=0;(c=getchar())!=10;i++) /*Taking chars until Enter*/
		{
			arr[i]=c;
		}
		num2=atof(arr);
		
		for (i=0;i<LEN;i++) /*Cleaning the array*/
			arr[i]=0;
		
		switch(sign) 
		{
			case '*':
			result=num1*num2;
			break;
			case '/':
			result=num1/num2;
			break;
			case '-':
			result=num1-num2;
			break;
			case '+':
			result=num1+num2;
			break;			
		}
		
		printf("%g %c %g = %g\n",num1,sign,num2,result);
	}	
	return 0;
}

