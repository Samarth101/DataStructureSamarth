// Question3
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
    printf("Enter element to be searched:");
    int element;
    scanf("%d",&element);
    int flag=0;
    for (int i = 0; i < size; i++)
    {
        if(a[i]==element)
        {
            printf("Element found at index %d",i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Element not found");
    }

    return 0;
}



// Question3 Binary
// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//     int size;
//     printf("Enter size of array:");
//     scanf("%d",&size);
//     int a[size];
//     for (int i = 0; i < size; i++)
//     {

//         printf("Enter value for index %d :-",i);
//         scanf("%d",&a[i]);
//     }
//     printf("Enter element to be searched:");
//     int element;
//     scanf("%d",&element);
//     int flag=0;
//     int low=0,high=size-1;
//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if(a[mid]==element)
//         {
//             printf("Element found at index %d",mid);
//             flag=1;
//             break;
//         }
//         else if(a[mid]<element)
//         {
//             low=mid+1;
//         }
//         else
//         {
//             high=mid-1;
//         }
//     }
//     if(flag==0)
//     {
//         printf("Element not found");
//     }
//     return 0;
// }
