/*
62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

#include<bits/stdc++.h>
using namespace std;

//using recursion
/*
class Solution {
public:
	int helper(int startR , int startC , int endR , int endC){
		if( startR == endR && startC == endC) return 1;
		if( startR > endR || startC > endC) return 0;
		
		int rightWays = helper(startR , startC + 1 , endR , endC);
		int downWays = helper(startR + 1, startC , endR , endC);
		return rightWays + downWays;
	}
	
    int uniquePaths(int m, int n) {
        return helper(1 , 1 , m , n);
    }
};
*/

// Using 2d array for memoize
/*
class Solution {
public:
	int helper(int startR , int startC , int endR , int endC , vector<vector<int>>&dp){
		if( startR == endR && startC == endC) return 1;
		if( startR > endR || startC > endC) return 0;
		if( dp[startR][startC] == -1 ){
			int rightWays = helper(startR , startC + 1 , endR , endC , dp);
			int downWays = helper(startR + 1, startC , endR , endC , dp);
			dp[startR][startC] = rightWays + downWays; 
		}
		return dp[startR][startC];
	}
	
    int uniquePaths(int m, int n) {
    	vector<vector<int>>dp ( m ,vector<int>(n , -1));
        return helper(0 , 0 , m-1 , n-1 , dp);
    }
};
*/

// Using tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
    	int dp[m][n];
		for(int i = 0; i < m; i++){
			for(int j = 0 ; j < n; j++){
				if( i == 0 || j == 0){
					dp[i][j] = 1;
				}
				else dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		
		return dp[m-1][n-1];    
    }
};

