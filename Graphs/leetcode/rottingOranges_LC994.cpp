/*
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int f = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i  = 0; i < n ; i++){
        	for(int j = 0 ; j < m; j++){
        		if(grid[i][j] == 1) f++;
        		else if(grid[i][j] == 2){
        			q.push({i , j});
				} 
			}
		}
		
		q.push({-1,-1});
		int mins = 0;
		vector<vector<int>>dir = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
		
		while(not q.empty()){
			auto cell = q.front();
			q.pop();
			if(cell.first == -1 and cell.second == -1){
				mins++;
				if(not q.empty()){
					q.push({-1 , -1});
				}else break;
			}else{
				int i = cell.first;
				int j = cell.second;
				for(int d = 0 ; d < 4 ; d++){
					int nr = i + dir[d][0];
					int nc = j + dir[d][1];
					if(nr < 0 or nc < 0  or nr >= n or nc >= m) continue;
					if(grid[nr][nc] == 2 or grid[nr][nc] == 0) continue;
					f--;
					grid[nr][nc] = 2;
					q.push({nr , nc});
				}
			}
		}
		return (f == 0) ? mins-1 : -1;		
    }
};

int main(){
	
}
