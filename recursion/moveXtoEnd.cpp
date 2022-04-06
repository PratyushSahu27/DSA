#include<bits/stdc++.h>
using namespace std;

string moveXtoEnd(string s){
    if(s.length() == 0){
        return "";
    }

    char c = s[0];
    string ans = moveXtoEnd(s.substr(1));
    if( c == 'x'){
        return ans + c;
    }
    return (c + ans);
}

int main(){
  string ans = moveXtoEnd("abxhjxxnmhxl");
  cout << ans <<endl;
}