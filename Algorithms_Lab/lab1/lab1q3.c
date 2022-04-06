#include<stdio.h>

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int a = -1;
    for (int i = 0; i < 10; i++)
    {
        if(arr[i]%2==0){
            a++;
            int temp = arr[i];
            arr[i] = arr[a];
            arr[a] = temp;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    return 0;
}