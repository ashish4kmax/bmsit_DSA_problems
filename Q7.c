#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char usn[12];
    char name[25];
    char branch[5];
    int sem;
    float phone;
    struct node *next;
};
typedef struct node *NODE;

NODE getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}

NODE insertbeg(NODE head)
{
    char usn[12], name[25], branch[5];
    int sem;
    float phone;
    printf("Enter the students USN : ");
    scanf("%s", usn);
    getchar();
    printf("Enter the name of the student : ");
    scanf("%s", name);
    getchar();
    printf("Enter the branch of student : ");
    scanf("%s", branch);
    printf("Enter the students semester in : ");
    scanf("%d", &sem);
    printf("Enter the phone number of student : ");
    scanf("%f", &phone);
    NODE newnode = getnode();
    strcpy(newnode->usn, usn);
    strcpy(newnode->name, name);
    strcpy(newnode->branch, branch);
    newnode->sem = sem;
    newnode->phone = phone;
    newnode->next = head;
}

NODE deletefront(NODE head)
{
    if (head == NULL)
    {
        printf("Liked List is empty!!\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        return head;
    }
    else
    {
        NODE temp = head->next;
        printf("Deleted data is of Name = %s\n\n", head->name);
        free(head);
        return temp;
    }
}

NODE deleteend(NODE head)
{
    if (head == NULL)
    {
        printf("Linked List is empty!!\n");
        return head;
    }
    else if(head->next==NULL) {
        printf("Deleted data is of Name = %s\n\n", head->name);
        head = NULL;
        return head;
    }
    else
    {
        NODE curr = head->next, prev = head;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        printf("Deleted data is of Name = %s\n\n", curr->name);
        free(curr);
        prev->next = NULL;
        return head;
    }
}

void display(NODE head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty!!\n");
    }
    else
    {
        NODE curr = head;
        printf("USN\t\tName\t\tBranch\tSem\tPhone\n");
        while (curr != NULL)
        {
            count++;
            printf("%-20s%-15s%-5s%5d%15.0f\n", curr->usn, curr->name, curr->branch, curr->sem, curr->phone);
            curr = curr->next;
        }
        printf("\nThe no. of nodes = %d\n", count);
    }
}

int main()
{
    NODE head = NULL;
    int choice;
    int n, i;
    printf("Enter the amount of student data you want to insert : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        head = insertbeg(head);
    }

    for (;;)
    {
        printf("\nMenue\n");
        printf("1.Insert the student datas\n");
        printf("2.Delete data from front\n");
        printf("3.Delete data from the end\n");
        printf("4.Display the students data\n");
        printf("5.Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = insertbeg(head);
            break;

        case 2:
            head = deletefront(head);
            break;

        case 3:
            head = deleteend(head);
            break;

        case 4:
            display(head);
            break;

        default:
            exit(0);
        }
    }
    return 0;
}
