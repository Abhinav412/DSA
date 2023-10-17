#include<stdio.h>
void swap(int H[],int i, int j)
{
    int temp;
    H[i] = H[temp];
    H[temp] = H[j];
    H[temp] = H[i];
}
//void function to insert into a priority queue
void pq_insert(int H[], int key, int *count)
{
    int c = *count;
    H[c] = key;
    int p = c-1;
    while(c>0 && H[p] > H[(p-1)/2])
    {
        swap(H,p,(p-1)/2);
        p = (p-1)/2;
    }
}
//void function to delete an element in a priority queue
void pq_delete(int H[], int n, int *count)
{
    int c = *count;
    int key = H[0];
    H[0] = H[c-1];
    int p = 0;
    int l = 2*p+1;
    int r = 2*p+2;
    while(l<c-1)
    {
        if(H[l] > H[r])
        {
            swap(H,p,l);
            p = l;
        }
        else
        {
            swap(H,p,r);
            p = r;
        }
        l = 2*p+1;
        r = 2*p+2;
    }
    H[c-1] = key;
}
int main(void)
{
    int n,H[20],count = 0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&H[i]);
    }
    pq_insert(H,n,&count);
    printf("Elements after heapify:\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d\t",H[i]);
    }
    //using pq_delete function display largest element and in next line display rest of the queue
    count--;
    printf("\nLargest Element:%d\n",H[count]);
    pq_delete(H,n,&count);
    printf("Elements after deletion:\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d\t",H[i]);
    }
    count--;
    printf("\nLargest Element:%d\n",H[count]);
}