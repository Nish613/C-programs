/*Conpare the number of comparisons between binary search and linear search for the same array*/
#include <stdio.h>
int main()
{
    int n = 5;
    int arr[5] = {1,2,3,4,5};
    int target = 1;
    int count1=0,count2=0;
    void linear()
    {
        for(int i=0;i<n;i++)
        {
            count1++;
            if(arr[i]==target)
            {
                printf("No of comparisions : %d\n",count1);
                return;
            }
            
        }
    }
    void binary()
    {
        int l=0,u=n-1;
        
        while(l<=u)
        {
            int mid = (l+u)/2;
            count2++;
            if(arr[mid]==target)
            {
                printf("No of comparisions : %d\n",count2);
                return;
            }
            
            else if(arr[mid]<target)
            l=mid+1;
            else if(arr[mid]>target)
            u=mid-1;
        }
    }
    linear();
    binary();
    return 0;
}

