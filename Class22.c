#include<stdio.h>
#include<stdlib.h>

void bottom_up_heap(int H[], int n)
{
    int k,j,key;
    for(int i=n/2;i>=1;i--)
    {
        k=i;
        key = H[k];
        int heap = 0;
        while(heap != 1 && 2*k <=n)
        {
            j = 2*k;
            if(j<n)
            {
                if(H[j+1] >= H[j])
                {
                    j=j+1;
                }
            }
            if(key > H[j])
            {
                heap = 1;;
            }
            else
            {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = key;
    }
}
int main(void)
{
    int n,H[20];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&H[i]);
    }
    bottom_up_heap(H,n);
    printf("Elements after heapify:\n");
    for(int i=1; i<=n; i++)
    {
        printf("%d\t",H[i]);
    }
}