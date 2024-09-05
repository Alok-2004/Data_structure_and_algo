/*
123. Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution {
public:
    int dp[100005][10][2]; // Increase the size to handle larger input cases
    int solve(vector<int>& prices, int i, int k, bool on) {
        if (i == prices.size()) return 0;
        if (dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = solve(prices, i+1, k, on);
        if (on) {
            ans = max(ans, prices[i] + solve(prices, i+1, k-1, false));
        } else {
            if (k > 0) {
                ans = max(ans, solve(prices, i+1, k, true) - prices[i]);
            }
        }
        return dp[i][k][on] = ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return solve(prices, 0, 2, false);
    }
};

