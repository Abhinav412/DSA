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

void insert_rear(DLIST *p_dlist, int ele)
{
    NODE *newNode,*cur;
    newNode = getnode(ele);
    if(p_dlist->head == NULL)
    {
        p_dlist->head = newNode;
    }
    else
    {
        cur = p_dlist->head;
        while(cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        cur->rlink = newNode;
        newNode->llink = cur;
    }
}

void delete_rear(DLIST *p_dlist)
{
    NODE *cur,*prev;
    if(p_dlist->head == NULL)
    {
        printf("Cannot delete");
        return;
    }
    else if(p_dlist->head->rlink == NULL)
    {
        cur = p_dlist->head;
        free(cur);
    }
    else
    {
        cur = p_dlist->head;
        while(cur->rlink != NULL)
        {
            cur = cur->rlink;
        }
        prev = cur->llink;
        free(cur);
        prev->rlink = NULL;
    }
}

void display(DLIST *p_dlist)
{
    NODE *aux = p_dlist->head;
    while(aux!=NULL)
    {
        printf("%d\n",aux->data);
        aux = aux->rlink;
    }
}

void delete_pos(DLIST p_dlist, int pos)
{}

int main(void)
{
    int ch,ele,pos;
    DLIST listv;
    init(&listv);
    do
    {
    printf("Enter the choice 1: insert_front 2: delete_front 3: display() 4: insert_rear 5: delete_rear 6: delete_pos 7: Exit\n");
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
        case 4: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_rear(&listv,ele);
                break;
        case 5: delete_rear(&listv);
                break;
        case 6: delete_pos(&listv,pos);
                break;        
        case 7: exit(0);
    }
    }while(ch!=4);
}