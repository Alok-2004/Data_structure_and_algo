/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
    void dfs(int row , int col , vector<vector<char>>&grid){
        if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size()) return;
        if ( grid[row][col] !=  '1') return;
        grid[row][col] = -1;
        dfs(row+1 , col , grid);
        dfs(row-1 , col , grid);
        dfs(row , col+1 , grid);
        dfs(row , col-1 , grid);
    }
*/
    void bfs(int row, int col, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = -1;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                q.push({r - 1, c});
                grid[r - 1][c] = -1;
            }
            if (r + 1 < grid.size() && grid[r + 1][c] == '1') {
                q.push({r + 1, c});
                grid[r + 1][c] = -1;
            }
            if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                q.push({r, c - 1});
                grid[r][c - 1] = -1;
            }
            if (c + 1 < grid[0].size() && grid[r][c + 1] == '1') {
                q.push({r, c + 1});
                grid[r][c + 1] = -1;
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size(); i++){
                if (grid[i][j] ==  '1'){
                    res++;
                    bfs(i,j,grid);
                }
            }
        }

        return res;
    }
};

int main(){

}