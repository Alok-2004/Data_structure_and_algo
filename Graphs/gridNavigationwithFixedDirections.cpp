/*
Given A grid of n*m size. Every Cell of the grid are marked as 'L' , 'R' , 'U'
'D'. Character on a cell denotes if you are standing at the cell, What direction 
you ca move to.

Check if we start from 0,0 can we reach n-1,m-1?
*/

/*
Constraints
Space complexity is constant

*/

// USe HAre and Tortise Approach 
// USe step counter approach

#include<bits/stdc++.h>
using namespace std;

pair<int, int> next_position(int x, int y, vector<vector<char>>& grid) {
    char direction = grid[x][y];
    if (direction == 'L') return {x, y - 1};
    if (direction == 'R') return {x, y + 1};
    if (direction == 'U') return {x - 1, y};
    if (direction == 'D') return {x + 1, y};
    return {x, y};
}

bool can_reach_end(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int step_count = 0, max_steps = n * m;
    int x = 0, y = 0;

    while (true) {
        if (x == n - 1 && y == m - 1) return true;
        if (step_count > max_steps) return false;
        tie(x, y) = next_position(x, y, grid);
        if (x < 0 || x >= n || y < 0 || y >= m) return false;
        step_count++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    if (can_reach_end(grid)) {
        cout << "Yes, can reach the end.\n";
    } else {
        cout << "No, cannot reach the end.\n";
    }

    return 0;
}

