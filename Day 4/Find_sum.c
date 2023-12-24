#include <stdio.h>

int check_sum(int a[],int n,int s)
{
    int temp,max=0,flag=0;

    for(int i=0;i<n;i++) 
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    for(int i=0;i<n;i++) 
    {
        temp=s-a[i];

        if(temp>=0&&temp<=max)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]==temp) 
                {
                     flag=1;
                }
                
            }
        }
    }
    
    if(flag==1)
    {
        printf("yes");
    }
    else
    {
        printf("No");
    }
}
int main() 
{
    int n,sum;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&array[i]);
    }
    printf("Enter the sum: ");
    scanf("%d",&sum);
    check_sum(array,n,sum);
    return 0;
}
