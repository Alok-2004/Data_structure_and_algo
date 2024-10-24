/*
417. Pacific Atlantic Water Flow
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, 
and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. 
You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's 
height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{1, 0},{-1, 0},{0, -1},{0, 1}};
    int rows;
    int col;
    vector<vector<int>>h;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        col = heights[0].size();
        h = heights;
        queue<pair<int, int>>pac;
        queue<pair<int, int>>atlan;

        // Steps for multi-source BFS
        for(int i = 0; i < rows; i++) {
            pac.push({i, 0});
            atlan.push({i, col-1});   
        }

        for(int j = 0; j < col; j++) {
            pac.push({0, j});
            atlan.push({rows - 1, j});   
        }

        vector<vector<bool>> pacific = bfs(pac);
        vector<vector<bool>> atlantic = bfs(atlan);

        vector<vector<int>> result;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }

    vector<vector<bool>> bfs(queue<pair<int, int>>& q) {
        vector<vector<bool>> visited(rows, vector<bool>(col, false));
        while(!q.empty()) {
            auto cell = q.front();
            q.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;

            for(int d = 0; d < 4; d++) {
                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];
                if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= col) continue;

                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol] < h[i][j]) continue;

                q.push({newRow, newCol});
            }
        }
        return visited;
    }
};

int main(){
    
}