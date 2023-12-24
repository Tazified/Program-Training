#include <stdio.h>

void first_last(int a[],int m,int b) 
{
    int first=-1,last=-1;
   
    for(int low=0,high=m-1;low<=high;) 
    {
        int mid=low+(high-low)/2;

        if(a[mid]==b) 
        {
            first=mid;
            high=mid-1; 
        } 
        else if(a[mid]<b) 
        {
            low=mid+1;
        }
        else 
        {
            high=mid-1;
        }
    }

    for(int low=0,high=m-1;low<=high;) 
    {
        int mid=low+(high-low)/2;
        if(a[mid]==b) 
        {
            last=mid;
            low=mid+1;
        }
        else if(a[mid]<b) 
        {
            low=mid+1;
        } 
        else 
        {
            high=mid-1;
        }
    }

    printf("First and last occurrence of %d : %d and %d",b,first,last);
}

int main() 
{
    int n,a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the element to find out the first and last occurrence: ");
    scanf("%d", &a);
    first_last(array,n,a);
    return 0;
}
