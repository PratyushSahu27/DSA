#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    vector<int> vz;
    int k = 4;
    for (int j = 0; j < k; j++)
        {
            vz.push_back(v[j]);
        }
    make_heap(vz.begin(),vz.end());
    cout << vz.front() << " ";
   
    for (int i = k; i < v.size(); i++)
    {   
        vz.pop_back();
        vz.push_back(v[i]);
        make_heap(vz.begin(),vz.end());
        cout << vz.front() << " ";
    }
    
return 0;
}
