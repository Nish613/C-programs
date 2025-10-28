/*Write a program to create a BST and perform inorder, preorder, and postorder 
traversals. 
2. Write a function to search an element in a BST. 
3. Write a function to delete a node from a BST. 
4. Write a function to find the minimum and maximum elements in a BST. */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createBST(struct Node* root,int data)
{
    if(root==NULL)
    createNode(data);

    if(data<root->data)
    root->left = createBST(root->left,data);

    else if(data>root->data)
    root->right = createBST(root->right,data);

    return root;
}

void inorder(struct Node* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void preorder(struct Node* root)
{
    if(root==NULL)
    return;

    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

struct Node* search(struct Node* root,int data)
{
    if(root==NULL||root==data)
    return root;

    if(data<root->data)
    search(root->left,data);
    else
    search(root->right,data);
}

struct Node* findMin(struct Node* root)
{
    while(root!=NULL && root->left!=NULL)
    root = root->left;

    return root;
}

struct Node* findMax(struct Node* root)
{
    while(root!=NULL && root->right!=NULL)
    root = root->right;

    return root;
}

struct Node* delete(struct Node* root,int data)
{
    
}



