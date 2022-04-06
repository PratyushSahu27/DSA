#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int low,int mid,int high) {
 int n1 = mid-low+1,n2 = high-mid;
 int left[n1],right[n2];
 for(int i=0;i<n1;i++)
 {
 left[i]=arr[low+i];
 }
 for(int i=0;i<n2;i++)
 {
 right[i]=arr[mid+i+1];
 }
 int i=0,j=0,k=low;
 while(i<n1 && j<n2)
 {
 if(left[i]<=right[j])
 {
 arr[k++]=left[i++];
 }
 else
 {
 arr[k++]=right[j++];
 }
 }
 while(i<n1)
 {
 arr[k++]=left[i++];
 }
 while(j<n2)
 {
 arr[k++]=right[j++];
 } }
void mergeSort(int *arr,int low,int high) {
 if(low<high)
 {
 int mid = low + (high-low)/2;
 mergeSort(arr,low,mid);
 mergeSort(arr,mid+1,high);
 merge(arr,low,mid,high);
 } }
int binSearch(int *arr,int low,int high,int x) {
 while(low<=high){
 int mid = (low+high)/2;
 if(arr[mid]==x)
 {
 return 1;
 }
 else if(arr[mid]<x)
 {
 low=mid+1;
 }
 else{
 high = mid-1;
 }
 }
 return 0; }
void intersection(int *boys,int *girls,int b,int g) {
 mergeSort(girls,0,g-1);
 for(int i=0;i<b;i++)
 {
 if(binSearch(girls,0,g-1,boys[i]))
 {
 printf("%d ",boys[i]);
 }
 
 }
 printf("\n");
}
int main()
{
 int b,g;
 printf("Enter the number of boys : ");
 scanf("%d",&b);
 printf("Enter the number of girls : ");
 scanf("%d",&g);
 int arr_boys[b],arr_girls[g];
 for(int i=0;i<b;i++)
 {
 printf("Age of boy %d : ",i+1);
 scanf("%d",&arr_boys[i]);
 }
 for(int i=0;i<g;i++)
 {
 printf("Age for girl %d :",i+1);
 scanf("%d",&arr_girls[i]);
 }
 printf("Common Age are : \n");
 intersection(arr_boys,arr_girls,b,g);
 return 0; }