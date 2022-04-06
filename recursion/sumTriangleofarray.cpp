#include<bits/stdc++.h>
using namespace std;

void sumTriangle(vector<int> arr, int n){
    
    if(n < 1){
        return;
    }

    vector<int> res(n-1,0);

    for(int i = 0; i < arr.size()-1; i++){
        res[i] = arr[i] + arr[i+1];
    }
    sumTriangle(res, n-1);
    for(int z : arr)
    {
        cout << z << ' ';
    }
    cout<<endl;
    return;
}

int main()
{
    vector<int> arr = { 1, 2, 3,4,5};
    int n = arr.size();
    sumTriangle(arr, n);
return 0;
}