#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6+5;
ll dp[N];
ll fib(int n)
{
    if(n == 1 || n == 0) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2); 
}
int main()
{
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << fib(n);
}