//Dice combination

/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:
1+1+1
1+2
2+1
3
*/

#include<bits/stdc++.h>
using namespace std;

// recursion with memoization
/*
class Solution {
public:
	int helper(int n , vector<int>&dp){
		if(  n == 0 ) return 1;
		if(dp[n] == -1) return dp[n];
		int res = 0;
		for(int i = 1; i <= 6 ; i++){
			if(n-i < 0) break;
			else res = (res % INT_MAX + helper(n-i , dp) % INT_MAX ) % INT_MAX;
		}
		
		dp[n] = res ;
        return dp[n];
	}
	
    int diceCombination(int amount) {
        vector<int>dp(amount+1 , -1);
    	int ans = helper(amount , dp);
		else return ans;    
    }
};
*/

//Tabulation

class Solution{
public:
	int diceCombination(int amount) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		
		for(int i = 1; i <= amount; i++){
			for(int j = 1; j <= 6; j++){
				if(i - j >= 0){
					dp[i] = (dp[i] % INT_MAX + dp[i - j] % INT_MAX) % INT_MAX;
				}
			}
		} 
		return dp[amount];    
    }
};

