#include <bits/stdc++.h>
using namespace std;

vector<list<pair<int, int>>> graph;
int v;

void add_edge(int src, int dest, int weight, bool bi_direc = true) {
    graph[src].push_back(make_pair(dest, weight));
    if (bi_direc) {
        graph[dest].push_back(make_pair(src, weight));
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
    
    return 0;
}

