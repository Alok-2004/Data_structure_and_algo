/*
886. Possible Bipartition
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] 
indicates that the person labeled ai does not like the person labeled bi, 
return true if it is possible to split everyone into two groups in this way.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& colors) {
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color, graph, colors)) return false;
            } else if (colors[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto& d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        vector<int> colors(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == -1 && !dfs(i, 0, graph, colors)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
    bool result = sol.possibleBipartition(n, dislikes);
    return result ? 0 : 1;
}


