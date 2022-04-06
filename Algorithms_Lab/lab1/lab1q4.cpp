#include<bits/stdc++.h>
using namespace std;


void swapall(int &a, int &b, int &c){
    a = a +b +c;
    b = a-(b+c);
    c = a-(b+c);
    a = a-(b+c);
}

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("Originally, a = %d, b = %d, c = %d\n",a,b,c);
    swapall(a,b,c);
    printf("After swapping, a = %d, b = %d, c = %d\n",a,b,c);
}