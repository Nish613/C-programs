/*structure of books- each book has title,
 author and price sort based on price recursively using insertion sort display after sorting*/

#include<stdio.h>

struct Book
{
    char title[50];
    char author[50];
    int price;
};

void selection(struct Book b[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(b[minIndex].price>b[j].price)
            minIndex = j;
        }
        if(minIndex!=i)
        {
            struct Book temp = b[minIndex];
            b[minIndex] = b[i];
            b[i] = temp;
        }
    }

}

void insertion(struct Book b[],int n)
{
    for(int i=1;i<n;i++)
    {
        struct Book curr = b[i];
        int prev = i-1;

        while(prev>=0 && b[prev].price>curr.price)
        {
            b[prev+1] = b[prev];
            prev--;
        }
        b[prev+1] = curr;
    }
}

void rec_insertion(struct Book b[],int n,int i)
{
    if(i==n)
    return;

    struct Book curr = b[i];
    int prev = i-1;
    while(prev>=0 && b[prev].price>curr.price)
    {
        b[prev+1] = b[prev];
        prev--;
    }
    b[prev+1] = curr;

    rec_insertion(b,n,i+1);
}

void rec_selection(struct Book b[],int n,int i)
{
    if(i==n-1)
    return;

    int minIndex = i;
    for(int j=i+1;j<n;j++)
    {
        if(b[minIndex].price>b[j].price)
        minIndex=j;
    }
    if(minIndex!=i)
    {
        struct Book temp = b[minIndex];
        b[minIndex] = b[i];
        b[i] = temp;
    }
    rec_selection(b,n,i+1);


}

void display(struct Book b[], int n)
{
    printf("After sorting : \n");
    for(int i=0;i<n;i++)
    {
        printf("Title : %s | Author : %s | Price : %d\n",b[i].title,b[i].author,b[i].price);
    }
}
int main()
{
    int n,ch;
    printf("Enter no ele : ");
    scanf("%d",&n);

    struct Book b[n];
    for(int i=0;i<n;i++)
    {
        printf("Book %d : \n",i+1);
        printf("Title : ");
        scanf(" %[^\n]",b[i].title);
        printf("Author : ");
        scanf(" %[^\n]",b[i].author);
        printf("Price : ");
        scanf("%d",&b[i].price);
    }

    //rec_selection(b,n,0);
    rec_insertion(b,n,1);
    display(b,n);


    return 0;
}