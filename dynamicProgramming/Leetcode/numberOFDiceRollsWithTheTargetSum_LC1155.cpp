/*
1155. Number of Dice Rolls With Target Sum
You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, 
so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 109 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

class Solution {
public:
    int helper(int n, int k, int t, vector<vector<ll>>& dp) {  //number of dice , faces , target
        if (t == 0 && n == 0) return 1;
        if (n == 0 || t < 0) return 0;
        if (dp[n][t] != -1) return dp[n][t];

        ll sum = 0;
        for (int v = 1; v <= k; v++) {
            sum = (sum + helper(n - 1, k, t - v, dp)) % mod;
        }
        
        return dp[n][t] = sum;
    };

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(35, vector<ll>(1005, -1));
        return helper(n, k, target, dp);    
    }
};


int main(){
	
}

