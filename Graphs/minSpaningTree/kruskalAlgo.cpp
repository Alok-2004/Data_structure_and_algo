//Kruskal Algorithm
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
    int src, des, weight;
};

bool cmp(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int find(int x, vector<int>& parents) {
    if (parents[x] == x) 
        return x;
    return parents[x] = find(parents[x], parents); // Path compression
}

void unionSets(vector<int>& parents, vector<int>& rank, int a, int b) {
    a = find(a, parents);
    b = find(b, parents);
    if (a == b) 
        return;
    
    if (rank[a] >= rank[b]) {
        parents[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    } else {
        parents[a] = b;
    }
}

ll kruskal(vector<Edge>& input, int n, int e) {
    sort(input.begin(), input.end(), cmp); // Sort edges by weight
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 1);
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    ll totalWeight = 0;
    int edgeCount = 0;
    
    for (int i = 0; i < input.size() && edgeCount < n - 1; i++) {
        Edge curr = input[i];
        int srcParent = find(curr.src, parent);
        int desParent = find(curr.des, parent);
        
        if (srcParent != desParent) {
            totalWeight += curr.weight;
            edgeCount++;
            unionSets(parent, rank, srcParent, desParent);
        }
    }
    
    return totalWeight;
}

int main() {
    int n, e; // n is number of vertices, e is number of edges
    cin >> n >> e;

    vector<Edge> input(e);
    
    for (int i = 0; i < e; i++) {
        cin >> input[i].src >> input[i].des >> input[i].weight;
    }

    cout << "Minimum Spanning Tree weight: " << kruskal(input, n, e) << endl;
    return 0;
}

