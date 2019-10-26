#include<stdio.h>
#include<stdlib.h>




int n,m=0,i=0,j=0,p,n;
char a[10][10],f[10];
void first(char c)
{
		int k;
		if(!isupper(c))
		{
		f[m++]=c;
		}
		for(k=0;k<n;k++)
		{if(a[k][0]==c)
		{
		if(a[k][2]=='$')
		{
		follow(a[k][0]);
		}
		else if((islower(a[k][2])) ||(isalpha(a[k][2])))
		{f[m++]=a[k][2];
		}
		else
		{first(a[k][2]);
		}
		}
		}
		}
		
		
void follow(char c)
{
		if(a[0][0]==c)
		{
		f[m++]='$';
		}
		for(i=0;i<n;i++)
		{
		for(j=0;j<strlen(a[i]);j++)
		{
		if(a[i][j]==c)
		{if(a[i][j+1]!='\0')
		first(a[i][j+1]);
		if(a[i][j+1]!='\0' && c!=a[i][0])
		{
		follow(a[i][0]);
		}
		}
		}
}}		
void main()
{
		int i,z;
		char c,h;
		printf("Enter the no of production/n");
		scanf("%d",&n);
		printf("Enter the production");
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
		}
		do
		{
			m=0;
			printf("Enter the elements whose first and follow is to be found:\n");
			scanf("%c",&c);
			first(c);
			printf("first(%c)={",c);
			for(i=0;i<m;i++)
			{
				printf("%c",f[i]);
			}
			printf("}\n");
			strcpy(f,"");
			m=0;
			follow(c);
			printf("Follow(%c)={",c);
			for(i=0;i<m;i++)
			{scanf("%c",f[i]);
		}
		printf("}\n");
		printf("Do you want to continue 1-yes,0-no\n");
		scanf("%d",&z);
		}while(z);
		return 0;
}
