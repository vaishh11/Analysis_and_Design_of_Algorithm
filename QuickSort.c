#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*a,int*b)
{
int temp=*a;
*a=*b;
*b=temp;

}
int partition(int arr[],int low,int high)
{
int pivot=arr[low];
int i=low+1;
int j=high;
while(1)
{
while(i<=j&&arr[i]<=pivot)
i++;
while(arr[j]>=pivot&&j>=i)
j--;
if(j<i)
break;
swap(&arr[i],&arr[j]);
}
swap(&arr[low],&arr[j]);
return j;
}
void quickSort(int arr[],int low,int high)
{
if(low<high)
{
int pivotIndex=partition(arr,low,high);
quickSort(arr,low,pivotIndex-1);
quickSort(arr,pivotIndex+1,high);
}
}
int main()
{
int n,i;
clock_t start,end;
double cpu_time_used;
printf("Enter the number of elements: ");
scanf("%d",&n);
int*arr=(int*)malloc(n*sizeof(int));
srand(time(NULL));
for(i=0;i<n;i++)
{
arr[i]=rand()%10000; //GeneraTING NO BETWEEN 0 AND 9999
}
start=clock();
quickSort(arr,0,n-1);
end=clock();
cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
printf("Sorted array:\n");
for(i=0;i<n;i++)
{
printf("%d",arr[i]);

}
printf("\n");
printf("Time taken for sorting %d elements:%lf seconds\n",n,cpu_time_used);
free(arr);
return 0;
}
