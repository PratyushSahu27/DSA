#include<stdio.h>
#include <stdbool.h>

bool check1(int* a, int n);
bool check2(int* a, int n);
int candidate(int *arr,int n);

int main(){
    int a[10];
    printf("Enter 10 elements - \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    bool chk1 = check1(a,10);
    if(chk1 == true)
        printf("algo-1 = No element in A repeats more than n/2 times\n");
    else
        printf("algo-1 = Some element in A repeats more than n/2 times\n");
    bool chk2 = check2(a,10);
    if(chk2 == true)
        printf("algo-2 = No element in A repeats more than n/2 times\n");
    else
        printf("algo-2 = Some element in A repeats more than n/2 times\n");
    
}
bool check1(int* a, int n){
    int count, maxcount = 0;
    for (int i = 0; i < n ; i++)
    {   
        count = 0;
        int x = a[i];
        for (int j = 0; j < n; j++)
        {
            if(a[j] == x) 
                count++;
        }
        maxcount  = (maxcount<count ? count : maxcount);
        if(maxcount > n/2){
            return false;
        }
    }
     return true;
}

int candidate(int *arr,int n)
{
    int max_index=0,count=1;
    for(int i=1;i<n;i++)
    {
        if(arr[max_index]==arr[i])
        {
            count++;
        }
        else{
            count--;
        }
        if(count==0)
        {
            max_index=i;
            count=1;
        }
        
    }
    return arr[max_index];
}
bool check2(int* a, int n){
    int cand = candidate(arr,n);
    int count =0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==cand)
        {
            count++;
        }
    }
    if(count>(n/2))
    {
        return cand;
    }
    return -1;
}