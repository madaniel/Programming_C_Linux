#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

char s1[LEN]={0},s2[LEN]={0};

void contract(char s1[],char s2[])
{
	int i=0,j=0,start=0,end=0;
	
	switch (strlen(s1))
	{
		case 0:
			return;			
		case 1:
			s2[0]=s1[0];
			return;			
		case 2:
			s2[0]=s1[0];
			s2[1]=s1[1];
			return;			
	}
	
	/*Scan the array */
	while(i < strlen(s1) -2)
	{		
		if (s1[i]+1 == s1[i+1] && s1[i]+2 == s1[i+2]) /*serial found*/			
			{
				start=i;
				end=i+2;
				i+=2;
				while (i < strlen(s1) -1 && s1[i]+1==s1[i+1]) /*serial continue*/
				{
					end++;
					i++;
				}
				s2[j]=s1[start]; /*copy serial in short format*/
				s2[j+1]='-';
				s2[j+2]=s1[end];								
				j+=2;
			}
		else /*not a serial*/
		{
			s2[j]=s1[i];
			i++;
			j++;				
		}				
	}
	/*copy the last parts, if any*/
	while (i < strlen(s1) )
	{
		s2[j]=s1[i];
		i++;
		j++;
	}
	
}

int main()
{
	int i=0;
	while (1)
	{
		printf("\nEnter characters: [e.g. abcd]\n");
		if (scanf("%s",s1)==EOF )
			break;			
		contract(s1,s2);
		printf("\n%s\n",s2);
		for (i=0;i < LEN ;i++)
			s2[i]=0;
	}
	return 0;
}



