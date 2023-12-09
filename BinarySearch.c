#include<stdio.h>
#include<conio.h>
void main()
{
     
    int a[10],i,n,item,flag=0,low,high,mid;
    
    printf("\n  Enter the size of an array: ");
    scanf("%d",&n);
     
    printf("\n  Enter the elements in ascending order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
     
    printf("\n  Enter the number to be search: ");
    scanf("%d",&item);
     
    low=0,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(item==a[mid])
        {
            flag=1;
            break;
        }
        else if(item<a[mid])
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    if(flag==0)
    printf("\n  The number is not found");
    else
    printf("\n  The number is found and its position is: %d",mid+1);
    getch();
}