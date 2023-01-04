#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void push(int queue[MAX], int *front, int *rear) {
    int elem;
    if(*front==(*rear+1)%MAX) {
        printf("Queue overflow!!\n");
        return;
    }
    printf("Enter the element : ");
    scanf("%d",&elem);
    *rear=(*rear+1)%MAX;
    queue[*rear]=elem;
    if(*front==-1) {
        *front=*front+1;
    }
}

void pop(int queue[MAX], int *front, int *rear) {
    if(*front==-1) {
        printf("Queue is overflow!!\n");
        return;
    }
    printf("The deleted element is = %d\n",queue[*front]);
    *front=(*front+1)%MAX;
    if(*front==*rear) {
        *front=-1;
        *rear=-1;
    }
}

void display(int queue[MAX], int *front, int *rear) {
    int i;
    if(*front==-1) {
        printf("Queue is empty!!\n");
        return;
    }
    printf("The Queue elements are : \n");
    for (i = *front; i <= *rear; i++)
    {
        printf("%d\n",queue[i]);
    }
    
    if(*rear<*front) {
        for(i=0;i<=*rear;i++) {
            printf("%d\n",queue[i]);
        }
        for(i=*front;i<=MAX-1;i++) {
            printf("%d\n",queue[i]);
        }
    }
}

int main() {
    int choice, queue[MAX], front=-1, rear=-1;
    for(;;) {
        printf("Menue\n");
        printf("1.Insert an element to the queue\n");
        printf("2.Delete an element in the queue\n");
        printf("3.Display the elements of queue\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(queue, &front, &rear);
            break;

        case 2:
            pop(queue, &front, &rear);
            break;

        case 3:
            display(queue, &front, &rear);
            break;
       
        default:
            exit(0);
            break;
        }
    }
    return 0;
}