#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int* arr, int n){
     int a, j;
    for (int i = 1; i < n; i++)
    {
        a = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > a)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = a;
    }
}

int main()
{
    int *arr, n, x, choice;
    int start, end, total;
    printf("Enter Size of Array:- ");
    scanf("%d", &n);
    int loop = 1;

    while (loop)
    {
        printf("1 for Best Case\n");
        printf("2 for Average Case\n");
        printf("3 for Worst Case\n");
        printf("4 to exit\n");

        printf("\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter %d Numbers in ascending order:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            insertionSort(arr, n);

            end = clock();
            total = end - start;

            printf("Time for best case - %lf\n", (double)(total / CLOCKS_PER_SEC));
            break;

        case 2:
            printf("\nEnter %d Numbers in random order:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            insertionSort(arr, n);

            end = clock();
            total = end - start;

            printf("Time for average case - %lf\n", (double)(total / CLOCKS_PER_SEC));
            break;

        case 3:
            printf("\nEnter %d Numbers in descending order:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            insertionSort(arr, n);

            end = clock();
            total = end - start;

            printf("Time for worst case - %lf\n", (double)(total / CLOCKS_PER_SEC));
            break;

        case 4:
            loop = 0;
            break;

        default:
            printf("\n Invalid Input Try Again\n");
            break;
        }
    }

    return 0;
}