#include<stdio.h>
#include<math.h>
#include<malloc.h>
int main(){
    
    int arr[16] = {1,2,1,3,3,4,3,5,6,7,6,8,9,9,3,3};
    int* a = (int*)malloc(100*sizeof(int));
    for (int i = 0; i < 100; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < 16; i++)
    {
        a[arr[i]] += 1;
    }
    int repeat =0;
    int maxrepeat = a[0];
    for (int i = 0; i < 100; i++)
    {
        if(a[i]>1)
        repeat++;
        maxrepeat = fmax(maxrepeat,a[i]);

    }
    printf("repeats = %d, max repeat = %d",repeat,maxrepeat);
    return 0;
    
    
}