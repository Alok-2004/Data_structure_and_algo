/*
210. Course Schedule II
There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to 
first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<list<int> >graph(n);
        unordered_set<int>visited;
        queue<int>q;
        vector<int>inDegree(n, 0);
        vector<int>res;
        for(auto x : pre){
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }

        for(int i = 0 ; i < n; i++){
            if(inDegree[i] == 0){
                visited.insert(i);
                q.push(i);
            }
        }

        while(not q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto x : graph[node]){
                if( not visited.count(x)){
                    inDegree[x]--;
                    if(inDegree[x] == 0){
                        visited.insert(x);
                        q.push(x);
                    }
                }
            }
        }

        return n == res.size()?res:vector<int>{};
    }
};


int main(){
	
}
