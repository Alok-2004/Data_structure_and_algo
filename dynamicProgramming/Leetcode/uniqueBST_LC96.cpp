/*
96. Unique Binary Search Trees
Given an integer n, return the number of structurally unique BST's 
which has exactly n nodes of unique values from 1 to n.
*/

//Application of catalan number
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int>dp;
	int helper(int n){
		if(n == 1 or n == 0) return 1;
		if(n == 2) return 2;
		if(dp[n] != -1) return dp[n];
 		
		int sum = 0;
		for(int i = 1; i <= n; i++){
			// Potential root Node i(1)
			sum += helper(i-1)*helper(i+1);
		}
        return dp[n] = sum;
	}
    int numTrees(int n) {
    	dp.clear();
    	dp.resize(30 , -1);
        return helper(n);
    }
};

int main(){
	
}
