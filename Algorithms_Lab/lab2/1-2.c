#include<stdio.h>
#include<time.h>

int prime(int x, int y){
    if(y==1){
        return 1;
    }
    
        if(x%y == 0){
        return 0;
        }
        else
        return prime(x,y-1);
    
}
int main(){
    int n,x;
    float start = clock();
    printf("Enter the no.of inputs\n");
    scanf("%d",&n);

    while(n--){
        x = rand();
       int g = prime(x,x/2);
       if(g==1){
           printf("Prime!\n");
       }
       else{
           printf("Not Prime\n");
       }
    }
    float end = clock();
    float et = end - start;
    printf("Time : %f",et/CLOCKS_PER_SEC);
    return 0;
}