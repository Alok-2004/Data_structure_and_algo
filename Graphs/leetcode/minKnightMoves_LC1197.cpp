/*
1197. Minimum Knight Moves
In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].
A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, 
then one square in an orthogonal direction.
Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        queue<pair<int, int>> q;
        unordered_set<string> visited;
        q.push({0, 0});
        visited.insert("0,0");
        int steps = 0;
        x = abs(x);
        y = abs(y);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                if (cur_x == x && cur_y == y) return steps;
                for (auto [dx, dy] : moves) {
                    int new_x = cur_x + dx;
                    int new_y = cur_y + dy;
                    string pos = to_string(new_x) + "," + to_string(new_y);
                    if (new_x >= -1 && new_y >= -1 && visited.find(pos) == visited.end()) {
                        visited.insert(pos);
                        q.push({new_x, new_y});
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution sol;
    cout << sol.minKnightMoves(5, 5) << endl;
    return 0;
}

