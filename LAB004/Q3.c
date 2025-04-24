// Question 1

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n,target;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
    printf("\nOriginal array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("Enter value to be searched : ");
    scanf("%d",&target);
    int low=0,high=n-1,flag=0,index;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==target)
        {
            flag=1;
            index=mid;
            break;
        }
        else if (arr[mid]<target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    if (flag==1)
    {
        printf("Element is found at index %d\n",index);
    }
    else
    {
        printf("Element does not exist in the array!!!\n");
    }
    return 0;
}
