#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
    }
    int partition(int arr[],int l,int r) {
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
    if(arr[j]<pivot)
    {
    i++;
    swap(arr,i,j);
    }
    }
    swap(arr,i+1,r);
    return i+1; 
 }
void quicksort(int arr[],int l,int r) {
    if(l<r)
    {
    int pi = partition(arr,l,r);
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);
 } }
void printarray(int arr[], int n) {
    printf("Quick Sort ");
    for(int i=0;i<n;i++) {
    printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    time_t start,end;
    float df;
    int l,r;
    int c,i,n,x,result;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    { scanf("%d",&arr[i]);}
    l=0,r=n-1;
    start=clock();
    quicksort(arr,l,r);
    printarray(arr,n);
    end=clock();
    df=end-start;
    printf("\nThe time taken is %f",(df/CLOCKS_PER_SEC));
}