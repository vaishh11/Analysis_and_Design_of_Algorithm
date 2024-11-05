#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[],int left,int mid,int right)
{
int n1=mid-left+1;
int n2=right-mid;
int L[n1],R[n2];
for(int i=0;i<n1;i++)
L[i]=arr[left+i];
for(int j=0;j<n2;j++)
R[j]=arr[mid+1+j];
int i=0,j=0,k=left;
while(i<n1&&j<n2)
{
if(L[i]<=R[j])
{
arr[k]=L[i];
i++;
}
else
{
arr[k]=R[j];
j++;
}
k++;
}
while(i<n1)
{
arr[k]=L[i];
i++;
k++;
}
while(j<n2)
{

arr[k]=R[j];
j++;
k++;
}
}
void mergeSort(int arr[],int left,int right)
{
if(left<right)
{
int mid=left+(right-left)/2;
mergeSort(arr,left,mid);
mergeSort(arr,mid+1,right);
merge(arr,left,mid,right);
}
}
void generateRandomNumbers(int n)
{
FILE*file=fopen("random_numbers.txt","w");
srand(time(NULL));
for(int i=0;i<n;i++)
{
fprintf(file,"%d",rand());
}
fclose(file);
}
int main()
{
int n=10000;
generateRandomNumbers(n);
FILE*file=fopen("random_numbers.txt","r");
int numbers[n];
for(int i=0;i<n;i++)
{
fscanf(file,"%d",&numbers[i]);
}
fclose(file);
clock_t start=clock();
mergeSort(numbers,0,n-1);
clock_t end=clock();
double elapsed_seconds=(double)(end-start)/CLOCKS_PER_SEC;
printf("Time taken to sort %d elements using Merge Sort :%.6f seconds \n",n,elapsed_seconds);
return 0;
}
