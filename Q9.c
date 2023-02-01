#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE create(NODE root);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void search(NODE root);

void main()
{
    int ch, n, i;
    NODE root = NULL;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        root = create(root);
    for (;;)
    {
        printf("\n1-inorder\n2-postorder\n3-preorder\n4.search\n");
        printf("5-exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Traverse of inorder\n");
            inorder(root);
            printf("\n");
            break;
        case 2:
            printf("Traverse of postorder\n");
            postorder(root);
            printf("\n");
            break;
        case 3:
            printf("Traverse of preorder\n");
            preorder(root);
            printf("\n");
            break;

        case 4:
            search(root);
            break;
        default:
            exit(0);
        }
    }
}
NODE create(NODE root)
{
    NODE temp, prev, temp1;
    int ele;
    temp1 = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d", &ele);
    temp1->num = ele;
    temp1->left = temp1->right = NULL;
    if (root == NULL)
        return (temp1);
    temp = root;
    prev = root;
    while (temp != NULL)
    {
        prev = temp;
        if (ele < temp->num)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (ele < prev->num)
        prev->left = temp1;
    else
        prev->right = temp1;
    return (root);
}
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->num);
        inorder(root->right);
    }
}
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\t", root->num);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->num);
    }
}
void search(NODE root)
{
    int num;
    NODE temp = root;
    if (root == NULL)
    {
        printf("LIST is empty!!\n");
        return;
    }
    printf("Enter the number : ");
    scanf("%d", &num);
    while (temp != NULL)
    {
        if (temp->num == num)
        {
            printf("Serach is sucessfull\n");
            return;
        }
        if (num < temp->num)
            temp = temp->left;
        else if (num > temp->num)
            temp = temp->right;
    }
    printf("Search is unsucessfull\n");
}
