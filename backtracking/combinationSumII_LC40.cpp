/*
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>>finalRes;
	
	void solve(vector<int>& cand, int target , int idx , vector<int>curr){
		if(target == 0){
			finalRes.push_back(curr);
			return;
		}
		if(idx >= cand.size()) return;
		if(target - cand[idx] >= 0){
			curr.push_back(cand[idx]);
			solve(cand , target - cand[idx] , idx+1 , curr);
			curr.pop_back();
		}
		int j = idx + 1;
		while( j  < cand.size() and cand[j] == cand[j-1]) j++;
		solve(cand , target , j , curr);
	}
	
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin() , cand.end());
        solve(cand , target , 0 , {});
        return finalRes;
    }
};

int main(){
	
}
