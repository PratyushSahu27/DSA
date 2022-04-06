#include<stdio.h>
#include<stdlib.h>

int sqrtn(int n){
    int start = 0, end = n;
	int mid;
	int ans;
	while (start <= end) 
    {
		mid = (start + end) / 2;
		if (mid * mid == n) 
        {
			ans = mid;
			break;
		}
		if (mid * mid < n)
        {
			ans = start;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
    return ans;
}

int main(){
    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    int ans = sqrtn(n);
    printf("Squareroot: %d",ans);
    return 0;
}