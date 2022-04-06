#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int binarySearch(int* arr,int start,int end, int key){
    
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,start,mid-1,key);
    }
    else {
        return binarySearch(arr,mid+1,end,key);
    }
}


int main()
{
    int *arr, n, x, choice,key;
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
            printf("\nEnter %d Numbers such that key is mid element:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("Enter the key value to find in array : \n");
            scanf("%d",&key);
            int pos = binarySearch(arr,0, n-1,key);

            end = clock();
            total = end - start;

            printf("Position of key = %d\nTime for best case - %lf\n",pos, (double)(total / CLOCKS_PER_SEC));
            break;

        case 2:
            printf("\nEnter %d Numbers such that key is neither mid element nor at extreme position:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("Enter the key value to find in array : \n");
             scanf("%d",&key);
            pos = binarySearch(arr,0, n-1,key);

            end = clock();
            total = end - start;

            printf("Position of key = %d\nTime for average case - %lf\n",pos, (double)(total / CLOCKS_PER_SEC));
            break;

        case 3:
            printf("\nEnter %d Numbers such that key is at extreme position:- ", n);
            start = clock();
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            printf("Enter the key value to find in array : \n");
             scanf("%d",&key);
            pos = binarySearch(arr,0, n-1,key);

            end = clock();
            total = end - start;

            printf("Positon of key = %d\nTime for worst case - %lf\n",pos, (double)(total / CLOCKS_PER_SEC));
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