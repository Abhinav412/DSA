#include<stdio.h>

void const_top_down(int H[], int ele, int *count)
{
    int c= *count;
    H[c] = ele;
    int p=(c-1)/2;
    while(c>0 && ele>=H[p])
    {
        H[c] = H[p];
        c = p;
        p = (c-1)/2;
    }
    H[c] = ele;
    *count = *count+1;
}

int main(void)
{
    int ele,H[100],count=0,n=3;
    for(int i=0;i<n;i++)
    {
        printf("Enter the element:");
        scanf("%d",&ele);
        const_top_down(H,ele,&count);
    }
    printf("\nThe heap elements are:");
    for(int j=0;j<count;j++)
    {
        printf("%d ",H[j]);
    }
}