#include <stdio.h>
#include <stdlib.h>

struct node{
    int row;
    int column;
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode() {
    return ((struct node*)malloc(sizeof(struct node)));
}

NODE insertbeg(NODE first, int rows, int columns, int values) {
    NODE newnode=getnode();
    newnode->row=rows;
    newnode->column=columns;
    newnode->value=values;
    newnode->next=first;
    return newnode;
}

NODE insertend(NODE first, int rows, int columns, int values) {
    NODE newnode=getnode();
    newnode->row=rows;
    newnode->column=columns;
    newnode->value=values;
    if(first==NULL) {
        return newnode;
    }
    else {
        NODE curr=first;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=newnode;
        return first;
    }
}

void display(NODE fisrt) {
    if(fisrt==NULL) {
        printf("Sparse matrix is empty\n");
    }
    else {
        NODE curr=fisrt;
        printf("row    column   value\n");
        while(curr!=NULL) {
            printf("%d       %d       %d\n",curr->row,curr->column,curr->value);
            curr=curr->next;
        }
    }
}

int main() {
    int i,j;
    NODE first=NULL;
    int sparse[25][25];
    int m,n;
    printf("Enter the rows and columns respeactively : ");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j]!=0) {
                first=insertend(first,i,j,sparse[i][j]);
            }
        }
    }
    printf("\nTHE SPARSE MATRIX IS : \n");
    display(first);
}