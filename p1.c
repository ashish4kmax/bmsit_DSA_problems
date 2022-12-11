#include <stdio.h>
#include <stdlib.h>

void arr_creation(int a[10], int *n)
{
    int i;
    printf("Enter the size of the array : ");
    scanf("%d", n);
    printf("Enter the elements of the array : \n");
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[10], int *n)
{
    int i;
    printf("The elements of the array are : \n");
    for (i = 0; i < *n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void push(int a[10], int *n)
{
    int i, ele, pos;
    printf("Enter the position and value of the element repectively : ");
    scanf("%d%d", &pos, &ele);
    for (i = *n; i >= pos; i--)
    {
        a[i]=a[i-1];
    }
    a[pos - 1] = ele;
}

void pop(int arr[10], int *n) {
    int i, pos;
    printf("Enter the position of which array element to be deleted : ");
    scanf("%d",&pos);
    for(i=pos-1;i<*n-1;i++) {
        arr[i]=arr[i+1];
    }
}

int main()
{
    int choice, a[10], n;
    for (;;)
    {
        printf("Menue\n");
        printf("1.Create an array of n elements\n");
        printf("2.Diplay the elements of the array\n");
        printf("3.Insert an element in the array at given position\n");
        printf("4.Delete an element at given position in the array\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            arr_creation(a, &n);
            break;

        case 2:
            display(a, &n);
            break;

        case 3:
            n++;
            push(a,&n);
            break;
        case 4:
            pop(a, &n);
            n--;
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}