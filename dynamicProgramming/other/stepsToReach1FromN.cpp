/*
Given a number n , you can perform any of the 
following opertions on it some number of times

1. Reduce n to n-1
2. if n % 2 == 0 then make n to n/2
3. if n % 3 == 0 then make n to n/3

Find the minimum nuber of steps to convert n to 1
*/
// State of the dp n

#include<bits/stdc++.h>
using namespace std;

// Recusion
/*
int helper(int n){
	if( n == 1) return 0;
	if( n == 2) return 1;
	if( n == 3) return 1;
	
	return 1 + min({ f(n-1) , (n%2 == 0)?f(n/2):INT_MAX , (n%3 == 0)?f(n/3):INT_MAX});
}
*/
// Recursion with Memoization
//TC = O(n)
/*
int helper(int n, vector<int>& dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 1;
    
    if (dp[n] != -1) return dp[n]; // Check memoized result
    
    dp[n] = 1 + min({helper(n - 1, dp),  (n % 2 == 0) ? helper(n / 2, dp) : INT_MAX, (n % 3 == 0) ? helper(n / 3, dp) : INT_MAX});
    
    return dp[n];
}
*/

//Tabulation
// TC = O(n)
int helper(int n, vector<int>& dp) {
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    
    for(int i = 4; i <= n; ++i) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    
    return dp[n];
}
int main() {
    int n = 34;
    vector<int> dp(n + 1, -1);
    int ans = helper(n, dp);
    cout << ans;
}

