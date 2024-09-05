/*
188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. 
You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dp[1005][105][2];
	int solve(vector<int>& prices , int i , int k , bool on){
		if( i== prices.size()) return 0;
		if(dp[i][k][on] != -1) return dp[i][k][on];
		int ans = INT_MIN;
		ans = solve(prices , i+1 , k , on); //avoid
		if(on){
			ans = max(ans , prices[i] + solve(prices , i+1 , k - 1, false));
		}
		else{
			if(k > 0){
				ans = max(ans , solve(prices , i+1 , k , true) - prices[i]);
			}
		}
		return dp[i][k][on] = ans;
	}
	
    int maxProfit(int k, vector<int>& prices) {
        memset(dp , -1 , sizeof dp);
		return solve(prices, 0 , k , false);
    }
};
