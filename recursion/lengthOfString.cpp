#include<bits/stdc++.h>
using namespace std;

int stringLength(char* str){
    if(*str == '\0'){
        return 0;
    }
    return 1 + stringLength(str+1);
    
}
int main()
{
    char str[] = "geeksForGeeks";
    cout << stringLength(str) << endl;
    return 0;
}