#include<stdio.h>
/*int main(void)
{
    int *p,x=10,**q;
    int a[]={10,20,30,40,50};
    p=&x;
    q=&p;
    printf("\nThe address of x = %u",&a);
    printf("\nThe address of p = %u",&p);
    printf("\nThe address of q = %u",&q);
    printf("\nThe address of p = %u",**q);

    for(int i = 0; i < 5; i++)
    printf("\n%d",*(a+i));
}*/
typedef struct Employee
{
    int emp_id;
    float salary;

}Emp;

int main(void)
{
    Emp employee1 = {123,1250000};
    printf("Employee id is %d and salary is %f",employee1.emp_id,employee1.salary);
}