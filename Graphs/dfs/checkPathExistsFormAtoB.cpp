#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void add_edge(int src, int dest, bool bi_direc = true) {
    graph[src].push_back(dest);
    if (bi_direc) {
        graph[dest].push_back(src);
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto ele : graph[i]) {
            cout << ele << " ";
        }
        cout << endl;
    }
}

bool dfs(int curr, int end) {
    if (curr == end) return true;  // Found the destination
    visited.insert(curr);  // Marking the current node as visited
    
    for (auto neighbour : graph[curr]) {
        if (!visited.count(neighbour)) {
            if (dfs(neighbour, end)) {
                return true;
            }
        }
    }
    
    return false;
}

bool anyPath(int src, int des) {
    return dfs(src, des);
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());
    
    visited.clear();
    int e;
    cin >> e;
    
    while(e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    
    display();
    
    int src, des;
    cout << "Enter source and destination: ";
    cin >> src >> des;
    
    if (anyPath(src, des)) {
        cout << "Path exists\n";
    } else {
        cout << "No path exists\n";
    }
    
    return 0;
}
