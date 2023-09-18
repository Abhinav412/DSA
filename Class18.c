//Binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
}NODE;

struct bst
{
    NODE *root;
};

typedef struct bst TREE;

void init(TREE *ptr)
{
    ptr->root=NULL;
}

NODE * getnode(int ele)
{
   NODE *temp;
   temp=(NODE *) malloc(sizeof(NODE));
   temp->data=ele;
   temp->rlink=NULL;
   temp->llink=NULL;
   return temp;

}

void insert_tree(TREE *ptr, int key)
{
    NODE *newNode = getnode(key);
    NODE *cur,*prev;
    if(ptr->root==NULL)
    {
        ptr->root = newNode;
    }
    else
    {
        prev=NULL;
        cur=ptr->root;
        while(cur!=NULL)
        {
            prev = cur;
            if(key < cur->data)
            {
                cur=cur->llink;
            }
            else
            {
                cur=cur->rlink;
            }
        }
        if(key < prev->data)
        {
            prev->llink = newNode;
        }
        else
        {
            prev->rlink = newNode;
        }
    }
}

void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->data);
        inorder(root->rlink);
    }
}

int main(void)
{
    int ch,ele,key,h;
    TREE tree;
    NODE *cur,*prev;
    intit(&tree);
    do
    {
        printf("1. insert_tree 2.search 3.inorder 4.delete");
        scanf("%d",ch);
        switch(ch)
        {
            case 1: printf("Enter the element:\n");
                    scanf("%d\n",&ele);
                    insert_tree(&tree,ele);
                    break;
        }
    }
    while(ch!=2);
}