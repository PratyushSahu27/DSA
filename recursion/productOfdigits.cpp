#include<bits/stdc++.h>
using namespace std;
int prodOfdigits(int x){
    if(x==0)
        return 1;
    return x%10 * prodOfdigits(x/10);
}

int main()
{
    int x = 129756;
    cout << prodOfdigits(x) << endl;
return 0;
}