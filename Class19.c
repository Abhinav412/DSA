// Binary search trees using arrays

#include<stdio.h>
#define MAX 50

void create_tree(int *a,int ele)
{
    int i=0;
    while(i<MAX && a[i]!=-1)
    {
        if(ele<a[i])
        {
            i=2*i+1;
        }
        else
        {
            i=2*i+2;
        }
    }
    a[i] = ele;
}

void inorder(int *a,int i)
{
    if(a[i]==-1)
    {
        return;
    }
    inorder(a,2*i+1);
    printf("%d\n",a[i]);
    inorder(a,2*i+2);
}

void postorder(int *a,int i)
{
    if(a[i]==-1)
    {
        return;
    }
    postorder(a,2*i+1);
    postorder(a,2*i+2);
    printf("%d\t",a[i]);
    printf("\n");
}

void preorder(int *a,int i)
{
    if(a[i]==-1)
    {
        return;
    }
    printf("%d\t",a[i]);
    printf("\n");
    preorder(a,2*i+1);
    preorder(a,2*i+2);
}

int main(void)
{
    int a[MAX];
    int ch,ele;
    for(int i=0;i<MAX;i++)
    {
        a[i]=-1;
    }
    while(1)
    {
        printf("1.Create a BST 2.Inorder Traversal 3.Preorder Traversal 4.Postorder Traversal\n");
        printf("Enter your choice:\n");
        scanf("%d\n",&ch);
        switch(ch)
        {
            case 1: printf("Enter an element:\n");
                    scanf("%d\n",&ele);
                    create_tree(a,ele);
                    break;
            case 2: inorder(a,0);
                    break;
            case 3: preorder(a,0);
                    break;
            case 4: postorder(a,0);
                    break;
        }
    }
}