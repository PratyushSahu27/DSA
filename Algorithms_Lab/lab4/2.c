#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void merge1(int arr[], int l, int mid, int r){
    int n1 = mid- l +1;
    int n2 = r - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[l+i];
    }
        for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[mid+1+i];
    }
    
    int i =0, j=0,k=l;
    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j] ){
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i<n1)
    {
        arr[k] = arr1[i];
            k++;
            i++;
    }
    while (j<n2)
    {
        arr[k] = arr2[j];
            k++;
            j++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge1(arr, l, mid, r);
    }
}

int main(){
    int n,start,end,totalTime;
    start = clock();
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements to sort\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    end = clock();
    totalTime = end - start;
    printf("\nTime Taken: %f",(double)(totalTime/CLOCKS_PER_SEC));
    
}
