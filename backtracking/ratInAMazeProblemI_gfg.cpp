/*
Rat in a Maze Problem - I
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. 
It has to reach the destination at (n - 1, n - 1). 
Find all possible paths that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents 
that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. 
In case of no path, return an empty list. 
The driver will output "-1" automatically.
*/

#nclude<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> result;

    void solve(int row, int col, string temp, vector<vector<int>> &mat, set<pair<int, int>> &visited) {
        if (row == mat.size() - 1 && col == mat[0].size() - 1) {
            result.push_back(temp);
            return;
        }
        
        vector<vector<int>> pos = {{0, 1, 'R'}, {1, 0, 'D'}, {-1, 0, 'U'}, {0, -1, 'L'}};
        
        for (int i = 0; i < 4; i++) {
            int x = row + pos[i][0];
            int y = col + pos[i][1];
            
            if (x >= 0 && y >= 0 && x < mat.size() && y < mat[0].size() && !visited.count({x, y}) && mat[x][y] == 1) {
                visited.insert({x, y});
                solve(x, y, temp + static_cast<char>(pos[i][2]), mat, visited);
                visited.erase({x, y});    
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        if (mat[0][0] == 0) return {};
        
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        solve(0, 0, "", mat, visited);
        return result;
    }
};


int main(){
	
}
