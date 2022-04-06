#include<bits/stdc++.h>
using namespace std;

void displayArr(int* arr,int n, int idx){

    if(idx == n){
        return;
    }

    cout<< arr[idx] <<endl;

    displayArr(arr,n, idx+1);
}

int main(){
    int* a = new int(4);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;

   
    displayArr(a,4,0);
}