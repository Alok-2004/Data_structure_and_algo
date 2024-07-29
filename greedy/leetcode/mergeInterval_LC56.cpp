/*
56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include<bits/stdc++.h>
using namespace std;
/*
Descending order
bool com(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> merge( vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , com);
        vector< vector<int>> res;
        int n = intervals.size();
        res.push_back(intervals[n-1]);
        for(int i = n - 2 ; i >= 0; i--){
        	vector<int>curr = intervals[i];
        	if(curr[1] >= res[res.size() - 1][0]){
        		res[res.size() - 1][0] = min(res[res.size() - 1][0] , curr[0]);
        		res[res.size() - 1][1] = max(res[res.size() - 1][1] , curr[1]);
			}else{
				res.push_back(curr);
			}
		}
		return res;
    }
};
*/

// ascending order
class Solution {
public:
    vector<vector<int>> merge( vector<vector<int>>& itrl) {
		int n = itrl.size();
		if(n == 0){
			return {};
		}
		sort(itrl.begin() , itrl.end());
		vector<vector<int>>res;
		res.push_back( itrl[0] );
		for(int i = 1; i < n ; i++){
			if( res[res.size() - 1][1] >= itrl[i][0]){
				res[res.size() - 1][0] = min( itrl[i][0] , res[res.size() - 1][0] );
				res[res.size() - 1][1] = max( itrl[i][1] , res[res.size() - 1][1] );
			}else{
				res.push_back(itrl[i]);
			}
		}
		return res;
	}
};
