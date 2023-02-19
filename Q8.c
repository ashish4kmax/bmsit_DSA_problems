#include <stdio.h>
#include <stdlib.h>

struct node
{
    char ssn[12], name[25], branch[5], desg[10], phone[11];
    int sal;
    struct node *next, *prev;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the ssn of the employee : ");
    scanf("%s", newnode->ssn);
    getchar();
    printf("Enter the name of the employee : ");
    //scanf("%s", newnode->name);
    gets(newnode->name);
    getchar();
    printf("Enter the branch of the employee : ");
    scanf("%s", newnode->branch);
    getchar();
    printf("Enter the desg of the employee : ");
    scanf("%s", newnode->desg);
    getchar();
    printf("Enter the salary of the employee : ");
    scanf("%d", &newnode->sal);
    printf("Enter the phone number of the employee : ");
    scanf("%s", newnode->phone);
    return newnode;
}

NODE insertbeg(NODE head)
{
    NODE temp = getnode();
    temp->prev = NULL;
    temp->next = head;
    return temp;
}

NODE insertend(NODE head)
{
    NODE temp = getnode();
    temp->prev = NULL;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    else if (head->next == NULL)
    {
        head->next = temp;
        temp->prev = head;
        return head;
    }
    else
    {
        NODE curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
        return head;
    }
}

NODE deletefront(NODE head)
{
    if (head == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
        return head;
    }
    else
    {
        NODE temp = head->next;
        printf("Deleted data is of name : %s\n", head->name);
        free(head);
        return temp;
    }
}

NODE deleteend(NODE head)
{
    NODE curr = head;
    if (head == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
        return head;
    }
    else if (head->next == NULL)
    {
        printf("Deleted data is of name : %s\n", curr->name);
        free(curr);
        return NULL;
    }
    else
    {
        NODE p = head;
        while (curr->next != NULL)
        {
            p = curr;
            curr = curr->next;
        }
        p->next = NULL;
        //curr->prev->next=NULL; //another way of assigning previous node's *next pointer to NULL, curr->prev is same as using p to store previous node
        printf("Deleted data is of name : %s\n", curr->name);
        free(curr);
        return head;
    }
}

void display(NODE head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Doubly Linked List is empty!!\n");
    }
    else
    {
        NODE curr = head;
        printf("ssn\t\tname\t\tBranch\tdesg\t\tsalary\tphone\n");
        while (curr != NULL)
        {
            printf("%-20s%-15s%-5s%-10s%5d\t%-10s\n", curr->ssn, curr->name, curr->branch, curr->desg, curr->sal, curr->phone);
            curr = curr->next;
            count++;
        }
        printf("\nTotal no. of nodes = %d\n", count);
    }
}

/*-------------------------------This is the code for back traversal in DE linked list its an extrapart!!-----------------------------------------------------------

void backward(NODE head)
{
    NODE newnode = head;
    if (head == NULL)
    {
        printf("Doubly linked list is empty!!\n");
    }
    else
    {
        int count = 0;
        NODE p=head;
        newnode->prev=NULL;
        while (newnode->next != NULL)
        {
            p=newnode;
            newnode = newnode->next;
            newnode->prev=p;
        }
        printf("ssn\t\tname\t\tBranch\tdesg\t\tsalary\tphone\n");
        // printf("%-20s%-15s%-5s%-10s%5d\t%-10s\n", newnode->ssn, p->next->name, p->next->branch, p->next->desg, p->next->sal, p->next->phone);
        while (newnode->prev != NULL)
        {
            printf("%-20s%-15s%-5s%-10s%5d\t%-10s\n", newnode->ssn, newnode->name, newnode->branch, newnode->desg, newnode->sal, newnode->phone);
            newnode = newnode->prev;
            count++;
        }
        printf("%-20s%-15s%-5s%-10s%5d\t%-10s\n", newnode->ssn, newnode->name, newnode->branch, newnode->desg, newnode->sal, newnode->phone);
        count++;
        printf("\nTotal no. of nodes = %d\n", count);
    }
}
*/

int main()
{
    NODE head = NULL;
    int choice, n;
    printf("Enter the no. of employees : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = insertend(head);
        printf("\n");
    }
    for (;;)
    {
        printf("Menu\n");
        printf("1.Display\n");
        printf("2.Insert at end\n");
        printf("3.Delete at end\n");
        printf("4.Insert at beginning\n");
        printf("5.Delete at beginning\n");
        //printf("6.Backward Traversal\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            display(head);
            break;

        case 2:
            head = insertend(head);
            break;

        case 3:
            head = deleteend(head);
            break;

        case 4:
            head = insertbeg(head);
            break;

        case 5:
            head = deletefront(head);
            break;

//         case 6:
//             backward(head);
//             break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}
