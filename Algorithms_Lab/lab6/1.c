#include<stdio.h>

int matrixMultiplication(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int min = 200000;
    int count;
    for (int m = i; m < j; m++)
    {
        count = matrixMultiplication(p, i, m) + matrixMultiplication(p, m + 1, j) + p[i - 1] * p[m] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}

int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d",matrixMultiplication(arr,1,n-1));
}