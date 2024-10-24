#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
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

void dfs(int curr, int end, vector<int>& path) {
    if (curr == end) {
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for (auto neighbour : graph[curr]) {
        if (!visited.count(neighbour)) {
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
}

bool allPath(int src, int des) {
    vector<int> path;
    dfs(src, des, path);
    return !result.empty();
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());

    visited.clear();
    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    display();

    int src, des;
    cout << "Enter source and destination: ";
    cin >> src >> des;

    if (allPath(src, des)) {
        cout << "Path exists\n";
        for (const auto& path : result) {
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists\n";
    }

    return 0;
}
