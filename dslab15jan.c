// // Question1
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
//     printf("Array :\n");
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ",a[i]);
//     }
//     return 0;
// }



// Question2
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int a[100]; // assuming user enter atmost this much elements
//     int size;
//     printf("Enter size of array:");
//     scanf("%d", &size);
//     for (int i = 0; i < size; i++)
//     {
//         printf("Enter value for index %d :-", i);
//         scanf("%d", &a[i]);
//     }
//     int index, elementval;
//     printf("Enter position of element to insert:");
//     scanf("%d", &index);
//     printf("Enter value of element:");
//     scanf("%d", &elementval);
//     for (int i = size; i > index; i--)
//     {
//         a[i] = a[i - 1];
//     }
//     a[index] = elementval;
//     for (int i = 0; i <= size; i++)
//     {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }




// Question3
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
//     for (int i = 0; i < size; i++)
//     {
//         if(a[i]==element)
//         {
//             printf("Element found at index %d",i);
//             flag=1;
//             break;
//         }
//     }
//     if(flag==0)
//     {
//         printf("Element not found");
//     }

//     return 0;
// }



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



// Question4 sorting using selection sort 
// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//     int num;
//     printf("Enter size of array:");
//     scanf("%d",&num);
//     int a[num];
//     for (int i = 0; i < num; i++)
//     {
//         printf("Enter value for index %d :-",i);
//         scanf("%d",&a[i]);
//     }
//     int endpos = num - 1, index, max;
//     for (int i = 0; i < num - 1; i++)
//     {
//         max = a[endpos];  
//         index = endpos;     
//         for (int j = 0; j <= endpos; j++)  
//         {
//             if (a[j] > max)
//             {
//                 max = a[j];
//                 index = j;
//             }
//         }
//         int temp = a[index];
//         a[index] = a[endpos];
//         a[endpos] = temp;
        
//         endpos--;  
//     }
//     return 0;
// }



// Question6
// #include<stdio.h>
// int main(int argc, char const *argv[])
// {
//     int num;
//     printf("Enter size of array:");
//     scanf("%d",&num);
//     int a[100];
//     for (int i = 0; i < num; i++)
//     {
//         printf("Enter value for index %d :-",i);
//         scanf("%d",&a[i]);
//     }
//     int index;
//     printf("Enter index of element to delete:");
//     scanf("%d",&index);
//     for (int i = index; i <=num-2; i++)
//     {
//         a[i]=a[i+1];
//     }
    
//     num--;
//     printf("Array after deletion:\n");
//     for (int i = 0; i <num ; i++)
//     {
//         printf("%d ",a[i]);
//     }
    
//     return 0;
// }



// Question7
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    printf("Enter size of array:");
    scanf("%d",&num);
    int a[num];
    for (int i = 0; i < num; i++)
    {
        printf("Enter value for index %d :-",i);
        scanf("%d",&a[i]);
    }
    //Sorting at even index
    for (int i = 0; i < num; i=i+2)
    {
        if (a[i]>a[i+2])
        {
            int temp=a[i];
            a[i]=a[i+2];
            a[i+2]=temp;
        }
    }
    printf("Array after sorting at even index:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",a[i]);
    }
    
    //sorting at odd index
    for (int i = 1; i < num; i=i+2)
    {
        if (a[i]>a[i+2])
        {
            int temp=a[i];
            a[i]=a[i+2];
            a[i+2]=temp;
        }
    }
    printf("\nArray after sorting at odd index:\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}


