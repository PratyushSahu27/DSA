#include<stdio.h>
#include<conio.h>
int main(){
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand()%100;
        printf("%d ",a[i]);
        
    }
    printf("\n");
    int temp = 0;

    for (int i = 0; i < 10; i = i+2)
    {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
    
}