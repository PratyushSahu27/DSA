#include<bits/stdc++.h>
using namespace std;

char firstUppercase(string s){
    if(s.size() == 0)
        return 0;
    if(isupper(s[0]))
        return s[0];
    else{
        return firstUppercase(s.substr(1));
    }
}

int main() {
	string str = "geekForGeeks" ;
	char i = firstUppercase(str);
	if(i == 0){
	    cout << "No Uppercase Letter!";
	}
	else
	cout << i << endl;
	return 0;
}