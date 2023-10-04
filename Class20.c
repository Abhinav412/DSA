#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node* llink;
    struct node* rlink;
}NODE;

NODE *stk[50];
NODE* getnode(char ch)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data = ch;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

int isoper(char ch)
{
    if(ch>='a'&& ch<='z')
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

NODE* create_exptree()
{
    int i=0, k=-1;
    char ch;
    char postfix[20];
    NODE* temp;

    printf("Enter the Postfix Expression : ");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        ch = postfix[i];
        temp = getnode(ch);
        if(isoper(ch))
        {
            stk[++k] = temp;
        }
        else
        {
            temp->rlink = stk[k--];
            temp->llink = stk[k--];
            stk[++k] = temp;
        }
        i++;
    }
    return stk[k];
}

void inorder(NODE* root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%c",root->data);
        inorder(root->rlink);
    }
}

// Function to evaluate expression tree
float eval(NODE* root)
{
    int ele,lval,rval;

    // Base case: leaf node
    if(root->llink==NULL && root->rlink==NULL)
    {
        printf("Enter the value for %c",root->data);
        scanf("%d",&ele);
        return ele;
    }

    // Recursive case: evaluate left and right subtrees
    lval = eval(root->llink);
    rval = eval(root->rlink);

    // Evaluate operation and return result
    switch(root->data)
    {
        case '+': return lval+rval;
        case '-': return lval-rval;
        case '*': return lval*rval;
        case '/': return lval/rval;
    }
}

int main(void)
{
    NODE* root = NULL;
    float res;
    root = create_exptree();
    inorder(root);
    res = eval(root);
}