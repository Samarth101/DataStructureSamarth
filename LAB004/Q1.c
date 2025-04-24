// Question 1
#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for (int j =low ; j <high; j++)    {
        if (arr[j]<=pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}
int quickselect(int arr[],int low,int high,int k)
{
    if (low<=high)
    {
        int pivotindex=partition(arr,low,high);

        if (k==pivotindex+1)
        {
            return arr[pivotindex];
        }
        if (pivotindex+1>k)
        {
            quickselect(arr,low,pivotindex-1,k);
        }
        else
        {
            quickselect(arr,pivotindex+1,high,k);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n,k;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
    printf("Array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\nEnter value of k : ");
    scanf("%d",&k);
    printf("\n%dth smallest element from array is : %d",k,quickselect(arr,0,n-1,k));
    printf("\n%dth largest element from array is : %d",k,quickselect(arr,0,n-1,n-k+1));
    if (n%2==0)
    {
        printf("\nMedian from array is : %d",(quickselect(arr,0,n-1,n/2+1)+quickselect(arr,0,n-1,n/2))/2.0);
    }
    else
    {
        printf("\nMedian from array is : %d",quickselect(arr,0,n-1,n/2+1));
    }
    
    
    return 0;
}
