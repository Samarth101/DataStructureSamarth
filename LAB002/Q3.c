#include <stdio.h>
#include <stdlib.h>
float emacalc(int arr[], float alpha,int n)
{
    if (n==1)
    {
        return arr[n-1];
    }
    return ((alpha*arr[n-1])+(1-alpha)*emacalc(arr,alpha,n-1));
}
int main(int argc, char const *argv[])
{
    int size;
    printf("Enter size of array :\n");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for index %d : ", i);
        scanf("%d", arr + i);
    }
    int n;
    float alpha;
    printf("Enter window size : ");
    scanf("%d", &n);
    if (n > size)
    {
        printf("Window size is greater than the array size!!!\n");
        free(arr);
        return 0;
    }
    alpha=2.0/(n+1);
    float ema=emacalc(arr,alpha,n);
    printf("EMA for last %d days : %0.2f",n,ema);
    return 0;
}
