#include<bits/stdc++.h>
using namespace std;

bool myCompare(pair <int,int> p1, pair <int,int> p2){
    return p1.first<p2.first;
}

int main(){

    int arr[8] = {65,32,3,7,8,4,2,11};
    vector<pair<int,int>> v;
    for (int i = 0; i < 8; i++)
    {
        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(), myCompare);

    int ans[v.size()];

    for (int i = 0; i < v.size(); i++)
    {
        ans[v[i].second] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
    
    
    
}