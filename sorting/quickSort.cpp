#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

int partition(int arr[], int l, int r){
    
    int pivot = arr[r];
    int i = l-1;
    int j = l;
    for (int j = l; j < r; j++)
    {
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,r,i+1);
    return i+1;
    
}

void quickSort(int arr[], int l, int r){
    if(l<r){

        int piv = partition(arr, l, r);
        quickSort(arr, l,piv-1);
        quickSort(arr,piv+1, r);
    }
}

int main(){
    int arr[10] = {4,2,8,3,9,0,1,5,6,7};
    quickSort(arr,0,9);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
    
}