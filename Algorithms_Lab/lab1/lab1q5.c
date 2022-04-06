#include<stdio.h>

int main(){
    int a[4][4] = {{1,2,3,4},{3,4,5,6},{6,7,8,9},{8,9,0,1}};
    int n;
    printf("enter the function no. = ");
    scanf("%d",&n);
    int c = 0;
    int d1 = 0;
    int rows = 4;
    int product = 1;
    switch (n)
    {
    case 1:
        
        for(int j=0;j<4;j++)
          for(int i=0;i<4;i++)
               if(a[j][i]!=0)
                     c++;
     printf("non-zeros present in Above Matrix: %d",c);
     break;

    case 2:
       for(int i=0;i<4;i++){ 
        for(int j=0;j<4;j++)
        {
            if(j>i)
            d1+=a[i][j];
        }
       }
        printf("Sum = %d",d1);
        break;

    case 3:
    
         for(int i=0; i< rows; i++)
                {
                         printf(" ");
                         printf("%d",a[i][rows - i - 1]);
                }
                break;
    case 4:
    
    for (int i = 0; i < n; i++) {
        product*=a[i][i];
        
    }
    printf("Product of diagonal elements = %d",product);
    break;
    default:
        break;
    }
    

}