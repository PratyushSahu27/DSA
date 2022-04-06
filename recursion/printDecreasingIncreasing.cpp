#include<bits/stdc++.h>
using namespace std;

void printDecInc(int n){
    if(n==0){
        return;
    }

    cout << n ;
    printDecInc(n-1);
    cout << n;
}

int main(){
    printDecInc(5);
}