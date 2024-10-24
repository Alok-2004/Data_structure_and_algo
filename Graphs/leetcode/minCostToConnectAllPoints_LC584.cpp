/*
1584. Min Cost to Connect All Points
You are given an array points representing integer coordinates of some 
points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan 
distance between them: |xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected 
if there is exactly one simple path between any two points.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Edge {
        public:
        int p1, p2, length;
        Edge(int len, int a, int b) : p1(a), p2(b), length(len) {};
        bool operator> (const Edge &e) const {
            return length > e.length;
        }
    };

    unordered_map <int, pair<int, int>> point;
    vector<Edge> edges;
    vector<int> parent;

    int root (int node) {
        while (parent[node] != node) node = parent[node];
        return node;
    }

    bool dsu (Edge e) {
        int p1 = e.p1, p2 = e.p2;
        int root1 = root(p1), root2 = root(p2);
        if (root1 == root2) return false;
        parent[root2] = root1;
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int i=1, n=points.size();
        parent.resize(n+1);

        for (vector<int> &v: points) {
            parent[i] = i;
            point[i++] = {v[0], v[1]};
        }

        priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

        for (int a=1; a<=n; a++) {
            for (int b=a+1; b<=n; b++) {
                pair<int, int> p1 = point[a], p2 = point[b];
                int len = abs(p1.first - p2.first) + abs(p1.second - p2.second);
                edges.push(Edge(len, a, b));
            }
        }

        int ans = 0, req = n-1;
        while (!edges.empty()) {
            Edge e = edges.top();
            edges.pop();
            if (dsu(e)) {
                ans += e.length;
                req--;
                if (req==0) break;
            }
        }
        return ans;
    }
};
int main(){
	
}
