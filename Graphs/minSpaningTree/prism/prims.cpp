#include<bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;

vector<list<pair<int, int>>> graph;

void add_edge(int u, int v, int weight, bool bidir = true) {
    graph[u].push_back({v, weight});
    if (bidir) {
        graph[v].push_back({u, weight});
    }
}

ll prisms(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> par(n, -1);
    vector<int> key(n, INT_MAX);

    key[src] = 0;
    pq.push({0, src});
    ll mst_weight = 0;
    int total_count = 0;
    while (!pq.empty() and total_count < n) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (vis.find(u) != vis.end()) continue;
        vis.insert(u);
        total_count++;

        mst_weight += weight;

        for (auto neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (vis.find(v) == vis.end() && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                par[v] = u;
            }
        }
    }

    return mst_weight;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);

    while (m--) {
        int u, v, weight;
        cin >> u >> v >> weight;
        add_edge(u, v, weight);
    }

    int src;
    cin >> src;

    ll mst_weight = prisms(src, n+1);
    cout << "Total weight of MST: " << mst_weight << endl;

    return 0;
}
