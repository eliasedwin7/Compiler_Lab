#include<stdio.h>
#include<stdlib.h>
char tr[20][3];
int s,t;
int visited[20];

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
				printf("->q%d",si);
				closure(si);
				}
			}
		}

}
void main(){
	int i,j;
	printf("Enter the number of states:\n");
	scanf("%d",&s);

	printf("Enter the number of transition function:\n");
	scanf("%d",&t);
	printf("Enter the inputs:\n");
	for(i=0;i<t;i++){
		for(j=0;j<3;j++){
			scanf(" %c",&tr[i][j]);
				}
			}

	for(i=0;i<s;i++){
	printf("\n e-closure of q%d is {q%d",i,i);
	for(j=0;j<s;j++){
		visited[j]=0;
		}
		visited[i]=1;
		closure(i);
		printf("}");

			}
			

printf("\n");
	}
