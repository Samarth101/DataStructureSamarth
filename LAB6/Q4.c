#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define stacksize 100
char stack[stacksize];
char result[stacksize + 1];
int top = -1;

int precedance(char operand)
{
    if (operand == '^')
    {
        return 3;
    }
    else if (operand == '*' || operand == '/')
    {
        return 2;
    }
    else if (operand == '+' || operand == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void infixtopostfix(char *exp)
{
    int j = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];
        if (isalnum(c))
        {
            result[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = '(';
        }
        else if (c == ')')
        {
            while (stack[top] != '(' && top != -1)
            {
                result[j++] = stack[top--];
            }
            if (top != -1)
            {
                top--;
            }
        }
        else
        {
            while (top != -1 && precedance(c) <= precedance(stack[top]))
            {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top!=-1)
    {
        result[j++]=stack[top--];
    }
    result[j]='\0';
    
}

int main(int argc, char const *argv[])
{
    char expression[100];
    printf("Enter INFIX expression : ");
    scanf("%[^\n]s", expression);
    infixtopostfix(expression);
    printf("\nPOSTFIX : %s\n",result);
    return 0;
}
