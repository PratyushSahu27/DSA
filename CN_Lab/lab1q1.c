#include<stdio.h>

int main(){
    float x,y;
    char operator;
    printf("Enter operands : \n");
    scanf("%f%f",&x,&y);
    printf("Enter Operator : \n");
    
    scanf(" %c",&operator);
    switch(operator){
        case '+':
        printf("%f",x+y);
        break;
        case '-':
        printf("%f",x-y);
        break;
        case '*':
        printf("%f",x*y);
        break;
        case '/':
        if(y==0){
            printf("Error");
        }
        else
        printf("%f",x/y);
        break;
        default:
        printf("Wrong input\n");
    }
return 0;
}