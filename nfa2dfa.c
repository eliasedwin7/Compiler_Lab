#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>

int stack[20],visitedarray[20],vmax=-1,top=-1,i=0,j=0,k=0,tmax=0,cl[20],ncl=0,dcount=0,newst[20],newc=0,trap=-1;
int qn1, qn2, qmax;
char ch,ch1='A';

void push(int v) { stack[++top]= v; }
int pop(){ if(top != -1) { return stack[top--]; } return -1; }
struct dfa
{
	char name;
	int stlist[20];
	int tran[2];
	int ns;
}dstates[20];
int svisited(int v)
{
	for(int y=0;y<vmax;y++)
		{	
			if(visitedarray[y] == v)
				return 1;
		}
	return -1;
}

void closure()
{
	FILE *fin, *fout;
	fin = fopen("input.txt","r");

	fscanf(fin," %d %d",&qmax,&tmax);
	fclose(fin);


			vmax=-1; top=-1;
			push(i);

			while(top != -1)
				{
					k=pop();
					if(svisited(k)==1)
						continue;
					visitedarray[++vmax]=k;

					cl[ncl++]=k;
					fin=fopen("input.txt","r");
					fscanf(fin," %d %d",&qmax, &tmax);
					j=0;
					while(j<tmax)
						{
							fscanf(fin, " %d %c %d",&qn1,&ch,&qn2);
							if(qn1 == k && ch == 'e' && svisited(qn2) != 1)
								push(qn2);
							j++;
						}
					fclose(fin);
				}

}
void sort()
{
	int x,z,swap;
	for(x=0;x<ncl;x++)
	{
		for(z=0;z<ncl-x-1;z++)
		{
			if(cl[z]>cl[z+1])
			{
				swap=cl[z];
				cl[z]=cl[z+1];
				cl[z+1]=swap;
			}
		}
	}
}

void main()
{
	int i1=0,j1=0,m,temp[20],tc=0,flag=0,x,j2=0,y;
	char _closure[11], copy[11];;
	int state,fr,to;
	char a_list[15];
	char b_list[15];

	FILE *c,*dfa, *nfa, *a, *b;
	c = dfa = nfa = a = b = NULL;		
	closure();

	dfa = fopen("dfa.txt","w");
	nfa = fopen("input.txt","r");
	
	//making 'a' & 'b' transitions files
	fscanf(nfa," %d %d",&qmax,&tmax);
	a = fopen("a.txt","w");
	b = fopen("b.txt","w");

	while(i1<tmax)
	{
		fscanf(nfa," %d %c %d",&qn1,&ch,&qn2);
		if( ch == 'a')
			fprintf(a,"%d %d\n",qn1,qn2);
		if( ch == 'b')
			fprintf(b,"%d %d\n",qn1,qn2);
		i1++;
	}
	fclose(a);
	fclose(b);
	fclose(nfa);


	sort();							
	for(m=0; m < ncl; m++)
	{
		dstates[0].stlist[m]=cl[m];
	}
	dstates[0].ns=ncl;
	dstates[0].name=ch1;
	dcount++;
	for(int g=0; g<dcount; g++)
	{
	for(int h=0;h<=1;h++)
	{	
		for(j1=0;j1<dstates[g].ns;j1++)
		{
			if(h==0)
				a=fopen("a.txt","r");
			else
				a=fopen("b.txt","r");
			while(fscanf(a,"%d %d",&fr,&to)!=EOF)
			{
				if(dstates[g].stlist[j1] == fr)
				{
					for(x=0; x<tc; x++)
					{
						if(temp[x] == to)
						{
							flag = 1;
							break;
						}
					}
					if(flag == 0)
					{
						temp[tc++] = to;
					}
					flag=0;				
					
				}
			}
			fclose(a);
		}
		if(tc == 0)
		{
			if(trap>=0)
				dstates[g].tran[h]=trap;
			else
			{
				dstates[dcount].stlist[0]=-1;
				dstates[dcount].ns=1;
				dstates[dcount].tran[0]=dcount;
				dstates[dcount].tran[1]=dcount;
				dstates[dcount].name='t';
				trap=dcount;
				dcount++;
				dstates[g].tran[h]=trap;
			}
	
		}
		else
		{
			for(j1=0;j1<tc;j1++)
			{
				ncl=0;	
				i=temp[j1];
				closure();
		
				for(i1=0; i1<ncl; i1++)
				{
					for(x=0; x<newc; x++)
					{
						if(cl[i1] ==  newst[x])
						{
							flag=1;
							break;	
						}
					}
					if(flag == 0)
					{
						newst[newc++] = cl[i1];
					}
					flag=0;
			
				}
			}

			ncl = newc;
			for(x=0;x<newc;x++)
				cl[x] = newst[x];
			sort();

			for(j2=0;j2<dcount;j2++)
			{	
				if(dstates[j2].ns == ncl)
				{
					for(x=0; x<dstates[j2].ns; x++)
					{
						if(dstates[j2].stlist[x] != cl[x])
						{
							flag=1;
							break;
						}	
					}
					if(flag == 0)
					{
						dstates[g].tran[h]=j2;
						flag=1;
						break;
					}
					flag=0;	
				}
		
			}//for j2
			if(flag !=1)
			{
				dcount++;
				for(m=0; m < ncl; m++)
				{
					dstates[dcount-1].stlist[m]=cl[m];
				}
				dstates[dcount-1].ns=ncl;
				ch1++;
				dstates[dcount-1].name=ch1;
				dstates[g].tran[h]=dcount-1;
			}
		}	
		tc=0;
		newc=0;
		flag=0;
	}
	}	
	printf("nfastate\tdfastate\tatran\tbtran\n");
	for(x=0;x<dcount;x++)
	{
		for(y=0;y<dstates[x].ns;y++)
		{
			printf("%d ",dstates[x].stlist[y]);
		}
		printf("\t%c\t",dstates[x].name);
		printf("\t%c\t%c",dstates[dstates[x].tran[0]].name,dstates[dstates[x].tran[1]].name);
		printf("\n");
	}
} 




