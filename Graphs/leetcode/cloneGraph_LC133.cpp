/*
133. Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    vector<Node*>nodeRegister;

    void dfs(Node* actual , Node* clone){
        for(auto neighbour : actual->neighbors){
            if(not nodeRegister[neighbour->val]){
                Node* newNode = new Node(neighbour->val);
                nodeRegister[newNode->val] = newNode;
                clone->neighbors.push_back(nodeRegister[neighbour->val]);
                dfs(neighbour, newNode);
            }else{
                clone->neighbors.push_back(nodeRegister[neighbour->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* clone = new Node(node->val);
        nodeRegister.resize(110 , nullptr);
        nodeRegister[clone->val] = clone;
        dfs(node, clone);
        return clone;
    }
};

int main(){

}