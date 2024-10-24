#include <bits/stdc++.h>
using namespace std;

vector<unordered_map<int, int>> graph;
int v;

void add_edge(int src, int dest, int weight, bool bi_direc = true) {
    graph[src][dest] = weight;
    if (bi_direc) {
        graph[dest][src] = weight;
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) {
            cout << "(" << ele.first << ", " << ele.second << ") ";
        }
        cout << endl;
    }
}

bool dfs(int src, int parent, unordered_set<int>& vis) {
    vis.insert(src);
    for (auto ele : graph[src]) {
        int neighbor = ele.first;
        if (vis.count(neighbor) && neighbor != parent) {
            return true;
        }
        if (!vis.count(neighbor)) {
            if (dfs(neighbor, src, vis)) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle() {
    unordered_set<int> vis;
    for (int i = 0; i < v; i++) {
        if (!vis.count(i)) {
            if (dfs(i, -1, vis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> v;
    graph.resize(v);
    
    int e;
    cin >> e;
    
    while (e--) {
        int s, d, w;
        cin >> s >> d >> w;
        add_edge(s, d, w);
    }
    
    display();
    
    if (hasCycle()) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
    
    return 0;
}
