#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void push_back(int DEQ[], int *rear, int *front, int *count) {
    int elem;
    if(*count==MAX) {
        printf("Dequeue is full\n");
        return;
    }
    printf("Enter the element : ");
    scanf("%d",&elem);
    *rear=(*rear+1)%MAX;
    *count=*count+1;
    DEQ[*rear]=elem;
    if(*front==-1) {
        *front=*front+1;
    }
}

void pop_back(int DQ[MAX], int *front, int *rear, int *count) {
    if (*count == 0) {
        printf("DEqueue underflow\n");
        return;
    }
    if (*rear == -1)
    {
        *rear = MAX - 1;
        printf("Deleted element is = %d\n", DQ[*rear]);
    }
    else
    {
        printf("Deleted element is = %d\n", DQ[*rear]);
        *rear = *rear - 1;
    }
    *count = *count - 1;
}

void push_front(int DEQ[], int *rear, int *front, int *count) {
    int elem;
    if(*count==MAX) {
        printf("Dequeue is full\n");
    }
    else {
        printf("Enter the element : ");
        scanf("%d", &elem);
        if(*front==-1) {
            *front=MAX-1;
        }
        else {
            *front = *front - 1;
        }
        DEQ[*front] = elem;
        *count = *count + 1;
    }
}

void pop_front(int DEQ[], int *rear, int *front, int *count) {
    if(*count==0) {
        printf("Dequeue underflow\n");
        return;
    }
    printf("The deleted element is = %d\n",DEQ[*front]);
    *front=(*front+1)%MAX;
    *count=*count-1;
}

void display(int DEQ[], int *rear, int* front, int *count) {
    if(*count==0) {
        printf("Dequeue is empty\n");
        return;
    }
    int x=*front;
    int i;
    printf("The dequeue elements are :\n");
    for(i=1;i<=*count;i++) {
        printf("%d\n",DEQ[x]);
        x = (x+1)%MAX;
    }
}

int main() {
    int DEQ[MAX], front=-1, rear=-1, choice;
    int count=0;
    for(;;) {
        printf("Menue\n");
        printf("1.Insert an element at front of queue\n");
        printf("2.Delete an element at the front of queue\n");
        printf("3.Insert an element at the back of queue\n");
        printf("4.Delete an element at the back of queue\n");
        printf("5.Display the dequeue elements\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push_front(DEQ,&rear,&front,&count);
            break;

        case 2:
            pop_front(DEQ,&rear,&front,&count);
            break;

        case 3:
            push_back(DEQ,&rear,&front,&count);
            break;

        case 4:
            pop_back(DEQ,&rear,&front,&count);
            break;

        case 5:
            display(DEQ,&rear,&front,&count);
            break;

        case 6:
            exit(0);
            break;           

        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    return 0;
}
