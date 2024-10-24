// Kahn's Algorithm
// BFS

#include<bits/stdc++.h>
using namespace std;

vector<list<int> > graph;
int v;

void addEdge(int a, int b, bool bidir = true) {
    graph[a].push_back(b);
    if (bidir) {
        graph[b].push_back(a);
    }
    return;
}

void topoBFS() {
    vector<int> inDegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto neighbour : graph[i]) {
            inDegree[neighbour]++;
        }
    }

    queue<int> q;
    unordered_set<int> vis;
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            vis.insert(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (auto neighbour : graph[node]) {
            if (!vis.count(neighbour)) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    q.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
}

int main() {
    cin >> v;
    int e;
    cin >> e;
    graph.resize(v, list<int>());
    while (e--) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y, false);
    }
    
    topoBFS();
    
    return 0;
}

