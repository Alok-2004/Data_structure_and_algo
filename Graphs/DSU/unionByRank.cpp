#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// TC is O(log*n)
int find(vector<int> &parents, int x) {
    // This function returns which group/cluster x belongs to
    if (parents[x] == x) 
        return x;
    return parents[x] = find(parents[x], parents); // Path compression 
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) {
        // Union by rank
        if (rank[a] > rank[b]) {
            parent[b] = a;
        } else if (rank[a] < rank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

int main() {
    int n, m;
    // n = number of elements and m is number of queries
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, rank, x, y);   
        } else {
            int x;
            cin >> x;
            cout << find(parent, x) << endl;
        }
    }

    return 0;
}
