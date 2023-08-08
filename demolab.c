/*
Q1. Write a c program for matrix multiplication using functions.
Q2. Write a c program for selection sort using functions.
Q3. Write a structure with the fields name marks1 marks2 marks3. Read print and calculate the average of the marks using functions.
Q4. Write a c program for bubble sort.*/

/*
//Q1
#include <stdio.h>
#include<stdlib.h>
void input(int m, int n, int a[m][n])
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d, %d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void print(int m, int n, int a[m][n])
{
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }   
}

void multiply(int r1,int r2,int c1,int c2,int (*a)[c1],int b[][c2],int c[][c2])
{
	int i,j,k;
	for(i = 0;i<r1;i++)
	{
		for(j = 0;j<c2;j++)
		{
			int sum = 0;
			for(k = 0;k<c1;k++)
			{
		
				sum  = sum + (a[i][k]*b[k][j]);
			}
			c[i][j] = sum;	
		}
		printf("\n");
	}	
}

int main(void)
{
    int r1, c1, r2, c2;
    printf("Row and column for matrix #1 :\n");
    scanf("%d %d", &r1, &c1);
    printf("Row and column for matrix #2 :\n");
    scanf("%d %d", &r2, &c2);

    if (r2 != c1) 
    {
        printf("The matrices are incompatible.\n");
        exit(0);
    }
    int mat1[r1][c1], mat2[r2][c2], ans[r1][c2];
    printf("Enter elements of the first matrix.\n");
    input(r1, c1, mat1);
    printf("Enter elements of the second matrix.\n");
    input(r2, c2, mat2);
    multiply(r1, r2, c1, c2, mat1, mat2, ans);
    printf("The product is :\n");
    print(r1, c2, ans);
}
*/

/*
//Q2
#include<stdio.h>
 void SelectionSort(int arr[], int n)
 {
    int i,j,min;
    for(i = 0 ; i < n ; i ++)
    {
        min=i;
        for(j = i + 1 ; j < n; j++)
        {
            if(arr[j]<arr[min])
            min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
 }
void printArray(int arr[] , int size)
{
    int i;
    for(i = 0; i < size; i++)
    printf("%d ",arr[i]);
    printf("\n");
}

 int main(void)
 {
    int arr[20], size;
    printf("Enter the array size:\n");
    scanf("%d",&size);
    printf("Enter the array elements: ");
    for(int i = 0; i<size; i++)
    scanf("%d",&arr[i]);
    SelectionSort(arr,size);
    printf("Sorted array is:\n");
    printArray(arr,size);
 }
 */

/*
//Q3
#include<stdio.h>
struct student
{
    char name[20];
    int marks1;
    int marks2;
    int marks3;
};

float avgmarks(struct student student)
{
    return (float)(student.marks1+student.marks2+student.marks3)/3;
}

void readStudent(struct student *student)
{
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter marks for subject 1: ");
    scanf("%d", &student->marks1);
    printf("Enter marks for subject 2: ");
    scanf("%d", &student->marks2);
    printf("Enter marks for subject 3: ");
    scanf("%d", &student->marks3);
}

void printStudent(struct student student)
{
    printf("Student Name: %s\n", student.name);
    printf("Marks in Subject 1: %d\n", student.marks1);
    printf("Marks in Subject 2: %d\n", student.marks2);
    printf("Marks in Subject 3: %d\n", student.marks3);
    printf("Average Marks: %.2f\n", avgmarks(student));
}

int main(void)
{
    struct student std;
    readStudent(&std);
    printStudent(std);
}
*/

/*
//Q4
#include <stdio.h>
#include<stdbool.h>

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
*/