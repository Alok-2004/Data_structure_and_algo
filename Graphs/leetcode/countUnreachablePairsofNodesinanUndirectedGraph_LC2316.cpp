/*
2316. Count Unreachable Pairs of Nodes in an Undirected Graph
You are given an integer n. There is an undirected graph with n nodes, 
numbered from 0 to n - 1. You are given a 2D integer array edges where 
edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from 
each other.
*/

#inlcude<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int find(vector<int> &parents, int x) {
        if (parents[x] == x)
            return x;
        return parents[x] = find(parents, parents[x]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a != b) {
            if (rank[a] > rank[b]) {
                parent[b] = a;
            } else if (rank[a] < rank[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            Union(parent, rank, edge[0], edge[1]);
        }

        vector<long long> component_sizes(n, 0);
        for (int i = 0; i < n; i++) {
            component_sizes[find(parent, i)]++;
        }

        long long total_pairs = (long long)n * (n - 1) / 2;
        long long reachable_pairs = 0;
        for (int i = 0; i < n; i++) {
            if (component_sizes[i] > 1) {
                reachable_pairs += (component_sizes[i] * (component_sizes[i] - 1)) / 2;
            }
        }

        return total_pairs - reachable_pairs;
    }
};


int main(){
	
}
