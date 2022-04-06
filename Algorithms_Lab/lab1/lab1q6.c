#include<stdio.h>

int main(){
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand()%100;
        printf("%d ",a[i]);
    }
    int max = a[0];
    int secmax = a[0];
    int min = a[0];
    int secmin = a[0];
    for (int i = 0; i < 10; i++)
    {
        if(a[i]>max){
            secmax = max;
            max = a[i];
        }
        
        if(a[i]<min){
            secmin = min;
            min = a[i];
        }
    }
    printf("Second max = %d, second min = %d",secmax, secmin);
    return 0;
    
}