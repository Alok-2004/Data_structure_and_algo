/*
934. Shortest Bridge
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dist = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void markFirstIsland(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        queue<pair<int, int>> tempQueue;
        tempQueue.push({i, j});
        grid[i][j] = -1;
        
        while (!tempQueue.empty()) {
            auto [x, y] = tempQueue.front();
            tempQueue.pop();
            q.push({x, y});

            for (auto& d : dist) {
                int ni = x + d[0], nj = y + d[1];
                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1) {
                    grid[ni][nj] = -1;
                    tempQueue.push({ni, nj});
                }
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool found = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    markFirstIsland(i, j, grid, q); 
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                auto [x, y] = q.front();
                q.pop();

                for (auto& d : dist) {
                    int ni = x + d[0], nj = y + d[1];
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
                        if (grid[ni][nj] == 1) {
                            return steps;
                        }
                        if (grid[ni][nj] == 0) {
                            grid[ni][nj] = -1;
                            q.push({ni, nj});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

int main(){
	 
}
