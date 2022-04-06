#include<stdio.h>
#include<stdlib.h>

void maxSum(int *arr,int n)
{
    int start=0,end=0,sum,max_sum=-1;
    for(int i=0;i<n;i++)
    {   sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum>0 && sum>max_sum)
            {
                max_sum=sum;
                start=i;
                end=j;
            }
        }
    }
    if(max_sum<0)
    {
        printf("There Are all Negative Number in the array\n");
        printf("Sum = 0\n");
    }
    else{
        printf("Largest Sum = %d\n",max_sum);
        printf("Sum is present between index %d and %d\n",start,end);
    }
}
int main()
{
    int *arr,n;
    printf("Enter Size of array:- ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter Array Elements:\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    maxSum(arr,n);
    return 0;
}