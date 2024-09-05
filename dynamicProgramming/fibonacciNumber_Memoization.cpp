// will be using the concept of recursion and memoization
// memoization will reduce number of calls 
//top Down

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fibo(int n , vector<int>&dp){
        if( n <= 1) return n;
        if( dp[n] != -1) return dp[n];
        dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
        return dp[n];
    }

    int fib(int n){
        vector<int>dp(n+1, -1);
        return fibo( n, dp);
    } 
};

int main(){
    int n = 3;
    Solution s;
    int ans = s.fib(11);
    cout<<ans;
}