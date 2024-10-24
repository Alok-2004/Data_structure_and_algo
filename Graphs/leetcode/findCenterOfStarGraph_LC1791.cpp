/*
1791. Find Center of Star Graph
There is an undirected star graph consisting of n nodes labeled from 1 to n. 
A star graph is a graph where there is one center node and exactly n - 1 
edges that connect the center node with every other node.

You are given a 2D integer array edges 
where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. 
Return the center of the given star graph.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        if(a == c) return a;
        else if(b == c) return b;
    }
};

int main(){

}