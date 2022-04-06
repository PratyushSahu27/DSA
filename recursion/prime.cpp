#include<bits/stdc++.h>
using namespace std;

bool prime(int x, int a = 2){
    if(x==2)
        return true;
    if(x%a==0)
        return false;
    if(a*a > x)
        return true;
    return prime(x,a+1);
    
}

int main()
{
    int x = 24;
    cout << prime(x)<< endl;
return 0;
}