

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
char tr[20][3];
int s,t;
int visited[20];
FILE *fp1,*fp2,*fp3,*fp4,*f3,*fp5,*fp6;

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
int i,t;
f3=fopen("text1.txt","r");
fp4=fopen("text2.txt","r");
fp1=fopen("a.txt","w");
fp2=fopen("b.txt","w");
char a[100],b[10],y[20],d[2];;



while(fscanf(fp4,"%s",a)!=EOF){
	printf("\n%s\n",a );

	int x=strlen(a);
	t=0;
while(t<x)
{
	printf("%c\t",a[t] );
while(fscanf(f3,"%s",b)!=EOF)
{
	printf("%s\t",b );
if(b[0]==a[t])
{
if(b[1]=='1'){
//fprintf("\n\na%c\n\n",d[2]);
fprintf(fp1,"a%c\t",b[2]);
}
if(b[1]=='2')
//printf("\n\nb%c\n\n",b[2]);
fprintf(fp2,"b%c\t",b[2]);

}
}
fprintf(fp1,"\n");
fprintf(fp2,"\n");
rewind(f3);
printf("\n" );
t++;
}
}



//printf("%c\n",a[1]);


fclose(fp1);
fclose(fp2);
fclose(f3);
fclose(fp4);
printf("\n\n" );




	}
