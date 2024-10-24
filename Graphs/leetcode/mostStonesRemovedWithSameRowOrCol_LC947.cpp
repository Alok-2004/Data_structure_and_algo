/*
947. Most Stones Removed with Same Row or Column
On a 2D plane, we place n stones at some integer coordinate points. 
Each coordinate point may have at most one stone.
A stone can be removed if it shares either the same row or the same column 
as another stone that has not been removed.
Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, 
return the largest possible number of stones that can be removed.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	
	void dfs(int n ,unordered_set<int>&visited, vector<vector<int>>& stones){
		visited.insert(n);
		for(int i  = 0 ; i < stones.size() ; i++){
			if(not visited.count(i)){
				if(stones[n][0] = stones[i][0] or  stones[n][1] = stones[i][1]){
					dfs(i , visited , stones);
				}
			}
		}
		
		return;
	}
	
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_set<int>visited;
        int connectedComponents = 0;
        for(int i = 0 ;i < n ; i++){
        	if(!visited.count(i)){
        		dfs(i , visited , stones);
        		connectedComponents++;	
			}
		}
		
		return n - connectedComponents;
    }
};

int main(){
	
}
