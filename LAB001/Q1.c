// Question1
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    int a[size];
    for (int i = 0; i < size; i++)
    {

        printf("Enter value for index %d :-",i);
        scanf("%d",&a[i]);
    }
    printf("Array :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
