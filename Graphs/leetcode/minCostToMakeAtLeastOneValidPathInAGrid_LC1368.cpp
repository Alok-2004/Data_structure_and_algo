/*
1368. Minimum Cost to Make at Least One Valid Path in a Grid
Given an m x n grid. Each cell of the grid has a sign pointing to the next cell 
you should visit if you are currently in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some signs on the cells of the grid that point outside 
the grid.

You will initially start at the upper left cell (0, 0). 
A valid path in the grid is a path that starts from the upper left cell (0, 0) and 
ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. 
The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. 
You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Directions: right, left, down, up
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // Initialize distances array to large values
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        deque<pair<int, int>> dq;

        // Start from the top-left corner
        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;

            // The direction from the grid cell (1 to 4)
            int dir = grid[x][y] - 1;  // Convert to 0-based index

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // Edge weight is 1 unless we follow the correct direction
                int edgewt = (i == dir) ? 0 : 1;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (dist[nx][ny] > dist[x][y] + edgewt) {
                        dist[nx][ny] = dist[x][y] + edgewt;

                        // Push with lower cost to the front and higher cost to the back
                        if (edgewt == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner
        return dist[n - 1][m - 1];
    }
};


int main(){
	
}
