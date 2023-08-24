// Doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* llink;
    struct node* rlink;
}NODE;

struct list
{
    NODE *head;
};
typedef struct list DLIST;

void init(DLIST *p_dlist)
{
    p_dlist->head = NULL;
}

NODE* getnode(int ele)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->rlink=NULL;
    temp->llink=NULL;
    return temp;
}

void insert_front(DLIST *p_dlist, int ele)
{
    NODE *newNode;
    newNode = getnode(ele);
    if(p_dlist->head == NULL)
    {
        p_dlist->head = newNode;
    }
    else
    {
        newNode->rlink = p_dlist->head;
        p_dlist->head->llink = newNode;
        p_dlist->head = newNode;
    }
}

void delete_front(DLIST *p_dlist)
{
    if(p_dlist->head == NULL)
    {
        printf("Cannot delete\n");
    }   
    else
    {
        NODE *aux = p_dlist->head;
        p_dlist->head = p_dlist->head->rlink;
        free(aux);
    }
}

void display(DLIST *p_dlist)
{
    NODE *aux = p_dlist->head;
    while(aux!=NULL)
    {
        printf("\n%d",aux->data);
        aux = aux->rlink;
    }
}

int main(void)
{
    int ch,ele;
    DLIST listv;
    init(&listv);
    do
    {
    printf("Enter the choice 1: insert_front 2: delete_front 3: display() 4: Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_front(&listv,ele);
                break;
        case 2: delete_front(&listv);
                break;
        case 3: display(&listv);
                break;
        case 4: exit(0);
    }
    }while(ch!=4);
}