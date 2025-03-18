// Question2
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[100]; // assuming user enter atmost this much elements
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter value for index %d :-", i);
        scanf("%d", &a[i]);
    }
    int index, elementval;
    printf("Enter position of element to insert:");
    scanf("%d", &index);
    printf("Enter value of element:");
    scanf("%d", &elementval);
    for (int i = size; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = elementval;
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}




