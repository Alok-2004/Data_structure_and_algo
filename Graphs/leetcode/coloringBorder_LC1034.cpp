/*
1034. Coloring A Border
You are given an m x n integer matrix grid, and three integers row, col, and color. 
Each value in the grid represents the color of the grid square at that location.

Two squares are called adjacent if they are next to each other in any of the 4 directions.

Two squares belong to the same connected component if they have the same color and they are adjacent.

The border of a connected component is all the squares in the connected component that are either adjacent to (at least) 
a square not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.

Return the final grid.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> borders;

    void dfs(vector<vector<int>>& grid, int row, int col, int originalColor, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited[row][col] = true;
        bool isBorder = false;
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != originalColor) {
                isBorder = true;
            } else if (!visited[newRow][newCol]) {
                dfs(grid, newRow, newCol, originalColor, visited);
            }
        }
        
        if (isBorder) {
            borders.push_back({row, col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int originalColor = grid[row][col];

        dfs(grid, row, col, originalColor, visited);

        for (auto& cell : borders) {
            grid[cell.first][cell.second] = color;
        }

        return grid;
    }
};

int main(){

}