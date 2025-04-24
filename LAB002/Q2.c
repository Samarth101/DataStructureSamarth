#include <stdio.h>
#include <stdlib.h>
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
    int n, sum = 0;
    float sma;
    printf("Enter window size : ");
    scanf("%d", &n);
    if (n > size)
    {
        printf("Window size is greater than the array size!!!\n");
        free(arr);
        return 0;
    }

    for (int i = size - n; i < size; i++)
    {
        sum += *(arr + i);
    }
    sma = (float)sum / n;
    printf("Simple moving average for at the last %d day is = %0.2f", n, sma);
    free(arr);
    return 0;
}
