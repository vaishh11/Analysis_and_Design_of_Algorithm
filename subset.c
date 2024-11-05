#include<stdio.h>
//#include<conio.h>
int s[10],d,n,set[10],count=0;
void display(int);
int flag=0;
void main()
{
int subset(int,int);
int i;
printf("ENTER THE NUMBER OF THE ELEMENTS IN THE SET:");
scanf("%d",&n);
printf("ENTER THE SET OF VALUES:");
for(i=0;i<n;i++)
scanf("%d",&s[i]);
printf("ENTER THE SUM:");
scanf("%d",&d);
printf("THE PROGRAM OUTPUT IS:");
subset(0,0);
if(flag==0)
printf("There is no solution");
}
int subset(int sum,int i)
{

if(sum==d)
{
flag=1;
display(count);
return 1;
}
if(sum>d||i>=n)
return 0;
else
{
set[count]=s[i];
count++;
subset(sum+s[i],i+1);
count--;
subset(sum,i+1);
}
}
void display(int count)
{
int i;
printf("\t{");
for(i=0;i<count;i++)
printf("%d,",set[i]);
printf("}");
}
