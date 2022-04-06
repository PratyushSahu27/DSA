#include <bits/stdc++.h>
using namespace std;
class minmax{
    public:
    int min = INT_MAX;
    int max = INT_MIN;
};

minmax minMax(vector<int> v, int i = 0 ){
    static minmax mx;
    if(i=v.size()){
        return mx;
    }
    if(v[i]<mx.min)
        mx.min = v[i];
    else if (v[i]>mx.max)
        mx.max = v[i];
     minMax(v,i+1);
}


int main() {
	vector<int> A = {1, 4, 45, 6, -50, 10, 2};
    minmax mx = minMax(A);
    cout << "Min = "<< mx.min<<" Max="<<mx.max<<endl;
    return 0;
}