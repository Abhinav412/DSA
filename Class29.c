#include<stdio.h>

#define tab_size 10

typedef struct inventry
{
    int p_id;
    int no_parts;
    int flag;
}parts;

void init(parts *p)
{
    for(int i=0; i<tab_size; i++)
    {
        p[i].flag = 0;
    }
}

void insert(parts *p,int pid, int pno, int *count)
{
    int key, k=1;
    if(*count==tab_size)
    {
        printf("Table is full\n");
        return;
    }
    key = pid%tab_size;
    while(p[key].flag == 1)
    {
        key = (key+(k*k))%tab_size;
        k = k*k+1;
    }
    p[key].p_id = pid;
    p[key].no_parts = pno;
    p[key].flag = 1;
    printf("\nPart id = %d",p[key].p_id);
    printf("\nNo.of parts = %d",p[key].no_parts);
    *count++;
    return;
}

void display(parts *p)
{
    for(int i=0; i<tab_size; i++)
    {
        if(p[i].flag == 1)
        {
            printf("Part id: %d\n",p[i].p_id);
            printf("No.of parts: %d\n",p[i].no_parts);
        }
    }
}

void delete(parts *p, int pid, int *count)
{
    int i=0,k=1;
    if(*count == 0)
    {
        printf("Empty hash table cannot delete");
        return;
    }
    int p_id = pid % tab_size;
    while(p[p_id].flag != 0 && i<tab_size)
    {
        p_id = (p_id+1)% tab_size;
        i=i+1;
    }
    if(p[p_id].p_id == pid && p[p_id].flag == 1)
    {
        p[p_id].flag = 0;
        *count = *count-1;
    }
    else
    {
        printf("ID not found");
    }
}

int main(void)
{
    int ch,pid,pno,count=0;
    parts p[tab_size];
    init(p);
    do
    {
        printf("Enter 1.Insert 2.Display 3.Delete 4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the part id and no.of parts: ");
                    scanf("%d %d",&pid,&pno);
                    insert(p,pid,pno,count);
                    break;
            case 2: display(p);
                    break;
            case 3: printf("Enter the part id to delete: ");
                    scanf("%d",&pid);
                    delete(p,pid,count);
                    break;
            case 4: exit(0);
        }
    } 
    while(ch!=4);
}