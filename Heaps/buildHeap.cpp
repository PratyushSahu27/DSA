#include<bits/stdc++.h>
using namespace std;
void heapify(int* arr, int n, int i){
    int largest = i;
    int left = (i*2)+1;
    int right = (i*2)+2;

    if(left<n&&arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void createHeap(int*arr, int n){
    int start = (n/2)-1;
    for(int i = start; i >= 0; i--)
        heapify(arr,n,i);
}
int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    createHeap(arr,n);
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
return 0;
}