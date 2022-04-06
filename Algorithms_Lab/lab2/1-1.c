#include<stdio.h>
#include<time.h>
int main(){
    int n, x,i, count;

    float start = clock();
    printf("Enter the number of inputs : ");
    scanf("%d",&n);
    
    while(n--){
        count = 0;
        // printf("Enter the number : ");
        // scanf("%d",&x);

        x = rand();
        for (i = 2; i < x/2; i++)
        {
            if (x%i == 0)
            {
                count++;
                break;
            }
            
        }
        if(count == 0){
            printf("The number is prime\n");
        }
        else
        printf("The number is not prime\n");
        
    }
    float end = clock();
    float et = end - start;
    printf("Time : %f",et/CLOCKS_PER_SEC);
    return 0;
}