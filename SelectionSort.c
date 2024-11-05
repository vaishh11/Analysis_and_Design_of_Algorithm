#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*a,int*b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void selectionSort(int arr[],int n)
{
int i,j,min;
for(i=0;i<n-1;i++){
min=i;
for(j=j+1;j<n;j++){

if(arr[j]<arr[min])
min=j;
}
swap(&arr[min],&arr[i]);
}
}
int main()
{
FILE *fp;
fp=fopen("random_numbers.txt","w");
int n_values[]={10000,15000,20000,25000,30000,35000};
int num_values=sizeof(n_values)/sizeof(n_values[0]);
fprintf(fp,"n,Time\n");
for(int k=0;k<num_values;k++)
{
int n=n_values[k];
int arr[n];
for(int i=0;i<n;i++)
{
arr[i]=rand();
fprintf(fp,"%d\n",arr[i]);
}
clock_t start=clock();
selectionSort(arr,n);
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken to sort %d elements:%f seconds\n",n,time_taken);
fprintf(fp,"%d,%f\n",n,time_taken);
}
fclose(fp);
return 0;
}
