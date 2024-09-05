/*
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> digits(int n){
	vector<int>res ;
	while(n > 0){
		res.push_back( n % 10 );
		n = n / 10;
	}
	return res;
}
//Recursion
/*
int helper(int n){
	if(n == 0) return 0;
	if(n <= 9 and n > 0) return 1;
	int res = INT_MAX;
	vector<int> nD = digits(n);
	
	for(int i = 0; i < nD.size() ; i++){
		if( nD[i] > 0 )  res = min(1 + helper( n - nD[i]) , res);
	}
	
	return res;
}
*/
// Recursion With Memoization
/*
int helper(int n , vector<int>&dp){
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int res = INT_MAX;
	vector<int> nD = digits(n);
	
	for(int i = 0; i < nD.size() ; i++){
		if( nD[i] > 0 )  res = min(1 + helper( n - nD[i] , dp) , res);
	}
	dp[n] = res; 
	return dp[n];
}
*/

// Tabulation

int helper(int n , vector<int>&dp){
	dp[0] = 0;
	for( int i = 1 ; i <= n and i <= 9 ; i++) dp[i] = 1;
	
	for(int i = 10 ; i <= n ; i++){
		vector<int> nD = digits(i);
		
		int res = INT_MAX;
        for (int j = 0; j < nD.size(); j++) {
            if (nD[j] > 0) {
                res = min(res, dp[i - nD[j]]);
            }
        }
		dp[i] = res + 1;	
	}
	
	return dp[n];
}

int main(){
	int n;
	cin>>n;
	vector<int>dp(n + 1 , -1);
	int res = helper(n , dp);
	cout<< res;
}
