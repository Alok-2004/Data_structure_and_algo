/*
1326. Minimum Number of Taps to Open to Water a Garden
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e., the length of the garden is n).
There are n + 1 taps located at points [0, 1, ..., n] in the garden.
Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can 
water the area [i - ranges[i], i + ranges[i]] if it was open.
Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i <= n; i++) {  // iterate over each tap
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
			int ans = INT_MAX;
            for (int j = start; j <= end; j++) {  // consider all positions covered by this tap
                ans = min(dp[j] , ans);
            }
            if(ans != INT_MAX){
            	dp[end] = min(dp[end] , ans + 1);
			}
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};

