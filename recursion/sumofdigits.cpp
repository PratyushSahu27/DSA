#include<bits/stdc++.h>
using namespace std;

int digits(int x){
    if(x==0)
        return 0;
    return x%10 + digits(x/10);
}

int main()
{
    int x = 129756;
    cout << digits(x) << endl;
return 0;
}