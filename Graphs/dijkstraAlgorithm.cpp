//Dijkstra Algorithm

#include <bits/stdc++.h>
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

unordered_map<int, int> dijkstra(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> via(n);
    unordered_map<int, int> mp;
    
    // O(v)
    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }

    pq.push({0, src});
    mp[src] = 0;

    while (!pq.empty()) {  // O((v+E)logv)
        pp curr = pq.top();
        pq.pop();
        
        if (vis.count(curr.second)) {
            continue;
        }

        vis.insert(curr.second);
		
//		O(v+e)
        for (auto neighbour : graph[curr.second]) {
            if (!vis.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second) {
                pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second] + neighbour.second;
            }
        }
    }
    return mp;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n , list<pp>());

    while (m--) {
        int u, v, weight;
        cin >> u >> v >> weight;
        add_edge(u, v, weight);
    }

    int src;
    cin >> src;

    unordered_map<int, int> sp = dijkstra(src, n);
    int dest;
    cin >> dest;
    cout << sp[dest];
    return 0;
}

