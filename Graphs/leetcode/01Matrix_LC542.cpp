/*
542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>res( mat.size() , vector<int>(mat[0].size() , INT_MAX));
        queue<pair<int, int>>q;
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(mat[i][j] == 0 and res[i][j] == INT_MAX){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }

        q.push({-1,-1});

        vector<vector<int>>dis = {{1 , 0}, {-1 , 0}, {0 , 1}, {0 , -1}};
        while( not q.empty()){
            auto cell = q.front();
            q.pop();
            for(int d = 0 ; d < 4 ; d++){
                int i = cell.first + dis[d][0];
                int j = cell.second + dis[d][1];
                if(i < 0 or j < 0 or i >= mat.size() or j >= mat[0].size() or res[i][j] != INT_MAX) continue;
                else{
                    res[i][j] = res[cell.first][cell.second]+1;
                    q.push({i,j});
                }
            }
        }
        return res;     
    }
};

int main(){
	
}
