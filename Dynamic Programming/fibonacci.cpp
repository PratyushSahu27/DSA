#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fib(int n, map<int, int> memo = {})
{   
    if(memo.find(n) != memo.end())
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fib(n - 1) + fib(n - 2);
    
    return memo[n];
}

int main()
{
    int n = 40;

    auto start = high_resolution_clock::now();

    cout << "nTH Fibo : " << fib(n) << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time : " << duration.count() << endl;
    return 0;
}