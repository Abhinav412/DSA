#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}NODE;

struct list
{
    NODE *head;
};
typedef struct list LIST;

NODE* getnode(int ele)
{
    NODE* temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->link=NULL;
    return temp;
}

void init(LIST *p)
{
    p->head = NULL;
}

void insert_front(LIST *p, int ele)
{
    NODE *newNode;
    newNode = getnode(ele);
    newNode->link = p->head;
    p->head = newNode;
}

void display(LIST* ptr)
{
    NODE *aux;
    aux  = ptr->head;
    while(aux!=NULL)
    {
        printf("%d\n",aux->data);
        aux = aux->link;
    }
}

int main(void)
{
    int ch,ele;
    LIST p_list;
    init(&p_list);
    do
    {
    printf("Enter the choice 1: insert_front 2: insert_rear 3: delete_front 4: delete_rear 5: key_search 6: Display() 7: Exit() \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the element to insert:\n");
                scanf("%d",&ele);
                insert_front(&p_list,ele);
                break;
        case 2: display(&p_list);
                break;
    }
    }while(ch!=3);
}