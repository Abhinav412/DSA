#include<stdio.h>
#include<stdlib.h>

int main(void)
{
   /*int *p = (int*)malloc(sizeof(int));
   *p = 20;
   printf("%d",p);*/

   int *p;
   p=(int*)malloc(sizeof(int)*5);
   *p  =20;
   *(p+1) = 21;
   *(p+2)=22;
   *(p+3)=23;
   *(p+4)=24;
   for(int i=0;i<5;i++)
   {
    printf("%d",*p);
    p++;
   }
   int *q;
   q=(int*)realloc(p,2*sizeof(int)*5);
   *(q+5) = 30;
   *(q+6) = 40;
   *(q+7) = 50;
   *(q+8) = 55;
   *(q+9) = 60;
   for(int j=0; j<10;j++)
   {
      printf("%d\n",*q);
      q++;
   }
}