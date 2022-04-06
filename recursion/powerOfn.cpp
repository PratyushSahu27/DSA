#include<bits/stdc++.h>
using namespace std;

int power(int x, int p){

    if(p == 0){
        return 1;
    }

    int ans = x * (power(x,p-1));

    return ans;
}

int main(){
    int ans = power(5,3);
    cout << ans << endl;
}