#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char>> grid;
vector<vector<string>> solutions;

bool canPlaceQueen(int row, int col, int n) {
    // Column check
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 'Q') { // Queen found above
            return false;
        }
    }

    // Left diagonal check
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (grid[i][j] == 'Q') { // Queen found on left diagonal
            return false;
        }
    }

    // Right diagonal check
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (grid[i][j] == 'Q') { // Queen found on right diagonal
            return false;
        }
    }

    return true;
}

void solve(int row, int n) {
    if (row == n) {
        // Store one possible solution
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string rowStr = "";
            for (int j = 0; j < n; j++) {
                rowStr += grid[i][j];
            }
            solution.push_back(rowStr);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPlaceQueen(row, col, n)) {
            grid[row][col] = 'Q';
            solve(row + 1, n);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>> nQueen(int n) {
    grid.resize(n, vector<char>(n, '.'));
    solve(0, n);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<string>> result = nQueen(n);

    cout << "All possible solutions:\n";
    for (const auto &solution : result) {
        for (const auto &row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

