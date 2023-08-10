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

void display(Emp *p,int n)
{
    for(int i = 0; i<n ;i++)
    {
        printf("\n Employee id is %d with salary %f ",p->emp_id,p->salary);
        p++;
    }
}

int main(void)
{
    Emp emp[3];

    emp[0].emp_id = 123;
    emp[0].salary = 12000;

    emp[1].emp_id = 456;
    emp[1].salary = 11000;

    emp[2].emp_id = 789;
    emp[2].salary = 13000;

    Emp *p = emp;

    /*for(int i =0; i<3; i++)
    {
        //printf("\n Employee id is %d with salary %f ",emp[i].emp_id,emp[i].salary);
        printf("\n Employee id is %d with salary %f ",(p+i)->emp_id,(p+i)->salary);
    }*/
    display(p,3);
}