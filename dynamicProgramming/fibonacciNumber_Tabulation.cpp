// Tabulation 
// Iterative DP / Bottom up approach

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int fib(int n){
        if( n <=  1) return n;
        int dp[n + 1];
        for(int i = 0; i <= n; i++){
            if( i <= 1) dp[i] = i;
            else dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    } 
};

int main(){
    int n = 3;
    Solution s;
    int ans = s.fib(6);
    cout<<ans;
}