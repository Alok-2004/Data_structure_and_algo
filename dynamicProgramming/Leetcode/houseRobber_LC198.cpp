/*
198. House Robber
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you 
from robbing each of them is that adjacent houses have security systems connected and it will automatically contact 
the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.
*/

#include<iostream> 
using namespace std;

// Recursive
/*
class Solution {
public:
    int helper(vector<int>&nums , int i){
        if( i == nums.size() - 1) return nums[i];
        if( i == nums.size() - 2) return max(nums[i] , nums[i+1]);

        return max( nums[i] + helper( nums , i + 2) ,helper(nums , i +1));
    }

    int rob(vector<int>& nums) {
        return helper(nums, 0);
    }
};
*/

//Top Down Approach
/*
class Solution {
public:
    int helper(vector<int>&nums , int i , vector<int>&dp){
        if( i == nums.size() - 1) return nums[i];
        if( i == nums.size() - 2) return max(nums[i] , nums[i+1]);

        if(dp[i+2] == -1){
            dp[i+2] = helper( nums , i + 2);
        }
        if(dp[i+1] == -1){
            dp[i+1] = helper(nums , i +1);
        }

        return max( nums[i] + dp[i+2] , dp[i+1]);
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        return helper(nums, 0 , dp);
    }
};
*/

// Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        
        //Base case
        dp[0] = nums[0];
        if( nums.size() > 1 ) dp[1] = max(dp[0] , nums[1]);
        
        for(int i = 2 ; i < nums.size() ; i++){
            dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};