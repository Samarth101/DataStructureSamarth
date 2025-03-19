#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define stacksize 100
int stack[stacksize];
int top=-1;

int parenthesischeck(char * exp)
{
    for (int i = 0; exp[i]!='\0'; i++)
    {
        char c=exp[i];
        if (c=='(' || c=='{' || c=='[')
        {
            stack[++top]=c;
        }
        else if (c==')' || c=='}' || c==']')
        {
            if (top==-1)
            {
                return -1;
            }
            
            if (c==')')
            {
                if (stack[top]=='(')
                {
                    top--;
                }
                else
                {
                    return -1;
                }
                
            }
            else if (c=='}')
            {
                if (stack[top]=='{')
                {
                    top--;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (stack[top]=='[')
                {
                    top--;
                }
                else
                {
                    return -1;
                }
            }
        }
        else
        {
            printf("Enter valid expression!!!\n");
            return -1;
        }
    }
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main(int argc, char const *argv[])
{
    char expression[100];
    printf("Enter string : ");
    scanf("%[^\n]s",expression);
    int result=parenthesischeck(expression);
    if (result==1)
    {
        printf("STring have balance parenthesis\n");
    }
    else
    {
        printf("String does not have balance parenthesis!!!\n");
    }
    return 0;
}
