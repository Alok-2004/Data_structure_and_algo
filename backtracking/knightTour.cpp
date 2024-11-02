#include <bits/stdc++.h>
using namespace std;

bool isItSafe(vector<vector<int>>& grid, int i, int j, int n) {
    return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == -1;
}

void solve(vector<vector<int>>& grid, int i, int j, int n, int count) {
    if (count == n * n) {  // Tour complete
        for (const auto& row : grid) {
            for (int cell : row) {
                cout << setw(2) << cell << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    // Possible knight moves
    vector<pair<int, int>> moves = {
        {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };

    for (auto move : moves) {
        int new_i = i + move.first;
        int new_j = j + move.second;
        
        if (isItSafe(grid, new_i, new_j, n)) {
            grid[new_i][new_j] = count;
            solve(grid, new_i, new_j, n, count + 1);
            grid[new_i][new_j] = -1;  // Backtrack
        }
    }
}

void knightTour(int n, int start_i, int start_j) {
    vector<vector<int>> grid(n, vector<int>(n, -1));  // -1 denotes position is vacant
    grid[start_i][start_j] = 0;  // Starting position

    solve(grid, start_i, start_j, n, 1);  // Start the tour
}

int main() {
    int n = 8;
    knightTour(n, 0, 0);  // Start at (0, 0)
    return 0;
}

