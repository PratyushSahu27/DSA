//given an array and a key. find the last index of the key;

#include<bits/stdc++.h>
using namespace std;

int firstIdx(int arr[], int n, int key, int idx){

    if(idx == n){
        return -1;
    }

    int ans = firstIdx(arr, n ,key, idx + 1);

    if(ans != -1){
        return ans;
    }
    else if(arr[idx] == key){ 
    return idx ;
    }
    else
    return -1;
}

int main(){
    int arr[10] = { 1,4,2,5,8,3,2,5,7,3};

   int ans = firstIdx(arr, 10, 3, 0);

   cout << ans << endl;
}