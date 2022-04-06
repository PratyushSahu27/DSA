#include <stdio.h>
struct Student
{    
    int id;
    char name[100];    
    int phone;
};
int main()
{    
struct Student s[10];    
char ch;
for (int i = 0; i < 2; i++)
{        
    printf("\nEnter Student%d Information\n", i + 1);        
    printf("\nEnter Name :");        
    scanf("%[^\n]s", s[i].name);        
    printf("Enter Id :");        
    scanf("%d", &s[i].id);        
    printf("Enter Phone Number :");        
    scanf("%d", &s[i].phone);
    ch = getchar();
}
    printf("\n-------------Students Information----------------\n");    
for (int i = 0; i < 2; i++)
{        
    printf("\nStudent%d Details\n", i + 1);       
    printf("Name      : %s\n", s[i].name);        
    printf("Id        : %d\n", s[i].id);        
    printf("Phone no. : %d\n", s[i].phone);
}
return 0;
}