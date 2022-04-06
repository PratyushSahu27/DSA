#include<iostream>
using namespace std;

void stringReverse(string s){

    if(s.length() == 0){
        return;
    }

    string ans = s.substr(1);
    stringReverse(ans);
    cout<<s[0];

}

int main(){
    string s;
    cin >> s;
    stringReverse(s);
    
}