/*Make a structure for employee with name, ID, emailID,
 read and display and then count the numbers of emails which are gmail ids and display count*/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 struct employee 
 {
    char name[50];
    int id;
    char email[50];
 };

void display(struct employee e[],int n)
{
   for(int i=0;i<n;i++)
   {
      printf("Name : %s\tID : %d\tEmail : %s\n",e[i].name,e[i].id,e[i].email);
   }
}

void count(struct employee e[],int n)
{
   int count=0;
   for(int i=0;i<n;i++)
   {
      if(strstr(e[i].email,"gmail"))
      count++;
   }
   printf("There are %d gmail ids\n",count);
}

 int main()
 {
    struct employee e[3];
    char name[50];
    int id;
    char email[50];
    for(int i=0;i<3;i++)
    {
        printf("Enter name : ");
        scanf("%s",e[i].name);
        printf("Enter id : ");
        scanf("%d",&e[i].id);
        printf("Enter email : ");
        scanf("%s",e[i].email);

        
    }
    count(e,3);
    display(e,3);
    return 0;
 }