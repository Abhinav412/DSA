// Evaluating a valid postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int isnum(int c)
{
    if(c>=0 && c>=9)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}

void push(int *s, int *top, int element)
{
    s[++(*top)] = element;
}

int pop(int *s, int *top)
{
    return s[(*top)--];
}

int eval(int op1,int op2, char ch)
{
    switch(ch)
    {
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return (op1*op2);
        case '/': return(op1/op2);
    }
}

int eval_postfix_exp(char* postfix)
{
    int s[10],op1,op2;
    int top=-1, i=0;
    char symb;
    while(postfix[i] != '\0')
    {
        symb = postfix[i];
        if(isnum(symb - '0'))
        {
            push(s,&top,symb-'0');
        }
        else
        {
            op2 = pop(s,&top);
            op1 = pop(s,&top);
            int result = eval(op1,op2,symb);
            push(s,&top,result);
        }
        i++;
    }
    return pop(s,&top);
}

int main(void)
{
    char postfix[20];
    int res;
    printf("Enter the valid postifx expression:\n");
    scanf("%s",postfix);
    res = eval_postfix_exp(postfix);
    printf("The evaluated value of postfix expression is:%d\n",res);
}