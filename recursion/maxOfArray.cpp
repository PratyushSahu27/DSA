#include<bits/stdc++.h>
using namespace std;

int max(int arr[], int n, int idx){
    
    if(idx == n){
        return 0;
    }

    if(arr[idx] >= max(arr, n,idx + 1)){
        return arr[idx];
    }
    else 
    {
        return max(arr,n, idx +1);
    }
}

int main(){
    int arr[5] = {4,6,2,8,3};

   int ans = max(arr,5,0);
   cout << ans << endl;

}