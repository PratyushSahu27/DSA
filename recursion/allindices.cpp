#include<bits/stdc++.h>
using namespace std;

int* allindices(int arr[], int n, int key, int idx, int found){

    if(idx == n){
        
        return new int(found);
    }

    if(arr[idx] == key){
       int *ans = allindices(arr,n,key,idx+1,found+1);
       ans[found] = idx;
       return ans;
    }
    else{
       int *ans = allindices(arr,n,key,idx+1,found);
       return ans;
    }
}

int main(){
    int arr[10] = { 1,4,3,5,8,3,2,5,7,3};

   int* ans = allindices(arr, 10, 3, 0, 0);

   for (int i = 0; i < 3; i++)
   {
       cout << ans[i] << endl;
   }
   
   
}