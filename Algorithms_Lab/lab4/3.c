#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
struct minmax{
    int min;
    int max;
};
struct minmax minmax_bruteforce(int arr[],int n){
    struct minmax m;
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max)
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    m.max = max;
    m.min = min;
    return m;
}

struct minmax minmax_DnC(int arr[],int low,int high){
    struct minmax m;
}

int main(){
    int n,start,end,totalTime;
    struct minmax ob;
    //bruteforce approach
    start = clock();
    printf("Enter size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d numbers\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    ob = minmax_bruteforce(arr,n);
    end = clock();
    totalTime =(double)((end-start)/ CLOCKS_PER_SEC);
    printf("Brute force -\n Min = %d,  Max = %d, CPU Time = %d\n",ob.min,ob.max,totalTime);
    //divide and conquer approach

    
    return 0;
}