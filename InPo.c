#include <stdio.h>
#include <ctype.h>

char stack[20];
int top=-1;

void Push(char x)
{
    stack[++top]=x;
}

char Pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int Priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    else if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
}

void main()
{
    char exp[100];
    char *e,x;
    printf("Enter The Expression : ");
    scanf("%s",&exp);
    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            printf("%c",*e);
        }
        else if(*e=='(')
        {
            Push(*e);
        }
        else if(*e==')')
        {
            while((x=Pop())!='(')
            {
                printf("%c ",x);
            }
        }
        else
        {
            while(Priority(stack[top])>Priority(*e))
            {
                printf("%c ",Pop());
                Push(*e);
            }
        }
    }
    while(Pop()!=-1)
    {
        printf("%c ",Pop());
    }
}