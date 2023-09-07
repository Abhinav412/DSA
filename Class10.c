//Infix to postfix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int input_prcd(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if( ch=='*' || ch== '/')
        return 3;
    else if(ch=='$')
        return 6;
    else if(isalpha(ch))
        return 9;
    else if(ch=='(')
        return 7;
    else if(ch==')')
        return 0;
}

int stack_prcd(char ch)
{
    if(ch=='+' || ch=='-')
        return 2;
    else if(ch=='*' || ch=='/')
        return 4;
    else if(ch=='$')
        return 5;
    else if(isalpha(ch))
        return 9;
    else if(ch=='(')
        return 0;
    else if(ch=='#')
        return -1;
}