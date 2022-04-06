#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    
    printf("Enter a sentence");
    fgets(s, sizeof(s), stdin);
     int space = 0;
     for (int i = 0; s[i] != NULL; i++)
     {
         if (s[i]==' ')
         {
             space++;
         }
         
     }
     int noOfWords = space+1;
     int noOfLetters = strlen(s) - space - 1;
     printf("Average number of letters in a word : %d", noOfLetters/noOfWords);
     return 0;
}