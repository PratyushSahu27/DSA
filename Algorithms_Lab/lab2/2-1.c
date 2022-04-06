#include <stdio.h>

void gcd(int x, int y);

int main() {
    int a, b;
    printf("Enter the first number :: ");
    scanf ("%d", &a);
    printf("Enter the second number :: ");
    scanf ("%d", &b);
    gcd(a,b);
    return 0;
}

void gcd(int x, int y) {
    int c;
    c = x >= y ? y : x;
    for(int i=c; i>=1; i--) {
        if(x%i ==0 && y%i == 0) {
            printf("GCD = %d\n",i);
            break;
        }
    }
}