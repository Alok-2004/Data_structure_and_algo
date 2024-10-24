/*
207. Course Schedule
There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to 
first take course 1.
Return true if you can finish all courses. Otherwise, return false
*/

#include<bits/stdc++.h>
using namespace std;
// TLE
/*
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_set<int>visited;
        queue<int>q;
        vector<int>inDegree(n, 0);
        for(auto x : pre){
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
            for(auto x : pre){
                if(x[1] == node){
                    if(not visited.count(x[0])){
                        inDegree[x[0]]--;
                        if(inDegree[x[0]] == 0){
                            visited.insert(x[0]);
                            q.push(x[0]);
                        }
                    }
                }
                
            }
        }
        return n == visited.size();
    }
    
};
*/
// This will Work because we have formed Adjacency list
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<list<int> >graph(n);
        unordered_set<int>visited;
        queue<int>q;
        vector<int>inDegree(n, 0);
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
        return n == visited.size();
    }
    
};
int main(){
	
}
