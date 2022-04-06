#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertRand(int *arr, int n){
for (int i = 0; i < n; i++)
{arr[i] = rand() % (10);}
}
void disp(int *arr, int n){
    for (int i = 0; i < n; i++)
        {
        printf("%d", arr[i]);
        }
    printf("\n");
}

void insertionSort(int *arr, int n)
{
for (int j = 1; j < n; j++)
{
int k = arr[j];
int i = j - 1;
while (i >= 0 && arr[i] > k)
{
arr[i + 1] = arr[i];
i--;
}
arr[i + 1] = k;
}
}
void revSort(int *arr, int n)
{
for (int j = 1; j < n; j++)
{
int k = arr[j];
int i = j - 1;
while (i >= 0 && arr[i] < k)
{
arr[i + 1] = arr[i];
i--;
}

arr[i + 1] = k;
}
}
double timetaken(int *arr, int n)
{
time_t t;
t = clock();
insertionSort(arr, n);
t = clock() - t;
double time_taken = ((double)t) / CLOCKS_PER_SEC;
// in seconds
return
time_taken;
}
int main()
{
int ch, n;
int *arr = (int *)malloc(n * sizeof(int));
while (1)
{
printf(" 0: Exit\n");
printf(" 1: n Random numbers=>Array\n");
printf(" 2: Display the Array\n");
printf(" 3: Sort the Array in Ascending Order by using Insertion Sort Algorithm\n");
printf(" 4: Sort the Array in Descending Order by using any sorting algorithm\n");
printf(" 5: Time Complexity to sort ascending of random data\n");
printf(" 6: Time Complexity to sort ascending of data already sorted in ascending order\n");
printf(" 7: Time Complexity to sort ascending of data already sorted in descending order\n");
printf("Enter your choice : \n");
scanf("%d", &ch);
switch (ch)
{
case0:
free(arr);
exit(0);
break;

case1:
printf("Enter the no of elements: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int));
insertRand(arr, n);
break;
case2:
disp(arr, n);
break;

case3:
insertionSort(arr, n);
disp(arr, n);
break;

case4:
revSort(arr, n);
disp(arr, n);
break;

case5:
insertRand(arr, n);
double timeRand = timetaken(arr, n);
printf("fun() took %f seconds to execute \n", timeRand);
break;
case6:
insertRand(arr, n);
insertionSort(arr, n);
double timeSort = timetaken(arr, n);

printf("fun() took %f seconds to execute \n", timeSort);
printf("\n");
break;
case7:
insertRand(arr, n);
revSort(arr, n);
double timeRev = timetaken(arr, n);
printf("fun() took %f seconds to execute \n", timeRand);
break;
default:
printf("Invalid Choice \n");
break;
}
}
return0;
}
