#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]); 
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    
    if(a == b) return true;
    
    if(rank[a] > rank[b]) {
        parent[b] = a;
    } else if(rank[a] < rank[b]) {
        parent[a] = b;
    } else {
        parent[b] = a;
        rank[a]++;
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    bool cycle = false;
    while(m--) {
        int x, y;
        cin >> x >> y;
        if(Union(parent, rank, x, y)) {
            cycle = true;
            break;
        }   
    }

    if(cycle) {
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle detected\n";
    }

    return 0;
}
