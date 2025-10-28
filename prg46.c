//Binary tree using LL

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* createNode()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }

    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

struct Node* createBinaryTree(int item)
{
    int data;
    if(item!=-1)
    {
        struct Node* temp = createNode();
        temp->data = item;

        printf("Enter left child of %d (-1 for no child): ", temp->data);
        scanf("%d",&data);
        temp->lchild = createBinaryTree(data);

        printf("Enter right child of %d (-1 for no child): ", temp->data);
        scanf("%d",&data);
        temp->rchild = createBinaryTree(data);

        return temp;
    }

    return NULL;
}

void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
    
}

int main()
{
    printf("Enter root : ");
    int root1;
    scanf("%d",&root1);

    struct Node* root = createBinaryTree(root1);

    inorder(root);

    return 0;
}