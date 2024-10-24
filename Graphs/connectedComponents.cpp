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

void dfs(int node){
    visited.insert(node);
    for(auto neighbour : graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour);
        }
    }
}

int connectedComponents(){
    int result = 0;
    for(int i = 0; i < v ; i++){
        // Go to every Vertex
        // IF from a vertex we can initialize a dfs , we got one more CC
        if(visited.count(i) == 0){
            result++;
            dfs(i);
        }
    }
    return result;
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

    cout << "Connected Components: " << connectedComponents() << endl;

    return 0;
}
