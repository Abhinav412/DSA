//Stack in C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACKSIZE 100

typedef struct stack
{
    int top;
    int items[STACKSIZE];
}STACK;

void push(STACK *ps,int ele)
{
    if(ps->top==STACKSIZE-1)
    {
        printf("Stack is full\n");
    }
    else
    {
        ps->top++;
        ps->items[ps->top] = ele;
    }
}

int pop(STACK *ps)
{
    if(ps->top == -1)
    printf("Empty stack\n");
    else
    {
        int x = ps->items[ps->top];
        (ps->top)--;
        return x;
    }
    return -1;
}

void display(STACK *ps)
{
    if(ps->top == -1)
    {
        printf("Empty stack\n");
    }
    else
    {
        for(int i=ps; i>=0; i--)
        {
            printf("%d\n",ps->items[ps->top]);
        }
    }
}

int main(void)
{
    int ch,ele;
    STACK s;
    s.top = -1;
    do
    {
        printf("1.push() 2.display() 3.pop() 4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted:\n");
                    scanf("%d\n",&ele);
                    push(&s,ele);
                    break;
            case 2: display(&s);
                    break;
            case 3: ele = pop(&s);
                    if(ele == -1)
                    {
                        printf("Empty stack\n");
                    }
                    else
                    {
                        printf("Popped element is:%d\n",ele);
                    }
                    break;
            case 4: exit(0);
        }
    }
    while(ch!=5);
}