#include <iostream>
#include <stdlib.h>
using namespace std;

void arraycr(int n,int *ptr) {
    // int n,*ptr;
    // printf("Enter the size of the array : ");
    // scanf("%d",&n);
    // ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array : ");
    for(int i=0;i<n;i++) {
        scanf("%d",&ptr[i]);
    }
}

void display(int n,int *ptr) {
    printf("The Elements of the array are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",ptr[i]);
    }
}

void insert(int n,int *ptr) {
    int pos,ele;
    printf("Enter the position at which you want to insert the element : ");
    scanf("%d",&pos);
    printf("Enter the element : ");
    scanf("%d",&ele);
    for(int i=n-1;i>pos-2;i--) {
        ptr[i]=ptr[i-1];
    }
    ptr[pos-1]=ele;
}

void deletion(int n,int *ptr) {
    int pos;
    printf("Enter the element to be deleted at position pos : ");
    scanf("%d",&pos);  
    for (int i = pos-1; i < n; i++)
    {
        ptr[i]=ptr[i+1];
    }
}

int main() {
    int n,*ptr;
    for(;;) {
        printf("Menue\n");
        printf("1.Creating an array\n");
        printf("2.Displaying elements of an array\n");
        printf("3.Inserting an element in the array at position pos\n");
        printf("4.Deleting an element in the array at position pos\n");
        printf("5.Exit\n");
        int choice;
        printf("Enter your choice : ");
        cin>>choice;
        switch (choice)
        {
        case 1:
            printf("Enter the size of the array required : ");
            scanf("%d",&n);
            ptr=(int*)malloc(n*sizeof(int));
            arraycr(n,ptr);
            break;
        
        case 2:
            display(n,ptr);
            break;

        case 3:
            n++;
            ptr=(int*)realloc(ptr,n*sizeof(int));
            ptr[n-1]=0;
            insert(n,ptr);
            break;

        case 4:
            deletion(n,ptr);
            n--;
            ptr=(int*)realloc(ptr,n*sizeof(int));
            break;
            
        case 5:
            free(ptr);
            exit(0);
            break;
        
        default:
            printf("Invalid Choice!!");
            break;
        }
    }
    return 0;
}