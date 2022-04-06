#include<bits/stdc++.h>
using namespace std;

void toh(int n, int t1, int t2, int t3){

    if(n == 0) {
        return;
    }

    toh(n-1, t1, t3, t2); //moving n-1 discs from t1 to t3 using t2

    cout << t1 << " -> " << t2 << endl; // moving last disc from t1 to t2

    toh(n-1, t3, t2, t1); // moving n-1 discs from t3 to t2
}

int main(){
    toh(3,7,8,9);
    return 0;
}