#include<stdio.h>
#include<math.h>

int main(){
int n;
scanf("%d",&n);
int arr[n];
for (int i = 0; i < n; i++)
{
    // int element = rand();
    // arr[i] = element;
    int element;
    scanf("%d", &element);
    arr[i] = element;
}

int small = arr[0], large = 0;
for(int i = 0; i < n-1; i++){
    if(arr[i]<=arr[i+1]){
        small = fmin(small,arr[i]);
        large = fmax(large,arr[i+1]);
    }
    else{
        small = fmin(small,arr[i+1]);
        large = fmax(large, arr[i]);
    }
}
printf("max = %d, min = %d",large,small);
return 0;
}
