#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stacksize 100
int stack[stacksize];
int top=-1;

int palindromecheck(char * exp)
{
    int len=strlen(exp),i=0;
    int halflen=(len%2==0)?len/2:len/2+1;
    char c;
    while (i<halflen)
    {
        c=exp[i];
        stack[++top]=c;
        i++;
    }
    if (len%2!=0)
    {
        top--;
    }
    while (top!=-1)
    {
        c=exp[i];
        if (c==stack[top])
        {
            top--;
        }
        else
        {
            return -1;
        }
        i++;
    }
    if (top==-1)
    {
        return 1;
    }
}
int main(int argc, char const *argv[])
{
    char expression[100];
    printf("Enter string : ");
    scanf("%[^\n]s",expression);
    int result=palindromecheck(expression);
    if (result==1)
    {
        printf("STring is palindrome\n");
    }
    else
    {
        printf("String is not a palindrome!!!\n");
    }
    return 0;
}
