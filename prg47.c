/*Write a program to create a BST and perform inorder, preorder, and postorder 
traversals.*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

struct Node* createBST(struct Node* root, int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }

    if(data<root->data)
    root->lchild = createBST(root->lchild,data);
    else if(data>root->data)
    root->rchild = createBST(root->rchild,data);

    return root;
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

void preorder(struct Node* root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(struct Node* root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}

int main()
{
    struct Node* root = NULL;
    printf("Enter no of ele : ");
    int n,ele;
    scanf("%d",&n);

    printf("Enter ele : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ele);
        root = createBST(root,ele);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}