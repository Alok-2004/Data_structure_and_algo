/*
130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int r = b.size();
        int c = b[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            if (b[i][0] == 'O') q.push({i, 0});
            if (b[i][c - 1] == 'O') q.push({i, c - 1});
        }

        for (int j = 1; j < c - 1; j++) {
            if (b[0][j] == 'O') q.push({0, j});
            if (b[r - 1][j] == 'O') q.push({r - 1, j});
        }

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;

            if (x < 0 || x >= r || y < 0 || y >= c || b[x][y] != 'O') continue;

            b[x][y] = 'E';
            q.push({x + 1, y});
            q.push({x - 1, y});
            q.push({x, y + 1});
            q.push({x, y - 1});
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (b[i][j] == 'O') b[i][j] = 'X';
                else if (b[i][j] == 'E') b[i][j] = 'O';
            }
        }
    }
};


int main(){
	
}


