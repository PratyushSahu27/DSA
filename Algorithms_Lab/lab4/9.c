#include<stdio.h>
#include<math.h>
#include<time.h>
void mergesort(int low,int mid,int high,int a[]){
    int i=low;
    int j=mid+1;
    int k=0;
    int n[100000];
    while(i<=mid && j<=high){
    if(a[i]<=a[j]) n[k++]=a[i++];
    else n[k++]=a[j++];
    }
    while(i<=mid) n[k++]=a[i++];
    while(j<=high) n[k++]=a[j++];
    j=0;
    for( i=low;i<=high;i++) a[i]=n[j++];
}
void merge(int low,int high,int a[]){
    if(low<high){
    int mid=low+(high-low)/2;
    merge(low,mid,a);
    merge(mid+1,high,a);
    mergesort(low,mid,high,a);
 } }
int display(int a[],int n){
    printf("\n the array is:\n");
    for(int i=0;i<n;i++) printf("%d\t",a[i]);
}
int main(){
    printf("Enter the size of the array : ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    if(n==1){
    printf("the number is:%d",a[0]);
    }
    else if(n==2){
    if(a[0]>a[1]){
    int temp=a[0];
    a[0]=a[1];
    a[1]=temp;
    }
    display(a,n);
    }
    else{
    printf("\nmerging upper half\n");
    merge(0,n*0.67,a);
    printf("\n merging lower half\n");
    merge(n*0.67,n-1,a);
    printf("\nmerging upper half again\n");
    merge(0,n*0.67,a);
    display(a,n);
 } 
 }