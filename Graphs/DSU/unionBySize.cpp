#include <vector>
#include <iostream>

using namespace std;


// Time complexity of O(n) with path compresion
int find(vector<int> &parent, int x) {
    // This function returns which group/cluster x belongs to
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int> &parent, vector<int> &size, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if (a != b) {
        // Union by size: attach the smaller tree under the larger tree
        if (size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
}

int main() {
    int n, m;
    // n = number of elements, m = number of queries
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);  // Initialize size of each set to 1

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
        string str;
        cin >> str;
        if (str == "union") {
            int x, y;
            cin >> x >> y;
            Union(parent, size, x, y);
        } else if (str == "find") {
            int x;
            cin >> x;
            cout << find(parent, x) << endl;
        }
    }

    return 0;
}
