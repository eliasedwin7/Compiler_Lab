#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int keywordfun(char *buffer)
{
	
	char keyword[9][10]={"do","while","if","else","int","float","void","return"};
	int h=0;
	for(int i=0;i<8;i++)
	{
		if(strcmp(buffer,keyword[i])==0)
		{
			printf("\n%s:keyword",buffer);
			h=1;
			break;
		}
	}
	if(h==1)
	{
		return 1;
	}
	else
	{
	        return 0;
	}
}
	

void main()
{
	char relop[]="<>!=",sep[]="{}.,;()",logical[]="&|",buffer[20],arith[]="+-/%*",ch,ch1;
	FILE *f=fopen("input.txt","r");
	int i,flag=0,g=0,j;
	if(f==NULL)
	{
		printf("\nFile cannot be opened");
		exit(0);
	}
	else
	{
		while((ch=fgetc(f))!=EOF)
		{
			for(i=0;arith[i]!='\0';i++)
			{
				if(ch==arith[i])
				{
					printf("\n%c-arithmetic operator",ch);
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				flag=0;
				continue;
			}
			for(i=0;sep[i]!='\0';i++)
			{
				if(ch==sep[i])
				{
					printf("\n%c-seperator",ch);
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				flag=0;
				continue;
			}
			for(i=0;relop[i]!='\0';i++)
			{
				if(ch==relop[i])
				{	
					ch1=fgetc(f);
					if(ch1=='=')
					{
						printf("\n%c= -relational operator",ch);
						flag=1;
						break;
					}
					else
					{
						ungetc(ch1,f);
						printf("\n%c -relational operator",ch);
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
			{
				flag=0;
				continue;
			}
			for(i=0;logical[i]!='\0';i++)
			{
				if(ch==logical[i])
				{	
					ch1=fgetc(f);
					if(ch1==ch)
					{
						printf("\n%c%c - logical operator",ch,ch1);
						flag=1;
						break;
					}
					else
					{
						ungetc(ch1,f);
						printf("\n%c : bitwise operator",ch);
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
			{
				flag=0;
				continue;
			}
			if(isdigit(ch))
			{
				printf("\n%c - digit",ch);
				continue;
			}
			if(isalpha(ch))
			{
				j=0;
				buffer[j++]=ch;
				ch1=fgetc(f);
				while(ch1!=' ')
				{
					buffer[j++]=ch1;
					ch1=fgetc(f);
				}
				buffer[j++]='\0';
				g=keywordfun(buffer);
				if(g==0)
				{
					printf("\n%s:identifier",buffer);
					continue;
				}
			}
		}
	}
 	printf("\n");
fclose(f);
}











			
			
