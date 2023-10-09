#include<stdio.h>
#include<stdlib.h>

typedef struct bin_tree
{
    int data;
    struct bin_tree*llink;
    struct bin_tree *rlink;
}NODE;

NODE* create_tree()
{
    int key;
    printf("Enter the key to insert: ");
    scanf("%d",&key);
    if(key == -1)
    {
        return NULL;
    }
    else
    {
        NODE* temp  =(NODE*)malloc(sizeof(NODE));
        temp->data = key;
        printf("Enter the left child for the key %d:\n",key);
        temp->llink = create_tree();
        printf("Enter the right child for the key %d:\n",key);
        temp->rlink = create_tree();
        return temp;
    }
}

void preorder(NODE* root)
{
    if(root!=NULL)
    {
        printf("\n%d",root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

int main(void)
{
    NODE* root = NULL;
    root = create_tree();
}