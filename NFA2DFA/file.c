

#include<stdio.h>
#include<stdlib.h>
char tr[20][3];
int s,t;
int visited[20];
FILE *fp1,*fp2,*fp3,*fp4;

void closure(int i)
{
	int j,si;
	i=i+'0';
	for(j=0;j<t;j++)
		{
		if(tr[j][0]==i && tr[j][1]=='e') 
			{
			si=tr[j][2]-'0';
			if(visited[si]==0)
				{
				visited[si]=1;
				fprintf(fp2," %d",si);
				closure(si);
				}
			}
		}

}
void main(){
/*	int i,j;
	
	fp1=fopen("text1.txt","w");
	fp2=fopen("text2.txt","w");
	printf("Enter the number of states:\n");
	scanf("%d",&s);

	printf("Enter the number of transition function:\n");
	scanf("%d",&t);
	printf("Enter the inputs:\n");
	for(i=0;i<t;i++){
		for(j=0;j<3;j++){
			scanf(" %c",&tr[i][j]);
			fprintf(fp1,"%c",tr[i][j]);
				}
                        fprintf(fp1,"\n");
			}

	for(i=0;i<s;i++){
	fprintf(fp2,"\n q%d = {%d",i,i);
	for(j=0;j<s;j++){
		visited[j]=0;
		}
		visited[i]=1;
		closure(i);
		fprintf(fp2,"}");

			}
			

printf("\n");

*/
int i;
fp3=fopen("text1.txt","r");
fp4=fopen("text2.txt","r");
char a[20],b[2];
fscanf(fp4," %s",a);
printf("%c\n",a[1]);
fscanf(fp4," %s",b);
if(b[1]==1)
printf("\n1");
else
printf("\n2");




	}
