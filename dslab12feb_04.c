// Question 1

// #include<stdio.h>
// #include<stdlib.h>
// int main(int argc, char const *argv[])
// {
//     int n,target;
//     printf("Enter size of array : ");
//     scanf("%d",&n);
//     int * arr=(int *)malloc(n*sizeof(int));
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",arr+i);
//     }
//     printf("\nOriginal array\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",*(arr+i));
//     }
//     printf("Enter value to be searched : ");
//     scanf("%d",&target);
//     int low=0,high=n-1,flag=0,index;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         if (arr[mid]==target)
//         {
//             flag=1;
//             index=mid;
//             break;
//         }
//         else if (arr[mid]<target)
//         {
//             low++;
//         }
//         else
//         {
//             high--;
//         }
//     }
//     if (flag==1)
//     {
//         printf("Element is found at index %d\n",index);
//     }
//     else
//     {
//         printf("Element does not exist in the array!!!\n");
//     }
//     return 0;
// }






// Question 2

// #include <stdio.h>
// #include <stdlib.h>
// struct node {
//     int data;
//     struct node *next;
// };
// void createlinklist(struct node **listhead) {
//     int nodedata, numofnodes;

//     printf("Enter the number of nodes for the list: ");
//     scanf("%d", &numofnodes);

//     if (numofnodes <= 0) {
//         printf("Invalid number of nodes!\n");
//         return;
//     }
//     *listhead = NULL;  
//     struct node *currentnode = NULL; 

//     for (int i = 1; i <= numofnodes; i++) {
//         struct node *newnode = (struct node *)malloc(sizeof(struct node));
//         if (newnode == NULL) {
//             printf("Memory allocation failed at node %d!\n", i);
//             return;
//         }
//         printf("Enter value for node %d: ", i);
//         scanf("%d", &nodedata);
//         newnode->data = nodedata;
//         newnode->next = NULL;
//         if (*listhead == NULL) {
//             *listhead = newnode; 
//         } else {
//             currentnode->next = newnode;
//         }
//         currentnode = newnode;
//     }
// }
// int nodecount(struct node *listhead) {
//     int count = 0;
//     while (listhead != NULL) {
//         count++;
//         listhead = listhead->next;
//     }
//     return count;
// }
// void oddindexreverse(struct node **listhead) {
//     if (*listhead == NULL || (*listhead)->next == NULL) {
//         return;
//     }
//     int totalnodes = nodecount(*listhead), index = 0, count = 0;
//     int *a = (int *)malloc((totalnodes / 2 + 1) * sizeof(int)); 
//     if (a == NULL) {
//         printf("Memory allocation failed!\n");
//         return;
//     }
//     struct node *currentnode = *listhead;
//     // Store values at odd indices
//     while (currentnode != NULL) {
//         if (index % 2 == 0) {
//             a[count] = currentnode->data;
//             count++;
//         }
//         currentnode = currentnode->next;
//         index++;
//     }
//     // Reverse the stored odd index values into the linked list
//     currentnode = *listhead;
//     index = 0;
//     count--;
//     while (currentnode != NULL) {
//         if (index % 2 == 0) {
//             currentnode->data = a[count];
//             count--;
//         }
//         currentnode = currentnode->next;
//         index++;
//     }
//     free(a); 
// }
// void displaylist(struct node *listhead) {
//     while (listhead != NULL) {
//         printf("%d -> ", listhead->data);
//         listhead = listhead->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     struct node *listhead1 = NULL;

//     createlinklist(&listhead1);
//     printf("Original List: ");
//     displaylist(listhead1);

//     oddindexreverse(&listhead1);
//     printf("Modified List (Odd indices reversed): ");
//     displaylist(listhead1);
//     return 0;
// }



// Question 3
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
