#include<iostream>
using namespace std;

bool checkSort(int* arr, int a){
    if(a==1){
        return true;
    }
    bool restArray = checkSort(arr+1,a-1);
   return (arr[0] < arr[1] && restArray);
    
}

int main()
{
    int* arr = new int;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    bool ans = checkSort(arr, 10);
    cout << ans;
    
    return 0;
}
