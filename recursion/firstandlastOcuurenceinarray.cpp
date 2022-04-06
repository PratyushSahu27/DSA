#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n,int i, int key){
    

    if(i == n){
        return -1;
    }

    if(arr[i] == key){
        return i;
    }
    return firstOccurence(arr, n, i+1, key);
     
}

int lastOccurence(int arr[], int n, int key){
    int i = n-1;
    if(i == -1){
        return -1;
    }
    if (arr[i] == key){
        return i;
    }
    return lastOccurence(arr, n-1, key);
}


int main(){
    int arr[8] = {1,2,6,4,8,2,2,6};

    int i = firstOccurence(arr, 8 ,0 ,2);
    cout<<"First occurence : " <<i << endl;

    int l = lastOccurence(arr, 8 ,2);
    cout<<"last occurence : " <<l << endl;


}