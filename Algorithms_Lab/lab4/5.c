#include<stdio.h>
int main()
{
    int num,guess;
    printf("Heyy A, enter a number:\n");
    scanf("%d",&num);
    
    while(1)
    {
    
    printf("Heyy B ,Again Guess the number ive entered!!\n");
    scanf("%d",&guess);
    if(guess<num)
    {
    printf("Try a bigger number!!\n");
    }
    else if(guess>num)
    {
    printf("Try a smaller number\n");
    }
    else if(guess==num)
    {
    printf("You guessed it right");
    break;
    }
 } 
}