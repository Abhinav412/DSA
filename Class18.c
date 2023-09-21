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

void postorder(NODE *root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->data);
    }
}

void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

int countleaf(NODE *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->rlink==NULL && root->llink==NULL)
    {
        return 1;
    }
    else
    {
        return countleaf(root->rlink)+countleaf(root->llink);
    }
}

NODE* delete_node(NODE *root,int ele)
{
    NODE *temp = NULL;
    if(root==NULL)
    {
        return root;
    }
    if (ele < root->data)
    {
        root->llink = delete_node(root->llink,ele);
    }
    else if(ele > root->data)
    {
        root->rlink = delete_node(root->rlink,ele);
    }
    else
    {
        if(root->llink == NULL)
        {
            temp = root->rlink;
            free(root);
            return temp;
        }
        else if(root->rlink == NULL)
        {
            temp = root->llink;
            free(root);
            return temp;
        }
    }
    NODE *cur = root->rlink;
    while(cur->llink!=NULL)
    {
        cur = cur->llink;
    }
    root->data = cur->data;
    root->rlink = delete_node(root->rlink,root->data);
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