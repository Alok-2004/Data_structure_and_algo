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

void bfs(int src, int dest, vector<int>& dist) {
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto neighbour : graph[curr]) {
            if (!visited.count(neighbour)) {
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1;
            }
        }
    }
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());

    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    display();

    int x, y;
    cout << "Enter source and destination: ";
    cin >> x >> y;

    vector<int> dist;
    bfs(x, y, dist);

    cout << "Distances from " << x << ":\n";
    for (int i = 0; i < v; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << " : Unreachable\n";
        } else {
            cout << i << " : " << dist[i] << "\n";
        }
    }

    return 0;
}
