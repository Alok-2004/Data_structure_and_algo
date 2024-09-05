/*
322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/
#include<bits/stdc++.h>
using namespace std;

// Recursion
/*
class Solution {
public:
	int helper(int n , vector<int>& coins){
		if(  n == 0 ) return 0;
		int res = INT_MAX;
		for(int i = 0; i < coins.size() ; i++){
			if(n >= coins[i]) res = min(res , helper(n - coins[i] , coins));
		}
		if(res == INT_MAX) return INT_MAX;
		return res + 1;
	}
	
    int coinChange(vector<int>& coins, int amount) {
    	int ans = helper(amount , coins);
		if(ans == INT_MAX) return -1;
		else return ans;    
    }
};
*/

// recursion with memoization
class Solution {
public:
	int helper(int n , vector<int>& coins , vector<int>&dp){
		if(  n == 0 ) return 0;
        if(dp[n] != -1) return dp[n];
		int res = INT_MAX;
		for(int i = 0; i < coins.size() ; i++){
			if(n >= coins[i]) {
                res = min(res , helper(n - coins[i] , coins , dp));
            }
		}
		if(res == INT_MAX) dp[n] = INT_MAX;
        else dp[n] = res + 1;
        return dp[n];
	}
	
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1 , -1);
    	int ans = helper(amount , coins , dp);
		if(ans == INT_MAX) return -1;
		else return ans;    
    }
};

int main(){
	
}
