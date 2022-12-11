#include <stdio.h>
#include <stdlib.h>
#define MAX 3

void push(int stack[MAX], int *top) {
    int elem;
    if(*top==MAX-1) {
        printf("Stack overflow!!\n");
        return;
    }   
    printf("Enter the element : ");
    scanf("%d",&elem);
    *top=*top+1;
    stack[*top]=elem;
}

void pop(int stack[MAX], int *top) {
    if(*top==-1) {
        printf("Stack underflow\n");
        return;
    }
    *top-=1;
}

void display(int stack[MAX], int *top) {
    int i;
    if(*top==-1) {
        printf("Stack is empty\n");
        return;
    }
    printf("The stack elements are : \n");
    for(i=0;i<=*top;i++) {
        printf("%d\n",stack[i]);
    }
}

int main() {
    int choice, stack[MAX], top=-1;
    for(;;) {
        printf("Menue\n");
        printf("1.Insert an element into stack\n");
        printf("2.Delete an element in stack\n");
        printf("3.Display the element in stack\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;
        
        case 2:
            pop(stack, &top);
            break;
        
        case 3:
            display(stack, &top);
            break;
        
        default:
            exit(0);
            break;
        }
    }
    return 0;
}