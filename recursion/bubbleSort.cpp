#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr,int s, int n){
    if(n==1)
        return;
    if(s < n){
        if(arr[s]>arr[s+1])
            swap(arr[s],arr[s+1]);
    
        bubbleSort(arr,s+1,n);
    }   
    else
    bubbleSort(arr,0,n-1);
}

void printArray(vector<int> arr, int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    bubbleSort(arr,0, n-1);
    printf("Sorted array : \n");
    printArray(arr, n);
return 0;
}