#include<stdio.h>
#include<math.h>
int srqroot(int n){
    int sr = (int)sqrt(n);
    return sr;
}
int main(){
    printf("%d\n",srqroot(525));
    printf("%d\n",srqroot(29397));
    printf("%d\n",srqroot(464782));
    printf("%d\n",srqroot(2983));
    printf("%d\n",srqroot(10939));
}