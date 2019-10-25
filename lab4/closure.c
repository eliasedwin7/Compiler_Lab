#include<stdio.h>
#include<stdlib.h>

int stack[20];
int transaction[20][2];
char sym[20];
int list[20];
int alpha_len,state_len,trans_len;
int top;
int closure_list[20];
void push(int c)
{
if(top<20)
{
stack[top]=c;
top++;
}
}

void pop()
{
top--;
}

void closure()
{

int count;
int temp;
int j,i;
int flag = 0;

while(top>=0)
{
flag = 0;
temp = stack[top];
pop();
closure_list[0] = temp;
count = 0;
for(i=0;i<trans_len;i++)
{
if(transaction[i][0] == temp && sym[i] == 'e')
{
for(j=0;j<count;j++)
{
if(temp == closure_list[j])
{
	flag = 1;
	break;
}
}
if(flag == 0){
count++;
closure_list[count]=transaction[i][1];
push(transaction[i][1]);
}
}
}
printf("The Epsilon closure of %d:\n",temp);
for(i = 0; i<count;i++)
{
printf("%d,",closure_list[i]);
}
printf("\n");
}
}

int main()
{

int i;
top = 0;

printf("Enter the number of states:\n");
scanf("%d",&state_len);

for(i=0;i<state_len;i++)
push(i);
for(i=0;i<state_len;i++)
printf("%d",stack[i]);

printf("Enter the number of transition function:\n");
scanf("%d",&trans_len);

printf("Use format: <Current_state><Input_symbol><Next_state>\nUse e as Epsilon\n");
printf("Enter the transistions:\n");
for(i=0;i<trans_len;i++)
{
scanf("%d",&transaction[i][0]);
scanf("%c",&sym[i]);
scanf("%d",&transaction[i][1]);
}
for(i=0;i<trans_len;i++)
{
printf("%d %c %d\n",transaction[i][0],sym[i],transaction[i][1]);
}

f
closure();

return(0);
}
